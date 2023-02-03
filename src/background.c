#include "background.h"

void DrawBG(Color);
void DrawBGTransition();
void DrawBGShort(Color, u8);
void DrawBGLong(Color, u8);
void DrawArrow(Color);
void ClearArrow(Color);

u8 bgRotateTime = 0, bgDirLeft = 0, bgStarted = 0;

void InitBG() {
    currentColor = red;
    DrawMap(5, 22, mapBGSectorMap);
}

void BGUpdate() {
    if(bgRotateTime) {
        if(bgRotateTime == 24) {
            ClearArrow(currentColor);
            currentColor = targetColor;
            bgRotateTime = 0;
            if(bgDirLeft) {
                Fill(BG_X_START - 2, 0, 3, 6, 0);
                Fill(BG_X_END, BG_RIGHT_Y_START, 16, 8, 0);
            } else {
                Fill(BG_X_START - 2, 22, 3, 6, 0);
                Fill(BG_X_END, BG_LEFT_Y_START - 7, 16, 8, 0);
            }
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
    u8 i = 0, j = BG_LEFT_Y_START, k = BG_RIGHT_Y_START, x = BG_X_START;
    const char *mapPtrLeft, *mapPtrRight;

    switch(color) {
        case blue:
            mapPtrLeft = mapBGBlueLeft;
            mapPtrRight = mapBGBlueRight;
            break;
        case green:
            mapPtrLeft = mapBGGreenLeft;
            mapPtrRight = mapBGGreenRight;
            break;
        case yellow:
            mapPtrLeft = mapBGYellowLeft;
            mapPtrRight = mapBGYellowRight;
            break;
        case lavendar:
            mapPtrLeft = mapBGLavendarLeft;
            mapPtrRight = mapBGLavendarRight;
            break;
        case orange:
            mapPtrLeft = mapBGOrangeLeft;
            mapPtrRight = mapBGOrangeRight;
            break;
        case pink:
            mapPtrLeft = mapBGPinkLeft;
            mapPtrRight = mapBGPinkRight;
            break;
        case violet:
            mapPtrLeft = mapBGVioletLeft;
            mapPtrRight = mapBGVioletRight;
            break;
        default:
            mapPtrLeft = mapBGRedLeft;
            mapPtrRight = mapBGRedRight;
    }

    DrawArrow(color);

    while(i++ < 8) {
        x -= 2;
        DrawMap(x, j, mapPtrLeft);
        DrawMap(x, k, mapPtrRight);
        j--;
        k++;
    }
}

void DrawArrow(Color color) {
    switch(color) {
        case blue:
            DrawMap(4, 21, mapBGSectorArrowUpRight);
            break;
        case green:
            DrawMap(5, 21, mapBGSectorArrowRight);
            break;
        case yellow:
            DrawMap(7, 21, mapBGSectorArrowDownRight);
            break;
        case lavendar:
            DrawMap(7, 22, mapBGSectorArrowDown);
            break;
        case orange:
            DrawMap(7, 24, mapBGSectorArrowDownLeft);
            break;
        case pink:
            DrawMap(5, 24, mapBGSectorArrowLeft);
            break;
        case violet:
            DrawMap(4, 24, mapBGSectorArrowUpLeft);
            break;
        default:
            DrawMap(4, 22, mapBGSectorArrowUp);
    }
}

void ClearArrow(Color color) {
    switch(color) {
        case blue:
            Fill(4, 21, 1, 1, 0);
            break;
        case green:
            Fill(5, 21, 2, 1, 0);
            break;
        case yellow:
            Fill(7, 21, 1, 1, 0);
            break;
        case lavendar:
            Fill(7, 22, 1, 2, 0);
            break;
        case orange:
            Fill(7, 24, 1, 1, 0);
            break;
        case pink:
            Fill(5, 24, 2, 1, 0);
            break;
        case violet:
            Fill(4, 24, 1, 1, 0);
            break;
        default:
            Fill(4, 22, 1, 2, 0);
    }
}

void DrawBGTransition() {
    switch(bgRotateTime) {
        case 4:
            if(bgDirLeft) Fill(BG_X_END, BG_LEFT_Y_START - 7, 16, 8, 0);
            else Fill(BG_X_END, BG_RIGHT_Y_START, 16, 8, 0);
            
            DrawBGShort(currentColor, !bgDirLeft);
            break;
        case 8:
            if(bgDirLeft) Fill(BG_X_END, BG_RIGHT_Y_START, 16, 8, 0);
            else Fill(BG_X_END, BG_LEFT_Y_START - 7, 16, 8, 0);
            break;
        case 12:
            if(bgDirLeft) Fill(BG_X_START - 2, 22, 3, 6, 0);
            else Fill(BG_X_START - 2, 0, 3, 6, 0);
            break;
        case 16:
            DrawBGShort(targetColor, bgDirLeft);
            break;
        case 20:
            if(bgDirLeft) Fill(BG_X_START - 2, 22, 3, 6, 0);
            else Fill(BG_X_START - 2, 0, 3, 6, 0);

            DrawBGLong(targetColor, bgDirLeft);
            break;
    }
}


void DrawBGShort(Color color, u8 dirLeft) {
    u8 x = BG_X_START, y;
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

    if(dirLeft) {
        y = 6;
        
        while(y) {
            y -= 2;
            DrawMap(x, y, mapPtr);
            x--;
        }
    } else {
        y = 22;
        while(y < 28) {
            DrawMap(x, y, mapPtr);
            x--;
            y += 2;
        }
    }
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

    while(i++ < 8) {
        x -= 2;
        if(dirLeft) {
            DrawMap(x, j, mapPtr);
            j--;
        } else {
            DrawMap(x, j, mapPtr);
            j++;
        }
    }
}