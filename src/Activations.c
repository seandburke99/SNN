#include <SNN/Activations.h>
#include <stdio.h>
#include <math.h>

void ReLu(SNNFTYPE *data, size_t size){
    for(int i=0;i<size;i++){
        if(data[i]<0) data[i]=0; // x<=0: y=x, x>0:y=x
    }
}

void Sigmoid(SNNFTYPE *data, size_t size){
    for(int i=0;i<size;i++){
        data[i] = 255.0/(1.0+exp(-data[i]/255.0));
    }
}

void TanH(SNNFTYPE* data,  size_t size){
    for(int i=0;i<size;i++){
        
        printf("data[%d]: %0.4f\n",i,data[i]);
        // data[i] = tanh_lut_lookup(data[i]);
        data[i] = (SNNFTYPE)(tanh(data[i]));
        printf("data[%d]: %0.4f\n",i,data[i]);
    }
}

int32_t sigmoid_lut_lookup(int32_t value) {
    value /= 255/48;
    if(abs(value)>255){
        if(value<0) return 0;
        else return 255;
    }
    if(value < 0){
        value *= -1;
        return 255 - sigmoid_table_uint16[value];
    }
    return sigmoid_table_uint16[value];
}

int32_t tanh_lut_lookup(int32_t value) {
    value /= 255/48;
    value *= 2;
    if(value < 0){
        if(value < -255) return -255;
        int8_t index = value*-1;
        return 2*sigmoid_table_uint16[index] - 256;
    }else{
        if(value > 255) return 255;
        return 2*sigmoid_table_uint16[value] - 256;
    }
}