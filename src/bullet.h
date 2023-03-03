#ifndef _BULLET_H
#define _BULLET_H

#include "defines.h"
#include "graphics.h"
#include "gamesys.h"

typedef struct {
    u8 active, distance, spriteIndex, playerIndex;
    struct SpriteStruct *sprite;
} PlayerBullet;

void InitPlayerBullet(PlayerBullet *, u8);
void PlayerBulletFire(PlayerBullet *, u8, u8);
void PlayerBulletUpdate(PlayerBullet *);
void PlayerBulletDeactivate(PlayerBullet *);

#endif