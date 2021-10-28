#include <SNN/Graph.h>
#include <SNN/Layer.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef SNNTYPE_INT16
int16_t* forward(const Graph* model, const int16_t* data, size_t* size){
    int16_t* _data;
    _data = layer_forward(&model->layers[0], data, size);
    for(int i=1;i<model->numLayers;i++){
        _data = layer_forward(&model->layers[i], _data, size);
        *size = model->layers[i].numNodes;
    }
    return _data;
}
#endif

int8_t add_layer(Graph* model, Layer l){
    Layer *ls = malloc(sizeof(Layer)*(model->numLayers+1));
    memcpy(ls, model->layers, sizeof(Layer)*model->numLayers);
    memcpy(&ls[model->numLayers], &l, sizeof(Layer));
    model->numLayers++;
    return 0;
}