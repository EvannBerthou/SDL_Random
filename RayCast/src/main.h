#ifndef MAIN_H
#define MAIN_H

#include "dynarray.h"
#include <SDL2/SDL.h>
void create_line(int sx, int sy, int ex, int ey, Dynarray* a);
void create_proto_line(int sx, int sy, int ex, int ey, SDL_Renderer* renderer);
void delete_line(int x,int y, Dynarray* a);
void ClearScreen(SDL_Renderer* renderer);

#endif
