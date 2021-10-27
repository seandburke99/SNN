#include <SNN/Activations.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int16_t test_data[3][1];
    for(int i=0;i<3;i++){
        test_data[i][0] = (rand() % 10) - 5;
    }
    ReLu(test_data[0], 1);
    Sigmoid(test_data[1], 1);
    TanH(test_data[2], 1);
    printf("Relu results: %d\nSigmoid results: %d\nTanH results: %d\n", test_data[0][0], test_data[1][0], test_data[2][0]);
    return 0;
}