#ifndef _COLLISION_H
#define _COLLISION_H

#include "defines.h"
#include "bullet.h"
#include "player.h"
#include "invader.h"

void CheckCollisions();
u8 SpriteCollision(u8, u8, u8, u8, u8, u8, u8, u8);

#endif