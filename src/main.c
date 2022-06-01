#include <SNN/SNN.h>
#include <SNN/Ops.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
	Layer *l = layer_create(10, 5, act_relu, NULL);
	Vector *in = vec_const_init(10, 1.0f);
	Vector *out = layer_forward(l, in);
	vec_show(out);
	vec_destroy(in);
	vec_destroy(out);
	layer_destroy(l);
	return 0;
}