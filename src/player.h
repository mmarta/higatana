#ifndef _PLAYER_H
#define _PLAYER_H

#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "bullet.h"

#define PLAYER_COUNT 2

typedef struct {
    u8 index, active, animTime, dieTime, fireButton, scoreDelta;
    u16 score;
    // Players SHARE a sprite index - see c file
    // Players also share the same bullets.
} Player;

extern Player players[];
extern u8 playerCurrentIndex;

void InitPlayers();
void PlayerStatusUpdate(Player *);
void PlayerUpdate(Player *);
void PlayerUpdateBullets(Player *);

#endif