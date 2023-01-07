#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include "defines.h"
#include "graphics.h"

#define BG_LEFT_Y_START 11
#define BG_RIGHT_Y_START 16
#define BG_X_START 24
#define BG_X_END 8

extern Color bgColor;

void BGUpdate();
void BGRotate(Color, u8);

#endif