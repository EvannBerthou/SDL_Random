#include <SDL2/SDL.h>
#include <stdlib.h>
#include "wall.h"

Wall* create_wall(int x1, int y1, int x2, int y2){
    Wall* wall = malloc(sizeof(Wall));
    SDL_Rect rect = {
            x1,y1,
            x2,y2
    };
    wall->rect = rect;
    return wall;
}

int wall_render(Wall* wall, SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0,255,255,255);
    SDL_RenderFillRect(renderer, &wall->rect);
    return 0;
}
