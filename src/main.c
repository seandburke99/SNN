#include <SNN/SNN.h>
#include <SNN/Ops.h>
#include <stdio.h>
#include <stdlib.h>

const double l1[3][5] = {
	{-1.0, 0.0, 0.0, 0.0, 0.0},
	{0.0, 1.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0, 0.0}
};

const double l2[1][3] = {
	{1.0, 1.0, 1.0}
};

int main(int argc, char *argv[]){
	Graph *g = graph_create(NULL);
	Layer *l = layer_create(5, 3, act_relu, l1);
	graph_add_layer(g, l);
	graph_summarize(g);
	layer_destroy(l);
	// l = layer_create(3, 1, act_relu, l2);
	// graph_add_layer(g, l);
	// graph_summarize(g);
	Vector *res = NULL, *data = vec_const_init(5, 1.0);
	res = graph_forward(g, data);
	for(size_t i=0;i<res->n;i++){
		printf("%lf ", res->data[i]);
	}
	printf("\n");

	return 0;
}