#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "defines.h"

#define U32_MAX 0xffffffff
#define SPRITE_Y_OFFSCREEN 224

#define PLAYER_X 208
#define PLAYER_START_Y 108
#define PLAYER_SPRITE_SIZE 1

#define PLAYER_BULLET_W 8
#define PLAYER_BULLET_H 8

#define PLAYER_BULLET_SPRITE_SIZE 1

#define HideSprite(spriteNum, w, h) MoveSprite(spriteNum, 0, SPRITE_Y_OFFSCREEN, w, h);

// The created tilemaps

extern const char mapBGStraightRight[];
extern const char mapBGStraightLeft[];
extern const char mapBGSlightRightA[];
extern const char mapBGSlightRightB[];
extern const char mapBGSlightRightC[];
extern const char mapBGSlightRightD[];
extern const char mapBGSlightLeftA[];
extern const char mapBGSlightLeftB[];
extern const char mapBGSlightLeftC[];
extern const char mapBGSlightLeftD[];
extern const char mapBGMidRightA[];
extern const char mapBGMidRightB[];
extern const char mapBGMidLeftA[];
extern const char mapBGMidLeftB[];
extern const char mapBGHeavyRight[];
extern const char mapBGHeavyLeft[];

// Sprite maps

extern const char mapHigatanaRedStill[];
extern const char mapHigatanaRedA[];
extern const char mapHigatanaRedB[];
extern const char mapHigatanaRedC[];
extern const char mapHigatanaYellowStill[];
extern const char mapHigatanaYellowA[];
extern const char mapHigatanaYellowB[];
extern const char mapHigatanaYellowC[];

extern const char mapHigatanaRedBulletA[];
extern const char mapHigatanaRedBulletB[];
extern const char mapHigatanaRedBulletC[];
extern const char mapHigatanaYellowBulletA[];
extern const char mapHigatanaYellowBulletB[];
extern const char mapHigatanaYellowBulletC[];

// The bare tiles themselves

extern const char tiles[];
extern const char spriteTiles[];

// Other variables

extern u8 nextAvailableSpriteIndex;

void AssignNextSprite(u8 *, u8);

void PrintVerticalPROGMEM(u8, u8, const char *);
void PrintVerticalRAM(u8, u8, const char *);
void PrintU8Vertical(u8, u8, u8);
void PrintU16Vertical(u8, u8, u16, u16, u8);
void PrintU32Vertical(u8, u8, u32, u32);

#endif
