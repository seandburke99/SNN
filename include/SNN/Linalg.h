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

uint8_t init_mat(Matrix* mat, size_t h, size_t w, int16_t a[h][w]);
uint8_t scalarxvect(Vector*dst, const int16_t sc, const Vector* a);
uint8_t vecxvecdot(int16_t* dst, const Vector* a, const Vector* b);
uint8_t vecxmatdot(Vector* dst, const Vector* a, const Matrix* b);
uint8_t matxmatdot(Matrix* dst, const Matrix* a, const Matrix* b);

#endif

#endif