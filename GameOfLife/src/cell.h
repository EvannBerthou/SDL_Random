#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>
#include "dynarray.h"

#define STATUS_DEAD  0
#define STATUS_ALIVE 1

typedef struct Cell Cell;
struct Cell{

	int x;
	int y;
	int size;
	int status;
	int next_status;

    Dynarray neighbours;

};

void draw_cell(SDL_Renderer* r, Cell cell);

Cell create_cell(int x, int y, int size);
Dynarray cell_get_neighbours(Cell* cells, Cell center, int array_height, int array_width);
int cell_get_next_status(Cell cell);
void cell_set_status(Cell* cell);
void cells_set_neighbours(Dynarray cells);

#endif
