#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "background.h"
#include "player.h"

int main() {
    SetTileTable(tiles);

    ClearVram();

    PrintU16Vertical(28, 6, 40000, 50000, 1);
    PrintVerticalRAM(29, 2, "1UP");

    PrintU16Vertical(28, 27, 20000, 50000, 1);
    PrintVerticalRAM(29, 23, "2UP");

    PrintU16Vertical(28, 16, 50000, 50000, 1);
    PrintVerticalRAM(29, 12, "HI");
    PrintVerticalRAM(2, 5, "@2023 RED BALLTOP");

    DrawMap(4, 22, mapBGSectorMap);

    InitPlayers();

    while(1) {
        WaitVsync(1);

        ReadInputs();

        BGUpdate();
        
        PlayerUpdate(&players[0]);
    }

    return 0;
}
