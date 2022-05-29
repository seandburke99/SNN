#include <SNN/Graph.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t forward(const Graph* model, const SNNFTYPE* data, SNNFTYPE *result){
    SNNFTYPE *d1 = NULL, *d2 = NULL;
    layer_forward(&model->layers[0], data, d1);
    for(int i=1;i<model->numLayers;i++){
        layer_forward(&model->layers[i], d1, d2);
        free(d1);
        d1 = d2;
    }
    result = d1;
    return 0;
}

Graph* graph_create(){
    Graph* model = malloc(sizeof(Graph));
    model->name = NULL;
    model->layers = NULL;
    model->numLayers = 0;
    return model;
}

uint8_t graph_add_layer(Graph* model, Layer l){
    Layer* ls = calloc((model->numLayers+1), sizeof(Layer));
    if(model->numLayers){
        memcpy(ls, model->layers, sizeof(Layer)*model->numLayers);
    }
    memcpy(&ls[model->numLayers], &l, sizeof(Layer));
    model->layers = ls;
    model->numLayers++;
    return 0;
}

void graph_destroy(Graph* model){
    for(int i=0;i<model->numLayers;i++){
        layer_destroy(&model->layers[i]);
    }
    free(model->layers);
    free(model);
}