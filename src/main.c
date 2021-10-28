#include <SNN/Graph.h>
#include <SNN/Activations.h>
#include <stdio.h>
#include <stdlib.h>

void init_layers(Graph* model);

int main(void){
    Graph NN = create_graph();
    init_layers(&NN);
    printf("Layers Created\n");
    graph_summarize(&NN);
    int16_t data[] = {32767, 32767, 32767, 32767};
    forward(&NN, data);
    printf("Data was passed through\n");
    for(int i=0;i<2;i++){
        printf("%hd ", data[i]);
    }
    printf("\n");
    destroy_graph(&NN);
    return 0;
}

void init_layers(Graph* model){
    model->name = malloc(3);
    model->name = "AC\0";


    Layer l = create_layer();

    l.name = malloc(7);
    l.name = "Input\0";    
    l.numDims = 2;
    l.dims = malloc(sizeof(int16_t)*l.numDims);
    l.dims[0] = 4;
    l.dims[1] = 4;
    l.weights = NULL;
    add_layer(model, l);
    free(l.dims);

    l = create_layer();
    l.name = malloc(8);
    l.name = "Hidden\0";
    l.numDims = 2;
    l.dims = malloc(sizeof(int16_t)*l.numDims);
    l.dims[0] = 4;
    l.dims[1] = 16;
    l.weights = NULL;
    add_layer(model, l);
    free(l.dims);

    l = create_layer();
    l.name = malloc(8);
    l.name = "Output\0";
    l.numDims = 2;
    l.dims = malloc(sizeof(int16_t)*l.numDims);
    l.dims[0] = 16;
    l.dims[1] = 2;
    l.weights = NULL;
    add_layer(model, l);
    free(l.dims);
    return;
}