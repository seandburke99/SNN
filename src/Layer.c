#include <SNN/Layer.h>
#include <SNN/Activations.h>

#ifdef SNNTYPE_INT16

int16_t* layer_forward(const Layer* l, const int16_t* data, size_t* dataLen){
    int16_t* _data = malloc(l->numNodes*2);
    for(int i=0;i<l->numNodes;i++){
        l->nodes[i] = 0;
        for(int j=0;j< *dataLen;j++){
            _data[i] += data[j]*l->weights[i*j];
        }
    }
    l->act(_data, l->numNodes);
    *dataLen = l->numNodes;
    return _data;
}

#endif