#include <SNN/Linalg.h>
#include <string.h>

#ifdef SNNTYPE_INT16

Vector* scalarxvect(const int16_t sc, const Vector* a){
    Vector* result;
    result->n = a->n;
    result->data = malloc(sizeof(a->data[0])*result->n);
    for(int i=0;i<a->n;i++){
        result->data[i] = a->data[i]*sc;
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

Vector* vecxmatdot(const Vector* a, const Matrix* b){
    Vector* result;
    result->n = b->w;
    result->data = malloc(sizeof(int16_t)*result->n);
    if(a->n != b->h){
        return NULL;
    }
    for(int j=0;j< b->w;j++){
        for(int i=0;i<b->h;i++){
            result->data[j] = a->data[i]*b->data[i][j];
        }
    }
    return result;
}

Matrix* matxmatdot(const Matrix* a, const Matrix* b){
    Matrix* result;
    if(a->w != b->h){
        return NULL;
    }
    result->w = a->h;
    result->h = b->w;
    result->data = malloc(sizeof(int16_t)*result->w*result->h);
    return 
}

#endif