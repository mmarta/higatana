#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "defines.h"

#define U32_MAX 0xffffffff
#define SPRITE_Y_OFFSCREEN 224

#define PLAYER_X 4
#define PLAYER_Y 13
#define PLAYER_W 2
#define PLAYER_H 2

#define PLAYER_BULLET_W 8
#define PLAYER_BULLET_H 16

#define PLAYER_BULLET_SPRITE_SIZE 1

// The created tilemaps

extern const char mapBGRedLeft[];
extern const char mapBGRedRight[];
extern const char mapBGRedLeftShort[];
extern const char mapBGRedRightShort[];

extern const char mapBGBlueLeft[];
extern const char mapBGBlueRight[];
extern const char mapBGBlueLeftShort[];
extern const char mapBGBlueRightShort[];

extern const char mapBGGreenLeft[];
extern const char mapBGGreenRight[];
extern const char mapBGGreenLeftShort[];
extern const char mapBGGreenRightShort[];

extern const char mapBGYellowLeft[];
extern const char mapBGYellowRight[];
extern const char mapBGYellowLeftShort[];
extern const char mapBGYellowRightShort[];

extern const char mapBGLavendarLeft[];
extern const char mapBGLavendarRight[];
extern const char mapBGLavendarLeftShort[];
extern const char mapBGLavendarRightShort[];

extern const char mapBGOrangeLeft[];
extern const char mapBGOrangeRight[];
extern const char mapBGOrangeLeftShort[];
extern const char mapBGOrangeRightShort[];

extern const char mapBGPinkLeft[];
extern const char mapBGPinkRight[];
extern const char mapBGPinkLeftShort[];
extern const char mapBGPinkRightShort[];

extern const char mapBGVioletLeft[];
extern const char mapBGVioletRight[];
extern const char mapBGVioletLeftShort[];
extern const char mapBGVioletRightShort[];

extern const char mapBGSectorMap[];

extern const char mapBGSectorArrowUp[];
extern const char mapBGSectorArrowDown[];
extern const char mapBGSectorArrowRight[];
extern const char mapBGSectorArrowLeft[];
extern const char mapBGSectorArrowUpRight[];
extern const char mapBGSectorArrowDownRight[];
extern const char mapBGSectorArrowUpLeft[];
extern const char mapBGSectorArrowDownLeft[];

extern const char mapHigatanaStill[];
extern const char mapHigatanaA[];
extern const char mapHigatanaB[];
extern const char mapHigatanaC[];

// Sprite maps

extern const char mapHigatanaBulletA[];
extern const char mapHigatanaBulletBTop[];
extern const char mapHigatanaBulletBBottom[];
extern const char mapHigatanaBulletCTop[];
extern const char mapHigatanaBulletCBottom[];

// The bare tiles themselves

extern const char tiles[];
extern const char spriteTiles[];

// Other variables

extern u8 nextAvailableSpriteIndex;

void PrintVerticalPROGMEM(u8, u8, const char *);
void PrintVerticalRAM(u8, u8, const char *);
void PrintU8Vertical(u8, u8, u8);
void PrintU16Vertical(u8, u8, u16, u16, u8);
void PrintU32Vertical(u8, u8, u32, u32);

#endif
