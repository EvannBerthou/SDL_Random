#include <SDL2/SDL.h>
#include "cell.h"

void draw_cell(SDL_Renderer* r, Cell cell){
	SDL_Rect rect = {
			cell.x * cell.size,
			cell.y * cell.size,
			cell.size,
			cell.size
	};
	if (cell.status == STATUS_ALIVE)
        SDL_SetRenderDrawColor(r, 150,150,150,255);
	else if (cell.status == STATUS_DEAD)
		SDL_SetRenderDrawColor(r, 0,0,0,255);
	SDL_RenderFillRect(r, &rect);
}

Cell create_cell(int x, int y, int size){
		Cell result = {x,y,size, rand() % 2, STATUS_ALIVE};
		return result;
}

Dynarray cell_get_neighbours(Dynarray* cells, Cell center, int array_width){
	Cell* cs = array_data(cells);
    Dynarray neighbours;
    init_array(&neighbours, sizeof(Cell));
	for (int i = center.x - 1; i <= center.x + 1; i++){
		for (int j = center.y - 1; j <= center.y + 1; j++){
			if (i == center.x && j == center.y) continue; //DONT ADD CENTER CELL AS A NEIGHBOURS
            int index = i * array_width + j;
            Cell c = cs[index];
            array_push(&neighbours, &c);
		}
	}
    return neighbours;
}


int cell_get_next_status(Cell cell, Cell* cell_neighbours){
    int sum = 0;
    for (size_t i = 0; i < 8; i++) sum += cell_neighbours[i].status;
    if (sum < 2) return STATUS_DEAD;
    if ((sum == 2 || sum == 3) && cell.status == STATUS_ALIVE) return STATUS_ALIVE;
    if (sum > 3 && cell.status == STATUS_ALIVE) return STATUS_DEAD;
    if (sum == 3 && cell.status == STATUS_DEAD) return STATUS_ALIVE;
    return STATUS_DEAD;
}

void cell_set_status(Cell* cell, int status){
	if (status == STATUS_ALIVE) cell->status = STATUS_ALIVE;
	if (status == STATUS_DEAD)  cell->status = STATUS_DEAD;
	return;
}
