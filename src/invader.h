#ifndef _INVADER_H
#define _INVADER_H

#include "defines.h"
#include "graphics.h"
#include "gamesys.h"

#define INVADER_COUNT 8

typedef enum {
    invaderA
} InvaderType;

typedef struct {
    u8 x, y, active, animTime, killTime;
    InvaderType type;
} Invader;

extern Invader invaders[];

void InvaderInitNext();
void InvaderUpdate(Invader *);

#endif