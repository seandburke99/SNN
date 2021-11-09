#include <SNN/Layer.h>
#include <SNN/Activations.h>
#include <stdio.h>

SNNFTYPE* layer_forward(const Layer* l, const SNNFTYPE* data){
    SNNFTYPE* _data = calloc(l->dims[1],sizeof(SNNFTYPE));
    size_t offset = l->dims[0];
    unsigned int index;
    for(int i=0;i<l->dims[0];i++) printf("%f ", data[i]);
    printf("\n");
    for(int i=0;i<l->dims[1];i++){
        _data[i] = 0;
        for(int j=0;j< l->dims[0];j++){
            index = (i*offset) + j;
            _data[i] += data[i]*l->weights[index];
            printf("%f ", _data[i]);
            //printf("%0.6f ",l->weights[index]);
        }
        printf("\n");
        //printf("l->bias[%d] = %0.4f \n", i, l->bias[i]);
    }
    l->act(_data, l->dims[1]);
    return _data;
}

Layer create_layer(){
    //Create a layer and initialize all the pointers to 0
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