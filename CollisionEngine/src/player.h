#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#define PLAYER_SIZE 48
#define PLAYER_SPEED 5

typedef struct Player{

    double pos_x, pos_y;
    double vel_x, vel_y;

} Player;

Player* create_player();
int player_render(Player*, SDL_Renderer*);
int player_update(Player*);
int player_input(Player*, const Uint8*, double);

#endif /* end of include guard: PLAYER_H */
