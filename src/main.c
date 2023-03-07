#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "background.h"
//#include "bullet.h"
#include "player.h"

int main() {
    SetTileTable(tiles);
    SetSpritesTileTable(spriteTiles);
    SetSpriteVisibility(1);

    ClearVram();

    PrintU16Vertical(3, 21, 40000, 50000, 1);
    PrintVerticalRAM(2, 25, "1UP");

    PrintU16Vertical(3, 0, 20000, 50000, 1);
    PrintVerticalRAM(2, 4, "2UP");

    PrintU16Vertical(3, 10, 50000, 50000, 1);
    PrintVerticalRAM(2, 15, "HI");
    PrintVerticalRAM(29, 22, "@2023 RED BALLTOP");

    BGDrawField();
    InitPlayers();

    while(1) {
        WaitVsync(1);

        ReadInputs();

        //BGUpdate();
        
        PlayerUpdate(&players[0]);
        PlayerUpdate(&players[1]);
        PlayerUpdateBullets(&players[0]);
        PlayerUpdateBullets(&players[1]);
    }

    return 0;
}
