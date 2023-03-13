#ifndef _INVADER_H
#define _INVADER_H

#include "defines.h"
#include "graphics.h"
#include "gamesys.h"

#define INVADER_COUNT 6

typedef enum {
    invaderA
} InvaderType;

typedef struct {
    u8 spriteIndex, active, animTime, killTime, score, distance;
    //struct SpriteStruct *sprite;
    InvaderType type;
} Invader;

extern Invader invaders[];

void InitAllInvaders();
void InvaderInitNext();
void InvaderUpdate(Invader *);
void InvaderKill(Invader *);
u8 InvaderIsCollidable(Invader *);

#endif