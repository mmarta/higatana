#ifndef _PLAYER_H
#define _PLAYER_H

#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "background.h"

#define PLAYER_COUNT 2

#define PLAYER_X 4
#define PLAYER_Y 13

typedef struct {
    u8 index, active, animTime, dieTime, rotating;
    u8 dirInput;
} Player;

extern Player players[];

void InitPlayers();
void PlayerInput(Player *);
void PlayerUpdate(Player *);

#endif