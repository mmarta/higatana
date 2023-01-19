#ifndef _BULLET_H
#define _BULLET_H

#include "defines.h"
#include "graphics.h"
#include "gamesys.h"

#define PLAYER_BULLET_COUNT 3

typedef struct {
    u8 x, y, active, distance, spriteIndex, spriteActive;
    Color sector;
} PlayerBullet;

extern PlayerBullet playerBullets[];

void InitPlayerBullets();
void PlayerBulletFire(Color);
void PlayerBulletUpdate(PlayerBullet *);
void PlayerBulletDeactivate(PlayerBullet *);

#endif