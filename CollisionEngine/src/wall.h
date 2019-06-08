#ifndef WALL_H
#define WALL_H

#include <SDL2/SDL.h>

typedef struct Wall{
    SDL_Rect rect;
} Wall;

Wall* create_wall(int, int, int, int);
int wall_render(Wall*, SDL_Renderer*);

#endif /* end of include guard: WALL_H */
