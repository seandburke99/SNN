#include <SNN/Linalg.h>
#include <string.h>
#include <stdlib.h>

#ifdef SNNTYPE_INT16

Matrix* init_mat(size_t h, size_t w, int16_t a[h][w]){
    Matrix* mat = malloc(sizeof(Matrix));
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
                return NULL;
            }
        }
    }
    else{
        return NULL;
    }
    return mat;
}

Vector* scalarxvect(const int16_t sc, const Vector* a){
    Vector* dst = malloc(sizeof(Vector));
    dst->n = a->n;
    dst->data = malloc(sizeof(a->data[0])*dst->n);
    if(dst->data){
    for(int i=0;i<a->n;i++){
        dst->data[i] = a->data[i]*sc;
    }
    }else{
        return NULL;
    }
    return dst;
}

int16_t* vecxvecdot(const Vector* a, const Vector* b){
    int16_t* dst = malloc(sizeof(int16_t));
    if(a->n==b->n){
        *dst = 0;
        for(int i=0;i<a->n;i++){
            *dst += a->data[i] * b->data[i];
        }
    }else{
        return NULL;
    }
    return dst;
}

Vector* vecxmatdot(const Vector* a, const Matrix* b){
    Vector* dst = malloc(sizeof(Vector));
    dst->n = b->w;
    dst->data = malloc(sizeof(int16_t)*dst->n);
    if(a->n != b->h){
        return NULL;
    }
    for(int j=0;j< b->w;j++){
        for(int i=0;i<b->h;i++){
            dst->data[j] = a->data[i]*b->data[i][j];
        }
    }
    return dst;
}

Matrix* matxmatdot(const Matrix* a, const Matrix* b){
    Matrix* dst = malloc(sizeof(Matrix));
    if(a->w != b->h){
        return NULL;
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
                return NULL;
            }
        }
    }else{
        return NULL;
    }
    return dst;
}

#endif

void destory_vector(Vector* src){
    free(src->data);
    free(src);
    src = NULL;
}

void destory_matrix(Matrix* src){
    free(src->data);
    free(src);
    src = NULL;
}