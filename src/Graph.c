#include <SNN/Graph.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Graph* graph_create(const char* name){
	Graph *g = calloc(1, sizeof(Graph));
	if(name!=NULL){
		g->name = malloc(strnlen(name, 20));
		strncpy(g->name, name, 20);
	}
	return g;
}

uint8_t graph_add_layer(Graph* model, const Layer *l){
	Vector **newLayers = calloc(model->numLayers, sizeof(Vector*));
	memcpy(newLayers, model->layers, model->numLayers*sizeof(Vector*));
	if(model->layers){
		realloc(model->layers, (model->numLayers+1)*sizeof(Vector*));
	}else{
		model->layers = calloc(1, sizeof(Vector*));
	}
	memcpy(model->layers, newLayers, model->numLayers*sizeof(Vector*));
	model->layers[model->numLayers] = layer_copy(l);
	assert(model->layers[model->numLayers++]);
	free(newLayers);
	return 0;
}

Vector *graph_forward(const Graph* model, const Vector *data){
	Vector *dp[2];
	dp[0] = vec_copy(data);
	for(size_t i=0;i<model->numLayers;i++){
		dp[1] = layer_forward(model->layers[i], dp[0]);
		free(dp[0]);
		dp[0] = dp[1];
	}
	return dp[1];
}

void graph_summarize(const Graph* model){
	for(size_t i=0;i<model->numLayers;i++){
		printf("%s: %d inputs, %d outputs\n", 
			model->layers[i]->name, 
			model->layers[i]->weights->w, 
			model->layers[i]->weights->h
		);
	}
	return;
}

void graph_destroy(Graph* model){
	for(size_t i=0;i<model->numLayers;i++){
		layer_destroy(model->layers[i]);
	}
	free(model->layers);
	free(model);
	return;
}