#include <SNN/SNN.h>
#include <SNN/Linalg.h>
#include <stdio.h>
#include <stdlib.h>

void init_layers(Graph* model);

int main(void){
    // int16_t *a[3] = {
    //     (int16_t[]){2, 3},
    //     (int16_t[]){3, 3},
    //     (int16_t[]){2, 4}
    // };
    // aM.data = a;
    // int16_t *b[2] = {
    //     (int16_t[]){2, 3, 1},
    //     (int16_t[]){3, 4, 2},
    // };
    int16_t a[3][5] = {
        {2, 3, 4, 2, 7},
        {3, 3, 6, 2, 8},
        {2, 4, 8, 1, 4}
    };
    int16_t b[5][4] = {
        {2, 3, 1, 2},
        {3, 4, 2, 6},
        {2, 3, 1, 9},
        {3, 4, 2, 0},
        {2, 3, 1, 4}
    };
    Matrix aM = init_mat(3, 5, a);
    Matrix bM = init_mat(5, 4, b);
    Matrix res = matxmatdot(&aM, &bM);
    for(int i=0;i<res.h;i++){
        for(int j=0;j<res.w;j++){
            printf("%hd ", res.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}