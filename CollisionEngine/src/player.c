#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>

#define MAX_SPEED 4

Player* create_player(){
    Player* player = malloc(sizeof(Player));
    player->pos_x = 320 - PLAYER_SIZE / 2;
    player->pos_y = 240 - PLAYER_SIZE / 2;
    player->vel_x = 0;
    player->vel_y = 0;
    return player;
}

int player_render(Player* player, SDL_Renderer* renderer){

    SDL_Rect rect = {
        (int)player->pos_x,
        (int)player->pos_y,
        PLAYER_SIZE,
        PLAYER_SIZE};

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer, &rect);
    return 0;
}

int player_update(Player* player){

    if (player->vel_x > MAX_SPEED)  player->vel_x = MAX_SPEED;
    if (player->vel_x < -MAX_SPEED) player->vel_x = -MAX_SPEED;

    if (player->vel_y > MAX_SPEED)  player->vel_y = MAX_SPEED;
    if (player->vel_y < -MAX_SPEED) player->vel_y = -MAX_SPEED;

    player->pos_x += player->vel_x;
    player->pos_y += player->vel_y;

    player->vel_x = 0;
    player->vel_y = 0;
    return 0;
}

int player_input(Player* player, const Uint8* keyboard, double delta_time){
    player->vel_x = (keyboard[SDL_SCANCODE_RIGHT] - keyboard[SDL_SCANCODE_LEFT]) * PLAYER_SPEED * delta_time;
    player->vel_y = (keyboard[SDL_SCANCODE_DOWN] - keyboard[SDL_SCANCODE_UP]) * PLAYER_SPEED * delta_time;
    return 0;
}
