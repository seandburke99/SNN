#include <SNN/Linalg.h>
#include <string.h>
#include <stdlib.h>

#ifdef SNNTYPE_INT16

Matrix init_mat(size_t h, size_t w, int16_t a[h][w]){
    Matrix mat = {0};
    mat.h = h;
    mat.w = w;
    mat.data = malloc(h*sizeof(int16_t*));
    if(mat.data){
        for(int i=0;i<h;i++){
            mat.data[i] = malloc(w*sizeof(int16_t));
            if(mat.data[i]){
                for(int j=0;j<w;j++){
                    mat.data[i][j] = a[i][j];
                }
            }
        }
    }
    return mat;
}

Vector scalarxvect(const int16_t sc, const Vector* a){
    Vector result;
    result.n = a->n;
    result.data = malloc(sizeof(a->data[0])*result.n);
    for(int i=0;i<a->n;i++){
        result.data[i] = a->data[i]*sc;
    }
    return result;
}

int16_t vecxvecdot(const Vector* a, const Vector* b){
    int16_t result;
    if(a->n==b->n){
        for(int i=0;i<a->n;i++){
            result += a->data[i] * b->data[i];
        }
    }
    return result;
}

Vector vecxmatdot(const Vector* a, const Matrix* b){
    Vector result;
    result.n = b->w;
    result.data = malloc(sizeof(int16_t)*result.n);
    if(a->n != b->h){
        return;
    }
    for(int j=0;j< b->w;j++){
        for(int i=0;i<b->h;i++){
            result.data[j] = a->data[i]*b->data[i][j];
        }
    }
    return result;
}

Matrix matxmatdot(const Matrix* a, const Matrix* b){
    Matrix result;
    result.w = b->w;
    result.h = a->h;
    result.data = calloc(result.h, sizeof(int16_t*));
    for(int i=0;i<result.h;i++){
        result.data[i] = calloc(result.w, sizeof(int16_t));
        for(int j=0;j<result.w;j++){
            for(int k=0;k<a->w;k++){
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

#endif