#ifndef _BULLET_H
#define _BULLET_H

#include "defines.h"
#include "graphics.h"
#include "gamesys.h"

#define PLAYER_BULLET_COUNT 2

#define INVADER_BULLET_COUNT 3

typedef struct {
    u8 active, distance, spriteIndex, playerIndex;
} PlayerBullet;

extern PlayerBullet playerBullets[];

typedef struct {
    u8 active, spriteIndex;
} InvaderBullet;

extern InvaderBullet invaderBullets[];

void InitPlayerBullets();
void PlayerBulletFire(PlayerBullet *, u8, u8, u8);
void PlayerBulletUpdate(PlayerBullet *);
void PlayerBulletDeactivate(PlayerBullet *);

#endif