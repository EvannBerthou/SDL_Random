#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>
#include "dynarray.h"

#define STATUS_DEAD  0
#define STATUS_ALIVE 1

typedef struct Cell{

	int x;
	int y;
	int size;
	int status;
	int next_status;

} Cell;

void draw_cell(SDL_Renderer* r, Cell cell);

Cell create_cell(int x, int y, int size);
Dynarray cell_get_neighbours(Dynarray* cells, Cell center, int array_width);
int cell_get_next_status(Cell cell, Cell* cell_neighbours);
void cell_set_status(Cell* cell,int status);

#endif
