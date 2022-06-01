#ifndef LAYER_H
#define LAYER_H
#include <SNN/SNN_Config.h>
#include <SNN/Ops.h>
#include <stddef.h>

typedef Vector*(*ActivationFunction)(const Vector *data);

typedef struct Layer{
    char *name;
    Matrix *weights;
    ActivationFunction act;
} Layer;

Layer *layer_create(size_t inDim, size_t outDim, ActivationFunction actFunc, const SNNTYPE **im);

Vector *layer_forward(const Layer* l, const Vector *data);

void layer_destroy(Layer *l);

#endif