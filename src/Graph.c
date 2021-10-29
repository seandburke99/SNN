#include <SNN/Graph.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef SNNTYPE_INT16
int16_t* forward(const Graph* model, const int16_t* data){
    int16_t* d1;
    int16_t* d2;
    d1 = layer_forward(&model->layers[0], data);
    for(int i=1;i<model->numLayers;i++){
        d2 = layer_forward(&model->layers[i], d1);
        free(d1);
        d1 = d2;
    }
    return d1;
}

void graph_summarize(const Graph* model){
    printf("%s\n\n", model->name);
    for(int i=0;i<model->numLayers;i++){
        printf("%s: ", model->layers[i].name);
        printf("%hd dims = ", model->layers[i].numDims);
        printf("%dx%d\n", model->layers[i].dims[0], model->layers[i].dims[1]);
    }
}
#endif
Graph* create_graph(){
    Graph* model = malloc(sizeof(Graph));
    model->layers = NULL;
    model->numLayers = 0;
    return model;
}

int8_t add_layer(Graph* model, Layer l){
    Layer* ls = calloc((model->numLayers+1), sizeof(Layer));
    if(model->numLayers){
        memcpy(ls, model->layers, sizeof(Layer)*model->numLayers);
    }
    memcpy(&ls[model->numLayers], &l, sizeof(Layer));
    model->layers = ls;
    model->numLayers++;
    return 0;
}

void destroy_graph(Graph* model){
    for(int i=0;i<model->numLayers;i++){
        destroy_layer(&model->layers[i]);
    }
    free(model->layers);
    free(model);
}