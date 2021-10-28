/*
 * File:  Activations.h 
 * --------------------
 * Contains the activation functions for the 
 * 
 * Written By: Sean Burke
 * 
 * Use of any of this code in libraries is allowed as long as proper credit is
 * given. Use of this code is at your own discretion and the author is not responsible
 * for anything resulting from the use of this code.
 * 
 */

#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H
#include <SNN/SNN_Config.h>
#include <math.h>
#include <stdlib.h>

//If the desired network type is 16 bit ints
#ifdef SNNTYPE_INT16
/*
 * Function: ReLu 
 * --------------------
 * Implements the (Re)ctified (L)inear (U)nit function on input data:
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returns: None
 */
void ReLu(int16_t* data, size_t size);

/*
 * Function: Sigmoid 
 * --------------------
 * Implements a modified Sigmoid function on input data that scales the value from 0 to 32767
 * sigmoid = 1/(1+exp(-data))
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returns: None
 */
void Sigmoid(int16_t *data, size_t size);

/*
 * Function:  TanH 
 * --------------------
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returs: None
 */
void TanH(int16_t *data, size_t size);
#endif

#endif