#include "player.h"

Player players[PLAYER_COUNT];

u8 playerCurrentIndex = 0;
u8 playerSharedSpriteIndex, playerSharedSpriteAssigned = 0;

void PlayerFire(Player *);

void InitPlayers() {
    u8 i = PLAYER_COUNT - 1;

    while(i--) {
        players[i].animTime = 0;
        players[i].index = i;

        if(!playerSharedSpriteAssigned) {
            AssignNextSprite(&playerSharedSpriteIndex, PLAYER_SPRITE_SIZE);
            playerSharedSpriteAssigned = 1;
        }
        
        players[i].score = 0;
        players[i].scoreDelta = 0;
        MapSprite(playerSharedSpriteIndex, i ? mapHigatanaYellowA : mapHigatanaRedA);
        MoveSprite(
            playerSharedSpriteIndex,
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
        if(sprites[playerSharedSpriteIndex].y < 208)
            MoveSprite(
                playerSharedSpriteIndex,
                sprites[playerSharedSpriteIndex].x,
                sprites[playerSharedSpriteIndex].y + 2,
                PLAYER_SPRITE_SIZE,
                PLAYER_SPRITE_SIZE
            );
    } else if(inputs[player->index] & BTN_RIGHT) {
        if(sprites[playerSharedSpriteIndex].y > 8)
            MoveSprite(
                playerSharedSpriteIndex,
                sprites[playerSharedSpriteIndex].x,
                sprites[playerSharedSpriteIndex].y - 2,
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
            MapSprite(playerSharedSpriteIndex, player->index ? mapHigatanaYellowA : mapHigatanaRedA);
            break;
        case 3:
        case 9:
            MapSprite(playerSharedSpriteIndex, player->index ? mapHigatanaYellowB : mapHigatanaRedB);
            break;
        case 6:
            MapSprite(playerSharedSpriteIndex, player->index ? mapHigatanaYellowC : mapHigatanaRedC);
            break;
    }
    
    player->animTime++;
    if(player->animTime >= 12) player->animTime = 0;
}

void PlayerFire(Player *player) {
    u8 i = PLAYER_BULLET_COUNT;
    while(i--) {
        if(!playerBullets[i].active) {
            PlayerBulletFire(
                &playerBullets[i], sprites[playerSharedSpriteIndex].x,
                sprites[playerSharedSpriteIndex].y, player->index
            );
            return;
        }
    }
}