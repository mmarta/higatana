#include "background.h"

void BGDrawField() {
    u8 x;
    u8 y[] = {8, 18};
    Fill(BG_X_START, 0, 1, 28, 64);

    x = BG_X_START + 1;
    y[0] = 10;
    y[1] = 16;
    while(x < 28) {
        DrawMap(x, y[0], mapBGSlightRightA);
        DrawMap(x + 2, y[0], mapBGSlightRightB);
        DrawMap(x + 4, y[0], mapBGSlightRightC);
        DrawMap(x + 6, y[0], mapBGSlightRightD);
        DrawMap(x, y[1], mapBGSlightLeftA);
        DrawMap(x + 2, y[1], mapBGSlightLeftB);
        DrawMap(x + 4, y[1], mapBGSlightLeftC);
        DrawMap(x + 6, y[1], mapBGSlightLeftD);
        x += 8;
        y[0] -= 2;
        y[1] += 2;
    }

    x = BG_X_START + 1;
    y[0] = 6;
    y[1] = 20;
    while(1) {
        DrawMap(x, y[0], mapBGMidRightA);
        DrawMap(x + 2, y[0], mapBGMidRightB);
        DrawMap(x, y[1], mapBGMidLeftA);
        DrawMap(x + 2, y[1], mapBGMidLeftB);
        x += 4;
        if(!y[0]) break;
        
        y[0] -= 2;
        y[1] += 2;
    }

    x = BG_X_START + 1;
    y[0] = 2;
    y[1] = 24;
    while(1) {
        DrawMap(x, y[0], mapBGHeavyRight);
        DrawMap(x, y[1], mapBGHeavyLeft);
        x += 2;
        if(!y[0]) break;
        
        y[0] -= 2;
        y[1] += 2;
    }
}