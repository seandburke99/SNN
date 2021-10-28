#ifndef GRAPH_H
#define GRAPH_H
#include <SNN/Layer.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16
typedef struct Graph{
    Layer *layers;
    uint16_t numLayers;
    uint8_t compiled;
} Graph;

int16_t* forward(const Graph* model, const int16_t* data, size_t size);
#endif

#endif