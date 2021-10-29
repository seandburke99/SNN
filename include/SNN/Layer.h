#ifndef LAYER_H
#define LAYER_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16
typedef void(*ActivationFunction)(int16_t *data, size_t size);

typedef struct Layer{
    char* name;
    int16_t* dims;
    int16_t numDims;
    int16_t* weights;
    ActivationFunction act;
} Layer;

int16_t* layer_forward(const Layer* l, const int16_t* data);
#endif

Layer* create_layer();
void destroy_layer(Layer *l);

#endif