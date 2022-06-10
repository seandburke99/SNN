#include <SNN/Layer.h>
#include <SNN/Activations.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Layer *layer_create(size_t inDim, size_t outDim, ActivationFunction actFunc, const SNNTYPE im[outDim][inDim]){
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

Layer *layer_copy(const Layer *l){
    Layer *nl = calloc(1, sizeof(Layer));
    nl->weights = mat_copy(l->weights);
    nl->act = l->act;
    if(l->name!=NULL){
        nl->name = malloc(strnlen(l->name, 20));
        strncpy(nl->name, l->name, strnlen(l->name, 20));
    }
    return nl;
}

void layer_destroy(Layer *l){
    return;
}