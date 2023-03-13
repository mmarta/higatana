#include "bullet.h"

PlayerBullet playerBullets[PLAYER_BULLET_COUNT];

void PlayerBulletHide(PlayerBullet *);

void InitPlayerBullets() {
    u8 i = PLAYER_BULLET_COUNT;
    while(i--) {
        AssignNextSprite(&playerBullets[i].spriteIndex, PLAYER_BULLET_SPRITE_SIZE);
        playerBullets[i].active = 0;
    }
}

void PlayerBulletFire(PlayerBullet *bullet, u8 x, u8 y, u8 index) {
    bullet->playerIndex = index;
    MapSprite(bullet->spriteIndex, index
        ? mapHigatanaYellowBulletA
        : mapHigatanaRedBulletA
    );
    
    MoveSprite(bullet->spriteIndex, x, y, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE);
    bullet->distance = 0;
    bullet->active = 1;
}

void PlayerBulletUpdate(PlayerBullet *bullet) {
    u8 speed;
    if(!bullet->active) return;

    switch(bullet->distance) {
        case 0:
            speed = 4;
            break;
        case 1:
            speed = 3;
            break;
        default:
            speed = 2;
    }

    if(sprites[bullet->spriteIndex].x < 180 && bullet->distance == 0) {
        bullet->distance = 1;
        MapSprite(bullet->spriteIndex, bullet->playerIndex
            ? mapHigatanaYellowBulletB
            : mapHigatanaRedBulletB
        );
    } else if(sprites[bullet->spriteIndex].x < 130 && bullet->distance == 1) {
        bullet->distance = 2;
        MapSprite(bullet->spriteIndex, bullet->playerIndex
            ? mapHigatanaYellowBulletC
            : mapHigatanaRedBulletC
        );
    } else if(sprites[bullet->spriteIndex].x < 100) {
        PlayerBulletDeactivate(bullet);
        return;
    }
    
    MoveSprite(
        bullet->spriteIndex, sprites[bullet->spriteIndex].x - speed, sprites[bullet->spriteIndex].y,
        PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE
    );
}

void PlayerBulletDeactivate(PlayerBullet *bullet) {
    bullet->active = 0;
    HideSprite(bullet->spriteIndex, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE);
}