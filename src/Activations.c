#include <SNN/Activations.h>
#include <stdio.h>
#include <math.h>

static const int16_t sigmoid_table_uint16[384] = {
    64,64,64,65,65,66,66,67,67,67,68,68,69,69,70,70,
    71,71,71,72,72,73,73,74,74,74,75,75,76,76,77,77,
    77,78,78,79,79,79,80,80,81,81,82,82,82,83,83,84,
    84,84,85,85,85,86,86,87,87,87,88,88,89,89,89,90,
    90,90,91,91,91,92,92,92,93,93,94,94,94,95,95,95,
    96,96,96,97,97,97,97,98,98,98,99,99,99,100,100,100,
    101,101,101,101,102,102,102,102,103,103,103,104,104,104,104,105,
    105,105,105,106,106,106,106,107,107,107,107,108,108,108,108,108,
    109,109,109,109,109,110,110,110,110,111,111,111,111,111,111,112,
    112,112,112,112,113,113,113,113,113,113,114,114,114,114,114,114,
    115,115,115,115,115,115,115,116,116,116,116,116,116,116,117,117,
    117,117,117,117,117,117,118,118,118,118,118,118,118,118,119,119,
    119,119,119,119,119,119,119,119,120,120,120,120,120,120,120,120,
    120,120,120,121,121,121,121,121,121,121,121,121,121,121,121,122,
    122,122,122,122,122,122,122,122,122,122,122,122,122,122,123,123,
    123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,
    123,124,124,124,124,124,124,124,124,124,124,124,124,124,124,124,
    124,124,124,124,124,124,124,124,124,124,125,125,125,125,125,125,
    125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,
    125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,126,
    126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,
    126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,
    126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,
    126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,127
};

void act_relu(SNNFTYPE *data, size_t size){
    for(int i=0;i<size;i++){
        if(data[i]<0) data[i]=0; // x<=0: y=x, x>0:y=x
    }
}

void act_sigmoid(SNNFTYPE *data, size_t size){
    for(int i=0;i<size;i++){
        data[i] = 255.0/(1.0+exp(-data[i]/255.0));
    }
}

void act_tanh(SNNFTYPE* data,  size_t size){
    for(int i=0;i<size;i++){
        data[i] = (SNNFTYPE)(tanh_lut_lookup(data[i]));
    }
    printf("\n");
}

int32_t sigmoid_lut_lookup(int32_t value) {
    value /= 38;
    if(abs(value)>=384){
        if(value<0) return 0;
        else return 127;
    }
    if(value < 0){
        value *= -1;
        return 128 - sigmoid_table_uint16[value];
    }
    return sigmoid_table_uint16[value];
}

int32_t tanh_lut_lookup(int32_t value) {
    value = value/38;
    if(value < 0){
        if(value <= -384) return -127;
        int index = value*-1;
        return -2*sigmoid_table_uint16[index] + 128;
    }else{
        if(value >= 384) return 127;
        return 2*sigmoid_table_uint16[value] - 128;
    }
}