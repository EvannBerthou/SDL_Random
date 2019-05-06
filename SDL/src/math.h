#ifndef MATH_H
#define MATH_H

typedef struct{
    int x;
    int y;
}Vec2;

Vec2 vec_sum(Vec2 first, Vec2 other);
void vec_add(Vec2* first, Vec2 other);

#endif
