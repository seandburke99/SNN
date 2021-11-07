#include <SNN/Layer.h>
#include <SNN/Activations.h>
#include <stdio.h>

SNNFTYPE* layer_forward(const Layer* l, const SNNFTYPE* data){
    SNNFTYPE* _data = calloc(l->dims[1], sizeof(SNNFTYPE));
    for(int i=0;i<l->dims[1];i++){
        _data[i] = 0;
        for(int j=0;j< l->dims[0];j++){
            _data[i] += data[i]*l->weights[i*j+j];
        }
        _data[i] += l->bias[i];
    }
    l->act(_data, l->dims[1]);
    return _data;
}

Layer create_layer(){
    Layer l;
    l.act = NULL;
    l.dims = NULL;
    l.name = NULL;
    l.numDims = 0;
    l.weights = NULL;
    return l;
}

void destroy_layer(Layer *l){
    free(l->weights);
    free(l->dims);
}