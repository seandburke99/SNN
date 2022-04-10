/*
 * File:  Graph.h 
 * --------------------
 * Top level implementation of neural network with Graph structure
 * and some accompanying functions
 * 
 * Written By: Sean Burke
 * 
 * MIT License
 * 
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <SNN/Layer.h>
#include <stddef.h>
#include <string.h>

//Structure to contain the full network
typedef struct Graph{
    char* name;             //Name of the netural network
    Layer *layers;         //Pointer to array of layers for the network
    size_t numLayers;     //Counter for the number of layers in a network
} Graph;

uint8_t graph_forward(const Graph* model, const SNNFTYPE* data, SNNFTYPE *result);

Graph* graph_create();

void graph_destroy(Graph* model);

uint8_t graph_add_layer(Graph* model, const Layer l);

void graph_summarize(const Graph* model);

#endif