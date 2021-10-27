#ifndef LAYER_H
#define LAYER_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16
typedef struct Layer{
    int16_t* nodes;
    int16_t* weights;
    int16_t numNodes;
} Layer;

void layer_forward(Layer* l, int16_t* data, size_t dataLen);
#endif


#endif