#include "background.h"

void DrawBG(Color);
void DrawBGTransition();
void ClearBGShort(u8);
void DrawBGShort(Color, u8);
void ClearBGLong(u8);
void DrawBGLong(Color, u8);
void DrawArrow(Color);
void ClearArrow(Color);

u8 bgRotateTime = 0, bgDirLeft = 0, bgStarted = 0;

void InitBG() {
    // currentColor = red;
    // DrawMap(5, 13, mapBGSectorMap);
}

void BGUpdate() {
    // if(bgRotateTime) {
    //     if(bgRotateTime == 24) {
    //         ClearArrow(currentColor);
    //         currentColor = targetColor;
    //         bgRotateTime = 0;
    //         ClearBGShort(bgDirLeft);
    //         DrawBG(currentColor);
    //     } else {
    //         DrawBGTransition();
    //         bgRotateTime++;
    //     }
    // } else if(!bgStarted) DrawBG(currentColor);
}

void DrawBG(Color color) {
    DrawArrow(color);

    DrawBGLong(color, 0);
    DrawBGLong(color, 1);
}