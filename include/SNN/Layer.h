#ifndef LAYER_H
#define LAYER_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16
typedef void(*ActivationFunction)(int16_t *data, size_t size);

typedef struct Layer{
    int16_t* nodes;
    int16_t* weights;
    int16_t numNodes;
    ActivationFunction act;
} Layer;

int16_t* layer_forward(const Layer* l, const int16_t* data, size_t* dataLen);

Layer create_layer(size_t* dimensions, void (*activation_function)(int16_t *data, size_t size));
#endif


#endif