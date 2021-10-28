#include <SNN/Layer.h>
#include <SNN/Activations.h>
#include <stdio.h>

#ifdef SNNTYPE_INT16

int16_t* layer_forward(const Layer* l, const int16_t* data){
    int16_t* _data = malloc(l->dims[1]*2);
    for(int i=0;i<l->dims[1];i++){
        _data[i] = 0;
        for(int j=0;j< l->dims[0];j++){
            _data[i] += data[j]*l->weights[i*j];
        }
    }
    l->act(_data, l->dims[l->numDims-1]);
    return _data;
}


#endif

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