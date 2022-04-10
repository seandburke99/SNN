#ifndef LAYER_H
#define LAYER_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

//Definition of activation function pointer for use in layer struct
typedef void(*ActivationFunction)(SNNFTYPE *data, size_t size);

//Layer structure
typedef struct Layer{
    char *name; //Name of the layer (unlikely to be useful on embedded devices)
    size_t dims[2];
    SNNTYPE *weights; //Pointer to flat weights buffer (Possible change to matrix)
    SNNTYPE *bias;
    ActivationFunction act; //Pointer to activation function
} Layer; //Name struct "Layer"

/*
 * Forward function for a layer structure and compatible data
 * l: pointer to layer structure
 * data: pointer to data
 *
 * returns: pointer to new data array
 */
uint8_t layer_forward(const Layer *l, const SNNFTYPE *data, SNNFTYPE *result);

/*
 * Function that is meant to create a new layer, initialized to 0
 *
 * returns: New layer structure
 */
Layer layer_create();

/*
 * Function that is meant to free all memory associated with layer structure pointer
 * l: layer structure
 *
 * returns: n/a
 */
void layer_destroy(Layer *l);

#endif