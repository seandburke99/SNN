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
    uint16_t m;
    uint16_t n;
    int16_t** data;
} Matrix;

Vector* scalarxvect(const int16_t sc, const Vector* a);
int16_t vecxvecdot(const Vector* a, const Vector* b);
Vector* vecxmatdot(const Vector* a, const Matrix* b);
Matrix** matxmatdot(const Matrix* a, const Matrix* b);

#endif

#endif