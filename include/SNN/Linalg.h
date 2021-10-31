/*
 * File:  Linalg.h 
 * --------------------
 * Basic linear algebra components with int16 implementations for running on an
 * embedded device with limited float math speed.
 * 
 * Written By: Sean Burke
 * 
 * MIT License
 * 
 */

#ifndef LINALG_H
#define LINALG_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16

//Basic vector struct with size and data
typedef struct Vector{
    uint16_t n;             //Length or size
    int16_t* data;          //Pointer to data
} Vector;

//Basic matrix implementation with height, width, and data
typedef struct Matrix{
    uint16_t w;             //Width
    uint16_t h;             //Height
    int16_t** data;         //Pointer to data
} Matrix;

/*
 * Initialization function for matricies from 2d array to matrix struct
 * h: height of matrix
 * w: width of matrix
 * a: 2d array of initial values
 *
 * returns: pointer to new matrix struct with initialized data values
 */
Matrix* init_mat(size_t h, size_t w, const int16_t a[h][w]);

/*
 * [NOTICE]: Not yet implemented. Declared only. DO NOT CALL.
 * 
 * Initialization function for matricies from flat buffer to matrix struct
 * h: height of matrix
 * w: width of matrix
 * a: 1d array of initial values
 *
 * returns: pointer to new matrix struct with initialized data values
 */
Matrix* init_matFB(size_t h, size_t w, const int16_t a[]);

/*
 * Function that is meant to multiply a vector by a scalar value
 * sc: scalar 16 bit integer value
 * a: Vector structure
 *
 * returns: pointer to new vector struct with new data values
 *          null if memory is unable to be allocated
 */
Vector* scalarxvect(const int16_t sc, const Vector* a);

/*
 * Function that is meant to multiply a vector by a vector
 * a: Vector structure
 * b: Vecotr structure
 *
 * returns: pointer to a 16 bit integer result
 *          null if memory is unable to be allocated or vectors are
 *          uncompatible
 */
int16_t* vecxvecdot(const Vector* a, const Vector* b);

/*
 * Function that is meant to multiply a vector by a compatible matrix
 * a: Vector structure
 * b: Matrix structure
 *
 * returns: pointer to a new matrix structure
 *          null if memory is unable to be allocated or structures are
 *          uncompatible
 */
Vector* vecxmatdot(const Vector* a, const Matrix* b);

/*
 * Function that is meant to multiply a matrix by a compatible matrix
 * a: matrix structure
 * b: matrix structure
 *
 * returns: pointer to a new matrix structure
 *          null if memory is unable to be allocated or matricies are
 *          uncompatible
 */
Matrix* matxmatdot(const Matrix* a, const Matrix* b);
#endif

#endif