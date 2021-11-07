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

/*
 * Forward function for a graph structure to feed data through
 * model: pointer to graph structure to feed data through
 * data: pointer to data to pass through graph structure
 *
 * returns: pointer to graph output
 */
SNNFTYPE* forward(const Graph* model, const SNNFTYPE* data);

/*
 * Function that creates a new graph structure and initializes
 * all graph data to 0 or NULL
 *
 * returns: pointer to new graph structure
 */
Graph* create_graph();

/*
 * Function to free all memory associated with a graph structure
 * model: pointer to model that needs to be freed
 *
 * returns: n/a
 */
void destroy_graph(Graph* model);

/*
 * Function to add a layer to a graph structure
 * model: pointer to graph structure to add the layer to
 * l: layer structure to 
 *
 * returns: 0 if successful, otherwise if not
 */
uint8_t add_layer(Graph* model, const Layer l);

/*
 * Function to print out full graph structure
 * model: pointer to graph to print out
 *
 * returns: n/a
 */
void graph_summarize(const Graph* model);

#endif