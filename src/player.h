#ifndef _PLAYER_H
#define _PLAYER_H

#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "bullet.h"

#define PLAYER_COUNT 2
#define BULLETS_PER_PLAYER 2

typedef struct {
    u8 index, spriteIndex, active, animTime, dieTime, fireButton;
    struct SpriteStruct *sprite;
    PlayerBullet bullets[BULLETS_PER_PLAYER];
} Player;

extern Player players[];

void InitPlayers();
void PlayerUpdate(Player *);
void PlayerUpdateBullets(Player *);

#endif