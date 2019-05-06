#include "math.h"

Vec2 vec_sum(Vec2 first, Vec2 other){
    Vec2 result = {
        first.x + other.x,
        first.y + other.y
    };
    return result;
}

void vec_add(Vec2* first, Vec2 other){
    first->x += other.x;
    first->y += other.y;
}
