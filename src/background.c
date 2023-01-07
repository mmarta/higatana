#include "background.h"

void DrawBG(Color);
void DrawBGTransition();
void DrawBGShort(Color, u8);
void DrawBGLong(Color, u8);

u8 bgRotateTime = 0, bgDirLeft = 0, bgStarted = 0;
Color bgColor = red, bgTargetColor;

void BGUpdate() {
    if(bgRotateTime) {
        if(bgRotateTime == 24) {
            bgColor = bgTargetColor;
            bgRotateTime = 0;
            if(bgDirLeft) {
                Fill(BG_X_START - 2, 0, 3, 6, 0);
                Fill(BG_X_END, BG_RIGHT_Y_START, 16, 8, 0);
            } else {
                Fill(BG_X_START - 2, 22, 3, 6, 0);
                Fill(BG_X_END, BG_LEFT_Y_START - 7, 16, 8, 0);
            }
            DrawBG(bgColor);
        } else {
            DrawBGTransition();
            bgRotateTime++;
        }
    } else if(!bgStarted) DrawBG(bgColor);
}

void BGRotate(Color color, u8 dirLeft) {
    bgRotateTime = 1;
    bgTargetColor = color;
    bgDirLeft = dirLeft;
}

void DrawBG(Color color) {
    u8 i = 0, j = BG_LEFT_Y_START, k = BG_RIGHT_Y_START, x = BG_X_START;
    const char *mapPtrLeft, *mapPtrRight;

    switch(color) {
        case green:
            mapPtrLeft = &mapBGGreenLeft;
            mapPtrRight = &mapBGGreenRight;
            break;
        default:
            mapPtrLeft = &mapBGRedLeft;
            mapPtrRight = &mapBGRedRight;
    }

    while(i++ < 8) {
        x -= 2;
        DrawMap(x, j, mapPtrLeft);
        DrawMap(x, k, mapPtrRight);
        j--;
        k++;
    }
}


void DrawBGTransition() {
    switch(bgRotateTime) {
        case 6:
            if(bgDirLeft) Fill(BG_X_END, BG_LEFT_Y_START - 7, 16, 8, 0);
            else Fill(BG_X_END, BG_RIGHT_Y_START, 16, 8, 0);
            
            DrawBGShort(bgColor, !bgDirLeft);
            break;
        case 12:
            if(bgDirLeft) Fill(BG_X_END, BG_RIGHT_Y_START, 16, 8, 0);
            else Fill(BG_X_END, BG_LEFT_Y_START - 7, 16, 8, 0);
            break;
        case 15:
            DrawBGShort(bgTargetColor, bgDirLeft);
            break;
        case 18:
            if(bgDirLeft) Fill(BG_X_START - 2, 22, 3, 6, 0);
            else Fill(BG_X_START - 2, 0, 3, 6, 0);

            DrawBGLong(bgTargetColor, bgDirLeft);
            break;
    }
}


void DrawBGShort(Color color, u8 dirLeft) {
    u8 x = BG_X_START, y;
    const char *mapPtr;

    switch(color) {
        case green:
            mapPtr = dirLeft ? &mapBGGreenLeftShort : &mapBGGreenRightShort;
            break;
        default:
            mapPtr = dirLeft ? &mapBGRedLeftShort : &mapBGRedRightShort;
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
        case green:
            mapPtr = dirLeft ? &mapBGGreenLeft : &mapBGGreenRight;
            break;
        default:
            mapPtr = dirLeft ? &mapBGRedLeft : &mapBGRedRight;
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