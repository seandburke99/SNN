#include <SNN/Activations.h>

#ifdef SNNTYPE_INT16
void ReLu(int16_t *data, size_t size){
    for(int i=0;i<size;i++){
        if(data[i]<0) data[i]=0;
    }
    return;
}

void Sigmoid(int16_t *data, size_t size){
    for(int i=0;i<size;i++){
        data[i] = (int16_t)round(255.0/(1.0+exp(-data[i])));
    }
    return;
}

void TanH(int16_t *data, size_t size){
    for(int i=0;i<size;i++){
        data[i] = (int16_t)round(255.0*tanh(data[i]));
    }
    return; 
}
#endif