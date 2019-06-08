#include <stdio.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "wall.h"

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

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


    Player* player = create_player();
    Wall* top = create_wall(0,0, WIDTH, 16);
    Wall* bottom = create_wall(0,HEIGHT-16, WIDTH, 16);
    Wall* left = create_wall(0,0, 16, HEIGHT);
    Wall* right = create_wall(WIDTH-16,0, WIDTH, HEIGHT);

    SDL_Event event;
    int running = 1;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    while(running){

        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        double delta_time = (double) ((NOW - LAST)*1000 
                / SDL_GetPerformanceFrequency());

        ClearScreen(renderer);
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    running = 0;
                    break;

            }
        }

        const Uint8 *keyboard = SDL_GetKeyboardState(NULL);
        player_input(player, keyboard, delta_time);

        wall_render(top, renderer);
        wall_render(bottom, renderer);
        wall_render(left, renderer);
        wall_render(right, renderer);

        player_update(player);
        player_render(player, renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
