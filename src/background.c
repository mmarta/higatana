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
    currentColor = red;
    DrawMap(5, 13, mapBGSectorMap);
}

void BGUpdate() {
    if(bgRotateTime) {
        if(bgRotateTime == 24) {
            ClearArrow(currentColor);
            currentColor = targetColor;
            bgRotateTime = 0;
            ClearBGShort(bgDirLeft);
            DrawBG(currentColor);
        } else {
            DrawBGTransition();
            bgRotateTime++;
        }
    } else if(!bgStarted) DrawBG(currentColor);
}

void BGRotate(Color color, u8 dirLeft) {
    if(bgRotateTime) return;

    bgRotateTime = 1;
    targetColor = color;
    bgDirLeft = dirLeft;
    //ClearArrow(currentColor);
}

void DrawBG(Color color) {
    DrawArrow(color);

    DrawBGLong(color, 0);
    DrawBGLong(color, 1);
}

void DrawArrow(Color color) {
    switch(color) {
        case blue:
            DrawMap(7, 15, mapBGSectorArrowUpRight);
            break;
        case green:
            DrawMap(5, 15, mapBGSectorArrowRight);
            break;
        case yellow:
            DrawMap(4, 15, mapBGSectorArrowDownRight);
            break;
        case lavendar:
            DrawMap(4, 13, mapBGSectorArrowDown);
            break;
        case orange:
            DrawMap(4, 12, mapBGSectorArrowDownLeft);
            break;
        case pink:
            DrawMap(5, 12, mapBGSectorArrowLeft);
            break;
        case violet:
            DrawMap(7, 12, mapBGSectorArrowUpLeft);
            break;
        default:
            DrawMap(7, 13, mapBGSectorArrowUp);
    }
}

void ClearArrow(Color color) {
    switch(color) {
        case blue:
            Fill(7, 15, 1, 1, 0);
            break;
        case green:
            Fill(5, 15, 2, 1, 0);
            break;
        case yellow:
            Fill(4, 15, 1, 1, 0);
            break;
        case lavendar:
            Fill(4, 13, 1, 2, 0);
            break;
        case orange:
            Fill(4, 12, 1, 1, 0);
            break;
        case pink:
            Fill(5, 12, 2, 1, 0);
            break;
        case violet:
            Fill(7, 12, 1, 1, 0);
            break;
        default:
            Fill(7, 13, 1, 2, 0);
    }
}

void DrawBGTransition() {
    switch(bgRotateTime) {
        case 4:
            ClearBGLong(bgDirLeft);
            DrawBGShort(currentColor, !bgDirLeft);
            break;
        case 8:
            ClearBGLong(!bgDirLeft);
            break;
        case 12:
            ClearBGShort(!bgDirLeft);
            break;
        case 16:
            DrawBGShort(targetColor, bgDirLeft);
            break;
        case 20:
            DrawBGLong(targetColor, bgDirLeft);
            break;
    }
}

void ClearBGShort(u8 dirLeft) {
    if(dirLeft) Fill(BG_X_START - 2, 20, 4, 8, 0);
    else Fill(BG_X_START - 2, 0, 4, 8, 0);
}

void DrawBGShort(Color color, u8 dirLeft) {
    u8 x = BG_X_START - 2, y;
    const char *mapPtr;

    switch(color) {
        case blue:
            mapPtr = dirLeft ? mapBGBlueLeftShort : mapBGBlueRightShort;
            break;
        case green:
            mapPtr = dirLeft ? mapBGGreenLeftShort : mapBGGreenRightShort;
            break;
        case yellow:
            mapPtr = dirLeft ? mapBGYellowLeftShort : mapBGYellowRightShort;
            break;
        case lavendar:
            mapPtr = dirLeft ? mapBGLavendarLeftShort : mapBGLavendarRightShort;
            break;
        case orange:
            mapPtr = dirLeft ? mapBGOrangeLeftShort : mapBGOrangeRightShort;
            break;
        case pink:
            mapPtr = dirLeft ? mapBGPinkLeftShort : mapBGPinkRightShort;
            break;
        case violet:
            mapPtr = dirLeft ? mapBGVioletLeftShort : mapBGVioletRightShort;
            break;
        default:
            mapPtr = dirLeft ? mapBGRedLeftShort : mapBGRedRightShort;
    }

    if(!dirLeft) {
        y = 8;
        
        while(y) {
            y -= 2;
            DrawMap(x, y, mapPtr);
            x++;
        }
    } else {
        y = 20;
        while(y < 28) {
            DrawMap(x, y, mapPtr);
            x++;
            y += 2;
        }
    }
}

void ClearBGLong(u8 dirLeft) {
    if(dirLeft) Fill(BG_X_START, BG_LEFT_Y_START, 16, 8, 0);
    else Fill(BG_X_START, BG_RIGHT_Y_START - 7, 16, 8, 0);
}

void DrawBGLong(Color color, u8 dirLeft) {
    u8 i = 0, j = dirLeft ? BG_LEFT_Y_START : BG_RIGHT_Y_START, x = BG_X_START;
    const char *mapPtr;

    switch(color) {
        case blue:
            mapPtr = dirLeft ? mapBGBlueLeft : mapBGBlueRight;
            break;
        case green:
            mapPtr = dirLeft ? mapBGGreenLeft : mapBGGreenRight;
            break;
        case yellow:
            mapPtr = dirLeft ? mapBGYellowLeft : mapBGYellowRight;
            break;
        case lavendar:
            mapPtr = dirLeft ? mapBGLavendarLeft : mapBGLavendarRight;
            break;
        case orange:
            mapPtr = dirLeft ? mapBGOrangeLeft : mapBGOrangeRight;
            break;
        case pink:
            mapPtr = dirLeft ? mapBGPinkLeft : mapBGPinkRight;
            break;
        case violet:
            mapPtr = dirLeft ? mapBGVioletLeft : mapBGVioletRight;
            break;
        default:
            mapPtr = dirLeft ? mapBGRedLeft : mapBGRedRight;
    }

    while(x <= BG_X_END) {
        if(dirLeft) {
            DrawMap(x, j, mapPtr);
            j++;
        } else {
            DrawMap(x, j, mapPtr);
            j--;
        }
        x += 2;
    }
}