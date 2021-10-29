#ifndef LINALG_H
#define LINALG_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16

typedef struct Vector{
    uint16_t n;
    int16_t* data;
} Vector;

typedef struct Matrix{
    uint16_t w;
    uint16_t h;
    int16_t** data;
} Matrix;

Matrix* init_mat(size_t h, size_t w, int16_t a[h][w]);
Vector* scalarxvect(const int16_t sc, const Vector* a);
int16_t* vecxvecdot(const Vector* a, const Vector* b);
Vector* vecxmatdot(const Vector* a, const Matrix* b);
Matrix* matxmatdot(const Matrix* a, const Matrix* b);
#endif

void destory_vector(Vector* src);
void destory_matrix(Matrix* src);

#endif