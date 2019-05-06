#include "vector.h"
#include <stdio.h>
#include <math.h>

Vec2 vec_sum(Vec2 first, Vec2 other){
    Vec2 result = {
        first.x + other.x,
        first.y + other.y
    };
    return result;
}

Vec2 vec_sub(Vec2 first, Vec2 other){
    Vec2 result = {
        first.x - other.x,
        first.y - other.y
    };
    return result;
}

void vec_add(Vec2* first, const Vec2 other){
    first->x += other.x;
    first->y += other.y;
}

void vec_mult(Vec2* vec, double value){
    vec->x *= value;
    vec->y *= value;
}

void vec_normalize(Vec2* vec){
    double lenght = vec_mag(*vec);
    if (lenght != 0){
        vec->x /= lenght;
        vec->y /= lenght;
    }
}

double vec_mag(Vec2 vec){
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

double vec_dot_product(Vec2 first, Vec2 other){
    return (first.x * other.x + first.y * other.y);
}
