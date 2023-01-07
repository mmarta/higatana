#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "defines.h"

#define U32_MAX 0xffffffff

// The created tilemaps

extern const char mapBGRedLeft[];
extern const char mapBGRedRight[];
extern const char mapBGRedLeftShort[];
extern const char mapBGRedRightShort[];

extern const char mapBGGreenLeft[];
extern const char mapBGGreenRight[];
extern const char mapBGGreenLeftShort[];
extern const char mapBGGreenRightShort[];

extern const char mapHigatanaStill[];
extern const char mapHigatanaA[];
extern const char mapHigatanaB[];
extern const char mapHigatanaC[];

// The bare tiles themselves

extern const char tiles[];
extern const char spriteTiles[];

void PrintVerticalPROGMEM(u8, u8, const char *);
void PrintVerticalRAM(u8, u8, const char *);
void PrintU8Vertical(u8, u8, u8);
void PrintU16Vertical(u8, u8, u16, u16, u8);
void PrintU32Vertical(u8, u8, u32, u32);

#endif
