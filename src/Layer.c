#include <SNN/Layer.h>
#include <SNN/Activations.h>

#ifdef SNNTYPE_INT16

void layer_forward(Layer* l, int16_t* data, size_t dataLen){
    for(int i=0;i<l->numNodes;i++){
        l->nodes[i] = 0;
        for(int j=0;j<dataLen;j++){
            l->nodes[i] += data[j]*l->weights[i*j];
        }
    }
    return;
}

#endif