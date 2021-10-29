#include <SNN/SNN.h>
#include <SNN/Linalg.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int16_t a = 2;
    Vector b, c;
    b.data = calloc(12, sizeof(int16_t));
    b.n = 12;
    printf("Before: ");
    for(int i=0;i<b.n;i++){
        b.data[i] = 1;
        printf("%hd ", b.data[i]);
    }
    printf("\n");
    c = *scalarxvect(8, &b);
    printf("After: ");
    for(int i=0;i<c.n;i++){
        printf("%hd ", c.data[i]);
    }
    printf("\n");
    return 0;
}