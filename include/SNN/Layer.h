#ifndef LAYER_H
#define LAYER_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16
//Definition of activation function pointer for use in layer struct
typedef void(*ActivationFunction)(int16_t *data, size_t size);

//Layer structure
typedef struct Layer{
    char *name; //Name of the layer (unlikely to be useful on embedded devices)
    int16_t *dims; //Pointer to array that defines dimension sizes
    int16_t numDims; //Number of dimensions to layer
    int16_t *weights; //Pointer to flat weights buffer (Possible change to matrix)
    ActivationFunction act; //Pointer to activation function
} Layer; //Name struct "Layer"

/*
 * Forward function for a layer structure and compatible data
 * l: pointer to layer structure
 * data: pointer to data
 *
 * returns: pointer to new data array
 */
int16_t* layer_forward(const Layer *l, const int16_t *data);
#endif

/*
 * Function that is meant to create a new layer, initialized to 0
 *
 * returns: Pointer to new layer structure
 */
Layer* create_layer();

/*
 * Function that is meant to free all memory associated with layer structure pointer
 * l: layer structure
 *
 * returns: n/a
 */
void destroy_layer(Layer *l);

#endif