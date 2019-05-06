#ifndef LINE_H
#define LINE_H
#include <SDL2/SDL.h>
#include "vector.h"

typedef struct{
    Vec2 start;
    Vec2 end;
} Line;

void draw_line(SDL_Renderer* renderer, Line l);
int line_contains_point(Line l, Vec2 pt);
void lookAt_line(Line* line, Vec2 position);

#endif
