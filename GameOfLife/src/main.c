#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>

#include "cell.h"
#include "dynarray.h"

#define WIDTH 800
#define HEIGHT 800
#define CELL_SIZE 5

void ClearScreen(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
}

int main(void){

	srand((unsigned)time(NULL));

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

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	
	Dynarray cells;
	init_array(&cells, sizeof(Cell));
	for (int i = 0; i < WIDTH/CELL_SIZE; i++)
		for (int j = 0; j < HEIGHT/CELL_SIZE; j++){
			Cell result = create_cell(i,j, CELL_SIZE);
			array_push(&cells, &result);
		}

    Cell* cs = array_data(&cells);

    SDL_Event event;
    int running = 1;
    while(running){
        ClearScreen(renderer);

        for(size_t i = 0; i < cells.count; i++){
            draw_cell(renderer, cs[i]);
            Dynarray neighbours = cell_get_neighbours(&cells, cs[i], HEIGHT/CELL_SIZE);
            Cell* c = array_data(&neighbours);
            cs[i].next_status = cell_get_next_status(cs[i], c);
            free_array(&neighbours);
        }

        for(size_t i = 0; i < cells.count; i++){
            cell_set_status(&cs[i], cs[i].next_status);
        }
        
       while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
        SDL_RenderPresent(renderer);
    }

    free_array(&cells);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
