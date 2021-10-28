#include <SNN/Graph.h>
#include <SNN/Layer.h>
#include <string.h>
#include <stdlib.h>

#ifdef SNNTYPE_INT16
int16_t* forward(const Graph* model, const int16_t *data, size_t size){
    int16_t* _data = malloc(size*2);
    memcpy(_data, data, size*2);
    for(int i=0;i<model->numLayers;i++){
        _data = layer_forward(&model->layers[i], _data, size);
        size = model->layers[i].numNodes;
    }
    return _data;
}
#endif