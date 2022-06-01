#ifndef GRAPH_H
#define GRAPH_H
#include <SNN/Layer.h>
#include <stddef.h>
#include <string.h>

typedef struct Graph{
    char* name;
    Layer **layers;
    size_t numLayers;
} Graph;

Graph* graph_create();
uint8_t graph_add_layer(Graph* model, const Layer *l);
Vector *graph_forward(const Graph* model, const Vector *data);
void graph_summarize(const Graph* model);
void graph_destroy(Graph* model);

#endif