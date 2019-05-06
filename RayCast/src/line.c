#include <SDL2/SDL.h>
#include "line.h"
#include <stdio.h>
#include <math.h>

void draw_line(SDL_Renderer* renderer, Line l){
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderDrawLine(renderer,(int)l.start.x,
                                (int)l.start.y,
                                (int)l.end.x,
                                (int)l.end.y);
}

int line_contains_point(Line l, Vec2 pt){

    double vAPx = pt.x - l.start.x;
    double vAPy = pt.y - l.start.y;
    double vABx = l.end.x - l.start.x;
    double vABy = l.end.y - l.start.y;

    double distance = (
            pow((l.end.x - l.start.x), 2) + pow((l.end.y - l.start.y),2)
         );

    double ABAPproduct = vABx*vAPx + vABy*vAPy;
    double amount = ABAPproduct / distance;

    if (amount > 1) amount = 1;
    if (amount < 0) amount = 0;

    double nx = (amount * (l.end.x - l.start.x)) + l.start.x;
    double ny = (amount * (l.end.y - l.start.y)) + l.start.y;

    return (pow((pt.x - nx), 2) + pow((pt.y - ny),2)) < 20;
}

void lookAt_line(Line* line, Vec2 position){

    Vec2 p2 = {
      position.x - line->start.x,
      position.y - line->start.y
    };

    vec_normalize(&p2);
    vec_mult(&p2, 50);
    line->end.x = line->start.x + p2.x;
    line->end.y = line->start.y + p2.y;
    
}
