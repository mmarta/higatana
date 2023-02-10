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

    PrintU16Vertical(3, 21, 40000, 50000, 1);
    PrintVerticalRAM(2, 25, "1UP");

    PrintU16Vertical(3, 0, 20000, 50000, 1);
    PrintVerticalRAM(2, 4, "2UP");

    PrintU16Vertical(3, 10, 50000, 50000, 1);
    PrintVerticalRAM(2, 15, "HI");
    PrintVerticalRAM(29, 22, "@2023 RED BALLTOP");

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
