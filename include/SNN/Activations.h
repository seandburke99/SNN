/*
 * File:  Activations.h 
 * --------------------
 * Contains 3 basic implementations of the ReLu, Sigmoid, and Tanh functions on array's of data
 * 
 * Written By: Sean Burke
 * 
 * MIT License
 * 
 */

#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H
#include <SNN/SNN_Config.h>
#include <math.h>
#include <stdlib.h>

/*
 * Implements the (Re)ctified (L)inear (U)nit function on input data:
 * data: items to pass through the function
 * size: number of items to pass through the function
 *
 * returns: None
 */
void act_relu(SNNFTYPE* data, size_t size);

/*
 * Implements a modified Sigmoid function on input data that scales the value from 0 to 32767
 * sigmoid = 1/(1+exp(-data))
 * data: items to pass through the function
 * size: number of items to pass through the function
 *
 * returns: None
 */
void act_sigmoid(SNNFTYPE *data, size_t size);

/*
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 * data: items to pass through the function
 * size: number of items to pass through the function
 *
 * returs: None
 */
void act_tanh(SNNFTYPE *data, size_t size);

/* 
 *
 */
int32_t sigmoid_lut_lookup(int32_t value);

/* 
 *
 */
int32_t tanh_lut_lookup(int32_t value);

#endif