#include "defines.h"
#include "graphics.h"

int main() {
    u8 i = 0;
    SetTileTable(tiles);

    ClearVram();

    PrintU16Vertical(30, 7, 52, 50000, 1);

    while(1) {
        WaitVsync(1);
        
        switch(i) {
            case 0:
                DrawMap(0, 0, mapHigatanaA);
                break;
            case 3:
            case 9:
                DrawMap(0, 0, mapHigatanaB);
                break;
            case 6:
                DrawMap(0, 0, mapHigatanaC);
                break;
        }
        
        i++;
        if(i >= 12) {
            i = 0;
        }
    }

    return 0;
}
