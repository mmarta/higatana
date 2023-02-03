#include "bullet.h"

PlayerBullet playerBullets[PLAYER_BULLET_COUNT];

void PlayerBulletDraw(PlayerBullet *, u8);
void PlayerBulletHide(PlayerBullet *);

void InitPlayerBullets() {
    u8 i = PLAYER_BULLET_COUNT;
    while(i--) {
        playerBullets[i].y = SPRITE_Y_OFFSCREEN;
        playerBullets[i].x = 0;
        playerBullets[i].spriteIndex = nextAvailableSpriteIndex;
        nextAvailableSpriteIndex += 2;
        playerBullets[i].active = 0;
    }
}

void PlayerBulletFire(Color sector) {
    u8 i = PLAYER_BULLET_COUNT;
    while(i--) {
        if(!playerBullets[i].active) {
            playerBullets[i].y = PLAYER_Y << 3;
            playerBullets[i].x = (PLAYER_X + 1) << 3;
            playerBullets[i].sector = sector;
            playerBullets[i].distance = 0;
            playerBullets[i].active = 1;
            playerBullets[i].spriteActive = 1;

            PlayerBulletDraw(&playerBullets[i], 1);
            return;
        }
    }
}

void PlayerBulletUpdate(PlayerBullet *bullet) {
    u8 remap = 0;
    if(!bullet->active) return;

    switch(bullet->distance) {
        case 0:
            bullet->x += 4;
            break;
        case 1:
            bullet->x += 3;
            break;
        default:
            bullet->x += 2;
    }

    if(
        bullet->spriteActive
        && (
            currentColor != targetColor
            || currentColor != bullet->sector
        )
    ) {
        bullet->spriteActive = 0;
        PlayerBulletHide(bullet);
    } else if(
        !bullet->spriteActive
        && currentColor == targetColor
        && currentColor == bullet->sector
    ) bullet->spriteActive = 1;

    if(bullet->x >= 120 && bullet->distance == 0) {
        bullet->distance = 1;
        remap = 1;
    } else if(bullet->x >= 170 && bullet->distance == 1) {
        bullet->distance = 2;
        remap = 1;
    } else if(bullet->x >= 188) {
        PlayerBulletDeactivate(bullet);
        return;
    }

    PlayerBulletDraw(bullet, remap);
}

void PlayerBulletDraw(PlayerBullet *bullet, u8 remap) {
    if(!bullet->spriteActive) return;

    if(remap) {
        switch(bullet->distance) {
            case 0:
                MapSprite(bullet->spriteIndex, mapHigatanaBulletA);
                MapSprite(bullet->spriteIndex + 1, mapHigatanaBulletA);
                break;
            case 1:
                MapSprite(bullet->spriteIndex, mapHigatanaBulletBTop);
                MapSprite(bullet->spriteIndex + 1, mapHigatanaBulletBBottom);
                break;
            case 2:
                MapSprite(bullet->spriteIndex, mapHigatanaBulletCTop);
                MapSprite(bullet->spriteIndex + 1, mapHigatanaBulletCBottom);
                break;
        }
    }
    
    MoveSprite(
        bullet->spriteIndex, bullet->x,
        bullet->y, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE
    );
    MoveSprite(
        bullet->spriteIndex + 1, bullet->x,
        bullet->y + 8, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE
    );
}

void PlayerBulletHide(PlayerBullet *bullet) {
    MoveSprite(bullet->spriteIndex, 0, SPRITE_Y_OFFSCREEN, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE);
    MoveSprite(bullet->spriteIndex + 1, 0, SPRITE_Y_OFFSCREEN, PLAYER_BULLET_SPRITE_SIZE, PLAYER_BULLET_SPRITE_SIZE);
}

void PlayerBulletDeactivate(PlayerBullet *bullet) {
    bullet->active = 0;
    PlayerBulletHide(bullet);
}