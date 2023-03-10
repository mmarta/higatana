#include "player.h"

Player players[PLAYER_COUNT];

void PlayerFire(Player *);

void InitPlayers() {
    u8 i = PLAYER_COUNT, j;

    while(i--) {
        players[i].animTime = 0;
        players[i].index = i;
        AssignNextSprite(&players[i].spriteIndex, PLAYER_SPRITE_SIZE);
        players[i].sprite = &sprites[players[i].spriteIndex];
        players[i].score = 0;
        players[i].scoreDelta = 0;
        MapSprite(players[i].spriteIndex, i ? mapHigatanaYellowA : mapHigatanaRedA);
        MoveSprite(
            players[i].spriteIndex,
            PLAYER_X, PLAYER_START_Y,
            PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE
        );

        if(i) {
            PrintVerticalRAM(2, 4, "2UP");
            PrintU16Vertical(3, 0, players[i].score, 50000, 1);
        } else {
            PrintVerticalRAM(2, 25, "1UP");
            PrintU16Vertical(3, 21, players[i].score, 50000, 1);
        }

        j = BULLETS_PER_PLAYER;
        while(j--) InitPlayerBullet(&players[i].bullets[j], i);
        
        players[i].active = 1;
    }
}

void PlayerStatusUpdate(Player *player) {
    if(player->scoreDelta) {
        player->score += player->scoreDelta;
        if(player->index) {
            PrintU16Vertical(3, 0, player->score, 50000, 1);
        } else {
            PrintU16Vertical(3, 21, player->score, 50000, 1);
        }
        player->scoreDelta = 0;
    }

    if(player->score > hiScore) {
        hiScore = player->score;
        PrintU16Vertical(3, 10, hiScore, 50000, 1);
    }
}

void PlayerUpdate(Player *player) {
    if(!player->active) return;
    
    // Input
    if(inputs[player->index] & BTN_LEFT) {
        if(player->sprite->y < 208)
            MoveSprite(
                player->spriteIndex,
                player->sprite->x,
                player->sprite->y + 2,
                PLAYER_SPRITE_SIZE,
                PLAYER_SPRITE_SIZE
            );
    } else if(inputs[player->index] & BTN_RIGHT) {
        if(player->sprite->y > 8)
            MoveSprite(
                player->spriteIndex,
                player->sprite->x,
                player->sprite->y - 2,
                PLAYER_SPRITE_SIZE,
                PLAYER_SPRITE_SIZE
            );
    }

    if(inputs[player->index] & BTN_A) {
        if(!player->fireButton) {
            PlayerFire(player);
            player->fireButton = 1;
        }
    } else if(player->fireButton) player->fireButton = 0;

    switch(player->animTime) {
        case 0:
            MapSprite(player->spriteIndex, player->index ? mapHigatanaYellowA : mapHigatanaRedA);
            break;
        case 3:
        case 9:
            MapSprite(player->spriteIndex, player->index ? mapHigatanaYellowB : mapHigatanaRedB);
            break;
        case 6:
            MapSprite(player->spriteIndex, player->index ? mapHigatanaYellowC : mapHigatanaRedC);
            break;
    }
    
    player->animTime++;
    if(player->animTime >= 12) player->animTime = 0;
}

void PlayerUpdateBullets(Player *player) {
    u8 i = BULLETS_PER_PLAYER;
    while(i--) PlayerBulletUpdate(&player->bullets[i]);
}

void PlayerFire(Player *player) {
    u8 i = BULLETS_PER_PLAYER;
    while(i--) {
        if(!player->bullets[i].active) {
            PlayerBulletFire(&player->bullets[i], player->sprite->x, player->sprite->y);
            return;
        }
    }
}