#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>
#include "vector.h"
#include "line.h"
#include "raycast.h"
#include <stdlib.h>
#include <time.h>
#include "dynarray.h"
#include "circle.h"

#define WIDTH 800
#define HEIGHT 800

void create_line(int sx, int sy, int ex, int ey, Dynarray* a){
    if (pow((ex - sx), 2) + pow((ey - sy),2) < 1000)
        return;
    Vec2 start = {sx, sy};
    Vec2 end = {ex,ey};
    Line l = {start, end};
    array_push(a, &l);
}

void create_proto_line(int sx, int sy, int ex, int ey, SDL_Renderer* renderer){
    Vec2 start = {sx, sy};
    Vec2 end   = {ex, ey};
    Line l = {start,end};
    draw_line(renderer, l);
}

void delete_line(int x, int y, Dynarray* a){
    Vec2 pt = {x,y};
    Line* lines = array_data(a);

    for (size_t i = 0; i < a->count; i++) {
        if (line_contains_point(lines[i], pt)){
            array_delete_element(a, &lines[i]);
            return;
        }
    }
}

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

    Vec2 start2 = {WIDTH/2,HEIGHT/2};
    Vec2 end2   = {0,0};
    Line caster = {start2,end2};

    Dynarray a;
    init_array(&a, sizeof(Line));

    int x_down, y_down, x_up, y_up;
    x_down = y_down = x_up = y_up = 0;

    SDL_Event event;
    int running = 1;
    while(running){
        ClearScreen(renderer);

        int x,y;
        SDL_GetMouseState(&x, &y);
        
        Line* walls = array_data(&a);
        draw_line(renderer, caster);

        Vec2 mouse_position = {x,y};
        lookAt_line(&caster, mouse_position);
        Dynarray pts;
        init_array(&pts, sizeof(Vec2));
        for(size_t i = 0; i < a.count; i++){
            draw_line(renderer, walls[i]);
            Vec2 pt = raycast(caster, walls[i]);
             
            if (pt.x != 0 && pt.y != 0){
                array_push(&pts, &pt);
            }
        }
        Vec2 closest = get_closest_point(caster.start, &pts);
        if (closest.x >= 0 && closest.y >= 0){
            draw_circle(renderer, closest, 5);
        }

        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                        SDL_GetMouseState(&x_down, &y_down);

                    if (event.button.button == SDL_BUTTON_RIGHT){
                        delete_line(x,y, &a);
                    }

                    break;
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT){
                        SDL_GetMouseState(&x_up, &y_up);
                        create_line(x_down, y_down, x_up, y_up, &a);
                        x_down = y_down = x_up = y_up = 0;
                    }
                    break;
            }
        }
        
        if (x_down != 0 && y_down != 0)
            create_proto_line(x_down, y_down, x,y, renderer);

        SDL_RenderPresent(renderer);
    }
    free_array(&a);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
