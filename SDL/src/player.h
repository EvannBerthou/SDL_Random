#ifndef PLAYER_H
#define PLAYER_H

#include "math.h"

typedef struct{
    Vec2 position;
    Vec2 scale;
} Player;

Player initPlayer(Vec2 position, Vec2 scale);
void player_draw(SDL_Renderer* renderer, Player* player);

#endif
