#ifndef VECTOR_C
#define VECTOR_C

typedef struct Vec2{
    double x;
    double y;
} Vec2;

Vec2 vec_sum(Vec2 first, Vec2 other);
Vec2 vec_sub(Vec2 first, Vec2 other);
void vec_add(Vec2* first, const Vec2 other);
void vec_mult(Vec2* vec, double value);
void vec_normalize(Vec2* vec);
double vec_mag(Vec2 vec);
double vec_dot_product(Vec2 first, Vec2 other);



#endif /* end of include guard: VECTOR_C */
