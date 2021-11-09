#include <SNN/Graph.h>
#include <stdio.h>
#include <stdlib.h>

SNNFTYPE* forward(const Graph* model, const SNNFTYPE* data){
    SNNFTYPE* d1;
    SNNFTYPE* d2;
    d1 = layer_forward(&model->layers[0], data);
    for(int i=1;i<model->numLayers;i++){
        d2 = layer_forward(&model->layers[i], d1);
        free(d1);
        d1 = d2;
    }
    return d1;
}

void graph_summarize(const Graph* model){
    if(model->name != NULL)
        printf("%s\n\n", model->name);
    for(int i=0;i<model->numLayers;i++){
        if(model->layers[i].name)
            printf("%s: ", model->layers[i].name);
        printf("%zd dims = ", model->layers[i].numDims);
        printf("%zdx%zd\n", model->layers[i].dims[0], model->layers[i].dims[1]);
        int numbias = model->layers[i].dims[1];
        printf("Weights:\n");
        int sum = 1;
        for(int j=0;j<model->layers[i].numDims;j++){
            sum *= model->layers[i].dims[j];
        }
        for(int j=0;j<sum;j++){
            printf("%f ", model->layers[i].weights[j]);
            if(j && !(j%model->layers[i].dims[model->layers[i].numDims-1]))
                printf("\n");
        }
        printf("\nBias: %d\n", numbias);
        for(int j=0;j<numbias;j++){
            printf("%f ", model->layers[i].bias[j]);
        }
        printf("\n");
    }
}

Graph* create_graph(){
    Graph* model = malloc(sizeof(Graph));
    model->name = NULL;
    model->layers = NULL;
    model->numLayers = 0;
    return model;
}

uint8_t add_layer(Graph* model, Layer l){
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