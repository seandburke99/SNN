#include <SNN/Graph.h>
#include <stdio.h>
#include <stdlib.h>

Graph* graph_create(const char* name){
	Graph *g = calloc(1, sizeof(Graph));
	if(name){
		g->name = malloc(strlen(name));
		strcpy(g->name, name);
	}
	return g;
}

uint8_t graph_add_layer(Graph* model, const Layer *l){
	Vector **newLayers = calloc(model->numLayers, sizeof(Vector*));
	memcpy(newLayers, model->layers, model->numLayers*sizeof(Vector*));
	reallocarray(model->layers, model->numLayers+1, sizeof(Vector*));
	memcpy(model->layers, newLayers, model->numLayers*sizeof(Vector*));
	model->layers[model->numLayers] = l;
	assert(model->layers[model->numLayers++]);
	return 0;
}

Vector *graph_forward(const Graph* model, const Vector *data);
void graph_summarize(const Graph* model);
void graph_destroy(Graph* model);