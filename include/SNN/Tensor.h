#ifndef TENSOR_H
#define TENSOR_H
#include <SNN/SNN_Config.h>
#include <stddef.h>

#ifdef SNNTYPE_INT16

typedef struct Tensor{
    size_t *dimSizes;
    size_t numDims;
    int16_t *data;
} Tensor;

#endif

Tensor create_tensor(int16_t size, size_t numDims, void* data, size_t dataLen);

#endif