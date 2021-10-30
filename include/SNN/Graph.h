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

#ifdef SNNTYPE_INT16

//Structure to contain the full network
typedef struct Graph{
    char* name;             //Name of the netural network
    Layer *layers;          //Pointer to array of layers for the network
    uint16_t numLayers;     //Counter for the number of layers in a network
} Graph;

int16_t* forward(const Graph* model, const int16_t* data);
#endif

Graph* create_graph();

void destroy_graph(Graph* model);

int8_t add_layer(Graph* model, Layer l);

void graph_summarize(const Graph* model);

#endif