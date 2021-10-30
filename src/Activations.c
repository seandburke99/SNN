#include <SNN/Activations.h>

#ifdef SNNTYPE_INT16
void ReLu(int16_t *data, size_t size){
    for(int i=0;i<size;i++){
        if(data[i]<0) data[i]=0; // x<=0: y=x, x>0:y=x
    }
}

void Sigmoid(int16_t *data, size_t size){
    for(int i=0;i<size;i++){
        //Multiplied by 32767 to give integer with some "decimal points"
        data[i] = 32767/(1.0+exp(-data[i]));
    }
}

void TanH(int16_t* data,  size_t size){
    for(int i=0;i<size;i++){
        //Multiplied by 32767 to give integer equivalent of decimal -1->1
        data[i] = (int16_t)round(32767*tanh(data[i])); 
    }
}
#endif