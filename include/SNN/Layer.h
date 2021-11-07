#ifndef LAYER_H
#define LAYER_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

//Definition of activation function pointer for use in layer struct
typedef void(*ActivationFunction)(SNNFTYPE *data, size_t size);

//Layer structure
typedef struct Layer{
    char *name; //Name of the layer (unlikely to be useful on embedded devices)
    size_t *dims; //Pointer to array that defines dimension sizes
    size_t numDims; //Number of dimensions to layer
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
SNNFTYPE* layer_forward(const Layer *l, const SNNFTYPE *data);

/*
 * Function that is meant to create a new layer, initialized to 0
 *
 * returns: Pointer to new layer structure
 */
Layer create_layer();

/*
 * Function that is meant to free all memory associated with layer structure pointer
 * l: layer structure
 *
 * returns: n/a
 */
void destroy_layer(Layer *l);

#endif

/*
 *
 * Neural network linear structure has previous size across and current size down
 * For example, 8->10 nodes has the matrix shape [10,8] 10 rows, 8 columns
 * For example, 10->2 nodes has the matrix shape [2, 10] 2 rows, 10 columns
 * Following this logic, the next layers first node has it valued multiplied by the first row of weights
 * based on how the sizes line up.
 * 
*/