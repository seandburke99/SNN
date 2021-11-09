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
void ReLu(SNNFTYPE* data, size_t size);

/*
 * Implements a modified Sigmoid function on input data that scales the value from 0 to 32767
 * sigmoid = 1/(1+exp(-data))
 * data: items to pass through the function
 * size: number of items to pass through the function
 *
 * returns: None
 */
void Sigmoid(SNNFTYPE *data, size_t size);

/*
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 * data: items to pass through the function
 * size: number of items to pass through the function
 *
 * returs: None
 */
void TanH(SNNFTYPE *data, size_t size);

/* 
 *
 */
int32_t sigmoid_lut_lookup(int32_t value);

/* 
 *
 */
int32_t tanh_lut_lookup(int32_t value);

static const uint16_t sigmoid_table_uint16[256] = {
    128,129,130,131,133,134,135,137,138,139,141,142,143,145,146,147,
    149,150,151,152,154,155,156,157,159,160,161,162,164,165,166,167,
    168,170,171,172,173,174,175,177,178,179,180,181,182,183,184,185,
    186,187,188,190,191,192,193,193,194,195,196,197,198,199,200,201,
    202,203,204,204,205,206,207,208,208,209,210,211,212,212,213,214,
    214,215,216,217,217,218,219,219,220,220,221,222,222,223,223,224,
    225,225,226,226,227,227,228,228,229,229,230,230,231,231,232,232,
    232,233,233,234,234,235,235,235,236,236,236,237,237,237,238,238,
    238,239,239,239,240,240,240,241,241,241,241,242,242,242,242,243,
    243,243,243,244,244,244,244,244,245,245,245,245,245,246,246,246,
    246,246,247,247,247,247,247,247,248,248,248,248,248,248,248,249,
    249,249,249,249,249,249,249,249,250,250,250,250,250,250,250,250,
    250,251,251,251,251,251,251,251,251,251,251,251,251,251,252,252,
    252,252,252,252,252,252,252,252,252,252,252,252,252,252,253,253,
    253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,
    253,253,253,253,253,253,253,254,254,254,254,254,254,254,254,255
};

#endif