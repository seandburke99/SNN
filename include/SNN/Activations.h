#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H
#include <SNN/SNN_Config.h>
#include <math.h>
#include <stdlib.h>

#ifdef SNNTYPE_INT16
void ReLu(int16_t *data, size_t size);
void Sigmoid(int16_t *data, size_t size);
void TanH(int16_t *data, size_t size);
#endif

#endif