#include "invader.h"

Invader invaders[INVADER_COUNT];

void InvaderDeactivate(Invader *);

void InitAllInvaders() {
    u8 i = INVADER_COUNT;
    while(i--) {
        AssignNextSprite(&invaders[i].spriteIndex, INVADER_SPRITE_SIZE);
        invaders[i].sprite = &sprites[invaders[i].spriteIndex];
        invaders[i].active = 0;
    }
}

void InvaderInitNext() {
    u8 i = INVADER_COUNT;
    while(i--) {
        if(!invaders[i].active) {
            MapSprite(invaders[i].spriteIndex, mapInvaderANearA);
            MoveSprite(
                invaders[i].spriteIndex, 60, (rand() % 208) + 8,
                INVADER_SPRITE_SIZE, INVADER_SPRITE_SIZE
            );
            invaders[i].active = 1;
            return;
        }
    }
}

void InvaderUpdate(Invader *invader) {
    if(!invader->active) return;

    MoveSprite(
        invader->spriteIndex, invader->sprite->x + 2, 
        invader->sprite->y, INVADER_SPRITE_SIZE, INVADER_SPRITE_SIZE
    );

    if(invader->sprite->x >= PLAYER_X + 16) InvaderDeactivate(invader);
}

void InvaderDeactivate(Invader *invader) {
    invader->active = 0;
    HideSprite(invader->spriteIndex, INVADER_SPRITE_SIZE, INVADER_SPRITE_SIZE);
}