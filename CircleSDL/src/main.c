#include <stdio.h>
#include <SDL2/SDL.h>
#include "vector.h"
#include "circle.h"

#define WIDTH 640
#define HEIGHT 480

void ClearScreen(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
}

int main(void){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Fenetre", 
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                WIDTH, HEIGHT,
                                SDL_WINDOW_SHOWN);

    if (!window){
        printf("Error while creating the window: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Vec2 pt = {WIDTH/2, HEIGHT/2};

    SDL_Event event;
    int running = 1;
    while(running){
        ClearScreen(renderer);
        draw_circle(renderer, pt, 100);
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
