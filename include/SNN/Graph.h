/*
 * File:  Graph.h 
 * --------------------
 * 
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

/*
 * Function:  TanH 
 * --------------------
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returs: None
 */
int16_t* forward(const Graph* model, const int16_t* data);
#endif

/*
 * Function:  TanH 
 * --------------------
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returs: None
 */
Graph* create_graph();

/*
 * Function:  TanH 
 * --------------------
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returs: None
 */
void destroy_graph(Graph* model);

/*
 * Function:  TanH 
 * --------------------
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returs: None
 */
int8_t add_layer(Graph* model, Layer l);

/*
 * Function:  TanH 
 * --------------------
 * Implements a modified TanH function on input data that scales the value to the positive
 * and negative max values of a 16 bit integer
 *
 * data: items to pass through the function
 * 
 * size: number of items to pass through the function
 *
 *  returs: None
 */
void graph_summarize(const Graph* model);

#endif