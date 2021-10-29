#include <SNN/Linalg.h>
#include <string.h>

#ifdef SNNTYPE_INT16

Vector* scalarxvect(const int16_t sc, const Vector* a){
    Vector* result = malloc(sizeof(a->data[0])*a->n);
    for(int i=0;i<a->n;i++){
        result->data[i] = a->data[i]*sc;
    }
    return result;
}

int16_t vecxvecdot(const Vector* a, const Vector* b);
Vector* vecxmatdot(const Vector* a, const Matrix* b);
Matrix** matxmatdot(const Matrix* a, const Matrix* b);

#endif