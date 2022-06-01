#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H
#include <SNN/SNN_Config.h>
#include <SNN/Ops.h>
#include <math.h>
#include <stdlib.h>

Vector *act_relu(const Vector *data);

Vector *act_sigmoid(const Vector *data);

Vector *act_tanh(const Vector *data);

int32_t sigmoid_lut_lookup(int32_t value);
int32_t tanh_lut_lookup(int32_t value);

#endif