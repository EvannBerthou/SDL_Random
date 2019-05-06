#include "circle.h"
#include "vector.h"
#include <math.h>
#include <SDL2/SDL.h>

void draw_circle(SDL_Renderer* renderer, Vec2 pt, int radius){
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    for (double r = radius; r > 0; r -= 0.5){
        for (double i = 0; i < 3.14 * 2; i += 0.01){
            int x = (int)(cos(i) * r + pt.x);
            int y = (int)(sin(i) * r + pt.y);
            SDL_RenderDrawPoint(renderer, x,y);
        }
    }
}
