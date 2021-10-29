#include <SNN/Linalg.h>
#include <string.h>
#include <stdlib.h>

#ifdef SNNTYPE_INT16

uint8_t init_mat(Matrix* mat, size_t h, size_t w, int16_t a[h][w]){
    mat->h = h;
    mat->w = w;
    mat->data = malloc(h*sizeof(int16_t*));
    if(mat->data){
        for(int i=0;i<h;i++){
            mat->data[i] = malloc(w*sizeof(int16_t));
            if(mat->data[i]){
                for(int j=0;j<w;j++){
                    mat->data[i][j] = a[i][j];
                }
            }else{
                return 1;
            }
        }
    }
    else{
        return 1;
    }
    return 0;
}

uint8_t scalarxvect(Vector* dst, const int16_t sc, const Vector* a){
    dst->n = a->n;
    dst->data = malloc(sizeof(a->data[0])*dst->n);
    for(int i=0;i<a->n;i++){
        dst->data[i] = a->data[i]*sc;
    }
    return 0;
}

uint8_t vecxvecdot(int16_t* dst, const Vector* a, const Vector* b){
    if(a->n==b->n){
        *dst = 0;
        for(int i=0;i<a->n;i++){
            *dst += a->data[i] * b->data[i];
        }
    }else{
        return 1;
    }
    return 0;
}

uint8_t vecxmatdot(Vector* dst, const Vector* a, const Matrix* b){
    dst->n = b->w;
    dst->data = malloc(sizeof(int16_t)*dst->n);
    if(a->n != b->h){
        return 1;
    }
    for(int j=0;j< b->w;j++){
        for(int i=0;i<b->h;i++){
            dst->data[j] = a->data[i]*b->data[i][j];
        }
    }
    return 0;
}

uint8_t matxmatdot(Matrix* dst, const Matrix* a, const Matrix* b){
    if(a->w != b->h){
        return 1;
    }
    dst->w = b->w;
    dst->h = a->h;
    dst->data = calloc(dst->h, sizeof(int16_t*));
    if(dst->data){
        for(int i=0;i<dst->h;i++){
            dst->data[i] = calloc(dst->w, sizeof(int16_t));
            if(dst->data[i]){
                for(int j=0;j<dst->w;j++){
                    for(int k=0;k<a->w;k++){
                        dst->data[i][j] += a->data[i][k] * b->data[k][j];
                    }
                }
            }else{
                return 1;
            }
        }
    }else{
        return 1;
    }
    return 0;
}

#endif