#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "background.h"
#include "player.h"
#include "invader.h"

int main() {
    u8 i = 0, j;

    SetTileTable(tiles);
    SetSpritesTileTable(spriteTiles);
    SetSpriteVisibility(1);

    ClearVram();

    PrintU16Vertical(3, 10, hiScore, 50000, 1);
    PrintVerticalRAM(2, 15, "HI");
    PrintVerticalRAM(29, 22, "@2023 RED BALLTOP");

    BGDrawField();
    InitPlayers();

    InitAllInvaders();

    while(1) {
        WaitVsync(1);

        ReadInputs();
        
        i++;
        if(i >= 20) {
            i = 0;
            InvaderInitNext();
        }
        
        PlayerStatusUpdate(&players[0]);
        PlayerStatusUpdate(&players[1]);

        PlayerUpdate(&players[0]);
        PlayerUpdate(&players[1]);
        PlayerUpdateBullets(&players[0]);
        PlayerUpdateBullets(&players[1]);

        j = INVADER_COUNT;
        while(j--) InvaderUpdate(&invaders[j]);
    }

    return 0;
}
