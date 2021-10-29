#include <SNN/SNN.h>
#include <SNN/Linalg.h>
#include <stdio.h>
#include <stdlib.h>

void init_layers(Graph* model);

int main(void){
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
    Matrix aM, bM, res;
    init_mat(&aM, 3, 5, a);
    init_mat(&bM, 5, 4, b);
    matxmatdot(&res, &aM, &bM);
    for(int i=0;i<res.h;i++){
        for(int j=0;j<res.w;j++){
            printf("%hd ", res.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}