#include "collision.h"

u8 SpriteCollision(
    u8 x1, u8 y1, u8 w1, u8 h1,
    u8 x2, u8 y2, u8 w2, u8 h2
) {
    if(
        x1 < w2 + x2 && x2 < w1 + x1
        && y1 < h2 + y2 && y2 < h1 + y1
    ) return 1;

    return 0;
}

void CheckCollisions() {
    u8 i, j;

    i = INVADER_COUNT;
    while(i--) {
        j = PLAYER_BULLET_COUNT;
        while(j--) {
            if(
                InvaderIsCollidable(&invaders[i]) && playerBullets[j].active
                && SpriteCollision(
                    sprites[invaders[i].spriteIndex].x, sprites[invaders[i].spriteIndex].y,
                    INVADER_SPRITE_SIZE << 3, INVADER_SPRITE_SIZE << 3,
                    sprites[playerBullets[j].spriteIndex].x, sprites[playerBullets[j].spriteIndex].y,
                    PLAYER_BULLET_SPRITE_SIZE << 3, PLAYER_BULLET_SPRITE_SIZE << 3
                )
            ) {
                PlayerBulletDeactivate(&playerBullets[j]);
                InvaderKill(&invaders[i]);
                players[playerCurrentIndex].scoreDelta += invaders[i].score;
                break;
            }
        }

        if(
            InvaderIsCollidable(&invaders[i])
            && PlayerIsCollidable(&players[playerCurrentIndex])
            && SpriteCollision(
                sprites[invaders[i].spriteIndex].x, sprites[invaders[i].spriteIndex].y,
                INVADER_SPRITE_SIZE << 3, INVADER_SPRITE_SIZE << 3,
                sprites[playerSharedSpriteIndex].x,
                sprites[playerSharedSpriteIndex].y,
                PLAYER_SPRITE_SIZE << 3, PLAYER_SPRITE_SIZE << 3
            )
        ) {
            PlayerKill(&players[playerCurrentIndex]);
            InvaderKill(&invaders[i]);
            players[playerCurrentIndex].scoreDelta += invaders[i].score;
            break;
        }
    }
}