#include <SNN/Layer.h>
#include <SNN/Activations.h>
#include <stdio.h>

Layer *layer_create(size_t inDim, size_t outDim, ActivationFunction actFunc, const SNNTYPE **im){
    Layer *l = calloc(1, sizeof(Layer));
    l->act = actFunc;
    if(im){
        l->weights = mat_arr_init(outDim, inDim, im);
    }else{
        l->weights = mat_init(outDim, inDim);
    }
    return l;
}

Vector *layer_forward(const Layer* l, const Vector *data){
    return l->act(vecxmatdot(data, l->weights));
}

void layer_destroy(Layer *l){
    return;
}