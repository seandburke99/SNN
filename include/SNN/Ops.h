#ifndef OPS_H
#define OPS_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

typedef struct Vector{
    size_t n;
    SNNTYPE* data;
} Vector;

typedef struct Matrix{
    uint16_t w;
    uint16_t h;
    Vector** data;
} Matrix;

Vector *vec_init(size_t n);
Vector *vec_arr_init(size_t n, const SNNTYPE a[n]);
Vector *vec_const_init(size_t n, const SNNTYPE a);
Vector *vec_copy(const Vector *a);
void vec_show(const Vector *a);
void vec_destroy(Vector *a);

Matrix *mat_init(size_t h, size_t w);
Matrix* mat_arr_init(size_t h, size_t w, const SNNTYPE a[h][w]);
Matrix *mat_const_init(size_t h, size_t w, const SNNTYPE a);
Matrix *mat_copy(const Matrix *a);
void mat_show(const Matrix *a);
void mat_destroy(Matrix *a);

Vector* scalarxvect(const SNNTYPE sc, const Vector* a);
SNNTYPE vecxvecdot(const Vector* a, const Vector* b);
Vector* vecxmatdot(const Vector* a, const Matrix* b);

#endif