#include "invader.h"

Invader invaders[INVADER_COUNT];

void InvaderDeactivate(Invader *);

void InitAllInvaders() {
    u8 i = INVADER_COUNT;
    while(i--) {
        AssignNextSprite(&invaders[i].spriteIndex, INVADER_SPRITE_SIZE);
        //invaders[i].sprite = &sprites[invaders[i].spriteIndex];
        invaders[i].active = 0;
    }
}

void InvaderInitNext() {
    u8 i = INVADER_COUNT;
    while(i--) {
        if(!invaders[i].active) {
            invaders[i].distance = 2;
            invaders[i].animTime = 0;
            invaders[i].killTime = 0;
            invaders[i].score = 1;
            MapSprite(invaders[i].spriteIndex, mapInvaderAFarA);
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

    if(invader->killTime) {
        switch(invader->killTime) {
            case 1:
                MapSprite(invader->spriteIndex, mapInvaderKillA);
                break;
            case 5:
                MapSprite(invader->spriteIndex, mapInvaderKillB);
                break;
            case 9:
                MapSprite(invader->spriteIndex, mapInvaderKillC);
                break;
            case 13:
                MapSprite(invader->spriteIndex, mapInvaderKillD);
                break;
            case 17:
                InvaderDeactivate(invader);
                return;
        }
        invader->killTime++;
        return;
    }

    if(sprites[invader->spriteIndex].x >= 130 && invader->distance == 2) {
        invader->distance--;
        MapSprite(invader->spriteIndex, invader->animTime >= 4
            ? mapInvaderAMidB
            : mapInvaderAMidA
        );
    } else if(sprites[invader->spriteIndex].x >= 180 && invader->distance == 1) {
        invader->distance--;
        MapSprite(invader->spriteIndex, invader->animTime >= 4
            ? mapInvaderANearB
            : mapInvaderANearA
        );
    } else if(sprites[invader->spriteIndex].x >= PLAYER_X + 16) {
        InvaderDeactivate(invader);
        return;
    }

    invader->animTime++;
    if(invader->animTime >= 8) invader->animTime = 0;

    switch(invader->animTime) {
        case 0:
            if(invader->distance == 2) MapSprite(invader->spriteIndex, mapInvaderAFarA);
            else if(invader->distance == 1) MapSprite(invader->spriteIndex, mapInvaderAMidA);
            else MapSprite(invader->spriteIndex, mapInvaderANearA);
            break;
        case 4:
            if(invader->distance == 2) MapSprite(invader->spriteIndex, mapInvaderAFarB);
            else if(invader->distance == 1) MapSprite(invader->spriteIndex, mapInvaderAMidB);
            else MapSprite(invader->spriteIndex, mapInvaderANearB);
            break;
    }

    MoveSprite(
        invader->spriteIndex, invader->distance == 2 ? sprites[invader->spriteIndex].x + 1 : sprites[invader->spriteIndex].x + 2, 
        sprites[invader->spriteIndex].y, INVADER_SPRITE_SIZE, INVADER_SPRITE_SIZE
    );
}

void InvaderDeactivate(Invader *invader) {
    invader->active = 0;
    HideSprite(invader->spriteIndex, INVADER_SPRITE_SIZE, INVADER_SPRITE_SIZE);
}

void InvaderKill(Invader *invader) {
    invader->killTime = 1;
}

u8 InvaderIsCollidable(Invader *invader) {
    return (invader->active && !invader->killTime);
}