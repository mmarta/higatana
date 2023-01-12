#include "player.h"

Player players[PLAYER_COUNT];

void InitPlayers() {
    players[0].active = 1;
    players[0].animTime = 0;
    players[0].dirInput = 0;
    players[0].index = 0;
}

void PlayerUpdate(Player *player) {
    // Input
    if(inputs[player->index] & BTN_LEFT) {
        if(!player->dirInput) {
            BGRotate(currentColor == violet ? red : currentColor + 1, 1);
            player->dirInput = 1;
        }
    } else if(inputs[player->index] & BTN_RIGHT) {
        if(!player->dirInput) {
            BGRotate(currentColor == red ? violet : currentColor - 1, 0);
            player->dirInput = 1;
        }
    } else if(player->dirInput) player->dirInput = 0;

    switch(player->animTime) {
        case 0:
            DrawMap(PLAYER_X, PLAYER_Y, mapHigatanaA);
            break;
        case 3:
        case 9:
            DrawMap(PLAYER_X, PLAYER_Y, mapHigatanaB);
            break;
        case 6:
            DrawMap(PLAYER_X, PLAYER_Y, mapHigatanaC);
            break;
    }
    
    player->animTime++;
    if(player->animTime >= 12) player->animTime = 0;
}