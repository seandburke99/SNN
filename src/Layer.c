#include <SNN/Layer.h>
#include <SNN/Activations.h>

#ifdef SNNTYPE_INT16

int16_t* layer_forward(const Layer* l, const int16_t* data, size_t dataLen){
    for(int i=0;i<l->numNodes;i++){
        l->nodes[i] = 0;
        for(int j=0;j<dataLen;j++){
            l->nodes[i] += data[j]*l->weights[i*j];
        }
    }
    l->act(l->nodes, l->numNodes);
    return _data;
}

#endif