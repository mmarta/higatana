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

    i = PLAYER_BULLET_COUNT;
    while(i--) {
        j = INVADER_COUNT;
        while(j--) {
            if(
                InvaderIsCollidable(&invaders[j]) && playerBullets[i].active
                && SpriteCollision(
                    sprites[invaders[j].spriteIndex].x, sprites[invaders[j].spriteIndex].y,
                    INVADER_SPRITE_SIZE << 3, INVADER_SPRITE_SIZE << 3,
                    sprites[playerBullets[i].spriteIndex].x, sprites[playerBullets[i].spriteIndex].y,
                    PLAYER_BULLET_SPRITE_SIZE << 3, PLAYER_BULLET_SPRITE_SIZE << 3
                )
            ) {
                PlayerBulletDeactivate(&playerBullets[i]);
                InvaderKill(&invaders[j]);
                players[playerCurrentIndex].scoreDelta += invaders[j].score;
            }
        }
    }
}