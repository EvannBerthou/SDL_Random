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
    Dynarray a;
    init_array(&a, sizeof(Cell));
    Cell result = {x,y,size, rand() % 2, STATUS_ALIVE, a};
    return result;
}

Dynarray cell_get_neighbours(Cell* cs, Cell center, int array_height, int array_width){

    Dynarray neighbours;
    init_array(&neighbours, sizeof(Cell*));
	for (int i = center.x - 1; i <= center.x + 1; i++){
		for (int j = center.y - 1; j <= center.y + 1; j++){
			if ((i == center.x && j == center.y)
                || i < 0  || j < 0
                || i >= array_width || j >= array_height) continue; //DONT ADD CENTER CELL AS A NEIGHBOURS
            int index = i * array_width + j;
            Cell* c = &cs[index];
            array_push(&neighbours, &c);
		}
	}
    return neighbours;
}

int cell_get_next_status(Cell cell){
    Cell** neighbours = array_data(&cell.neighbours);
    int sum = 0;
    for (size_t i = 0; i < cell.neighbours.count; i++) sum += neighbours[i]->status;
    if (sum < 2) return STATUS_DEAD;
    if ((sum == 2 || sum == 3) && cell.status == STATUS_ALIVE) return STATUS_ALIVE;
    if (sum > 3 && cell.status == STATUS_ALIVE) return STATUS_DEAD;
    if (sum == 3 && cell.status == STATUS_DEAD) return STATUS_ALIVE;
    return STATUS_DEAD;
}

void cell_set_status(Cell* cell){
	if (cell->next_status == STATUS_ALIVE) cell->status = STATUS_ALIVE;
    else if (cell->next_status == STATUS_DEAD)  cell->status = STATUS_DEAD;
}

void cells_set_neighbours(Dynarray cells){
    Cell* cs = array_data(&cells);
    for (size_t i = 0; i < cells.count; i++){
        Dynarray neighbours = cell_get_neighbours(cs, cs[i], 80,80);
        cs[i].neighbours = neighbours;
    }
}
