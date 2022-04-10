#include <SNN/SNN.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    Layer l = layer_create();
    l.act = act_sigmoid;
    l.dims[0] = 4;
    l.dims[1] = 8;
    return 0;
}