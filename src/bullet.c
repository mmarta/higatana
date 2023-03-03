#include "bullet.h"

void PlayerBulletHide(PlayerBullet *);

void InitPlayerBullet(PlayerBullet *bullet, u8 index) {
    AssignNextSprite(&bullet->spriteIndex, PLAYER_BULLET_SPRITE_SIZE);
    bullet->sprite = &sprites[bullet->spriteIndex];
    HideSprite(bullet->spriteIndex, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE);
    bullet->playerIndex = index;
    bullet->active = 0;
}

void PlayerBulletFire(PlayerBullet *bullet, u8 x, u8 y) {
    MapSprite(bullet->spriteIndex, bullet->playerIndex
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

    if(bullet->sprite->x < 180 && bullet->distance == 0) {
        bullet->distance = 1;
        MapSprite(bullet->spriteIndex, bullet->playerIndex
            ? mapHigatanaYellowBulletB
            : mapHigatanaRedBulletB
        );
    } else if(bullet->sprite->x < 130 && bullet->distance == 1) {
        bullet->distance = 2;
        MapSprite(bullet->spriteIndex, bullet->playerIndex
            ? mapHigatanaYellowBulletC
            : mapHigatanaRedBulletC
        );
    } else if(bullet->sprite->x < 100) {
        PlayerBulletDeactivate(bullet);
        return;
    }
    
    MoveSprite(
        bullet->spriteIndex, bullet->sprite->x - speed, bullet->sprite->y,
        PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE
    );
}

void PlayerBulletDeactivate(PlayerBullet *bullet) {
    bullet->active = 0;
    HideSprite(bullet->spriteIndex, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE);
}