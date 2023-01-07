#include "defines.h"
#include "graphics.h"
#include "background.h"

int main() {
    u8 i = 0, j = 0;
    SetTileTable(tiles);

    ClearVram();

    PrintU16Vertical(28, 6, 40000, 50000, 1);
    PrintVerticalRAM(29, 2, "1UP");

    PrintU16Vertical(28, 27, 20000, 50000, 1);
    PrintVerticalRAM(29, 23, "2UP");

    PrintU16Vertical(28, 16, 50000, 50000, 1);
    PrintVerticalRAM(29, 12, "HI");
    PrintVerticalRAM(2, 5, "@2023 RED BALLTOP");

    while(1) {
        WaitVsync(1);

        BGUpdate();
        
        switch(i) {
            case 0:
                DrawMap(4, 13, mapHigatanaA);
                break;
            case 3:
            case 9:
                DrawMap(4, 13, mapHigatanaB);
                break;
            case 6:
                DrawMap(4, 13, mapHigatanaC);
                break;
        }
        
        i++;
        if(i >= 12) i = 0;

        j++;
        if(j >= 60) {
            j = 0;
            BGRotate(bgColor == red ? green : red, 1);
        }
    }

    return 0;
}
