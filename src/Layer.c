#include <SNN/Layer.h>
#include <SNN/Activations.h>
#include <stdio.h>

uint8_t layer_forward(const Layer* l, const SNNFTYPE* data, SNNFTYPE *result){
    result = (SNNFTYPE*)calloc(l->dims[1],sizeof(SNNFTYPE));
    size_t offset = l->dims[0];
    unsigned int index;
    for(int i=0;i<l->dims[1];i++){
        result[i] = (double)l->bias[i];
        for(int j=0;j< l->dims[0];j++){
            index = (i*offset) + j;
            result[i] += data[j]*l->weights[index];
        }
    }
    l->act(result, l->dims[1]);
    return 0;
}

Layer layer_create(){
    //Create a layer and initialize all the pointers to 0
    Layer l;
    l.act = NULL;
    l.name = NULL;
    l.weights = NULL;
    return l;
}

void layer_destroy(Layer *l){
    free(l->weights);
    free(l->dims);
}