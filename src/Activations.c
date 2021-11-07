#include <SNN/Activations.h>
#include <stdio.h>

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
        printf("Data[%d]: %d\n", i, data[i]);
        data[i] = (SNNFTYPE)(255*tanh(data[i]/(float)(255*255)));
        printf("Data[%d]: %d\n", i, data[i]);
    }
    printf("\n");
}