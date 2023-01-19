#ifndef _PLAYER_H
#define _PLAYER_H

#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "background.h"
#include "bullet.h"

#define PLAYER_COUNT 2

typedef struct {
    u8 index, active, animTime, dieTime, rotating, fireButton;
    u8 dirInput;
} Player;

extern Player players[];

void InitPlayers();
void PlayerInput(Player *);
void PlayerUpdate(Player *);

#endif