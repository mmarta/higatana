#include "defines.h"
#include "system.h"
#include "graphics.h"
#include "gamesys.h"
#include "background.h"
#include "bullet.h"
#include "player.h"

int main() {
    u8 i;

    SetTileTable(tiles);
    SetSpritesTileTable(spriteTiles);
    SetSpriteVisibility(1);

    ClearVram();

    PrintU16Vertical(28, 6, 40000, 50000, 1);
    PrintVerticalRAM(29, 2, "1UP");

    PrintU16Vertical(28, 27, 20000, 50000, 1);
    PrintVerticalRAM(29, 23, "2UP");

    PrintU16Vertical(28, 16, 50000, 50000, 1);
    PrintVerticalRAM(29, 12, "HI");
    PrintVerticalRAM(2, 5, "@2023 RED BALLTOP");

    InitBG();
    InitPlayerBullets();
    InitPlayers();

    while(1) {
        WaitVsync(1);

        ReadInputs();

        BGUpdate();
        
        PlayerUpdate(&players[0]);
        i = PLAYER_BULLET_COUNT;
        while(i--) PlayerBulletUpdate(&playerBullets[i]);
    }

    return 0;
}
