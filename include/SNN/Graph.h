#ifndef GRAPH_H
#define GRAPH_H
#include <SNN/Layer.h>
#include <stddef.h>
#include <string.h>

#ifdef SNNTYPE_INT16
typedef struct Graph{
    char* name;
    Layer *layers;
    uint16_t numLayers;
} Graph;

int16_t* forward(const Graph* model, const int16_t* data);
#endif

Graph create_graph();
void destroy_graph(Graph* model);

int8_t add_layer(Graph* model, Layer l);
void graph_summarize(const Graph* model);

#endif