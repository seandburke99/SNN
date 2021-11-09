#include <SNN/SNN.h>
#include <SNN/Linalg.h>
#include <SNN/main.h>
#include <stdio.h>
#include <stdlib.h>

Graph *init_test(void);

int main(void){
    SNNFTYPE data[] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
    Graph *model = init_test();
    //graph_summarize(model);
    SNNFTYPE *ret = forward(model, data);
    for(int i=0;i<2;i++){
        printf("%f ", ret[i]);
    }
    printf("\n");
    free(ret);
    return 0;
}


Graph *init_test(void){
    Graph *model = create_graph();

    Layer l = create_layer();
    l.act = TanH;
    l.numDims = 2;
    l.dims = malloc(2*sizeof(size_t));
    l.dims[0] = 8;
    l.dims[1] = 10;
    l.weights = weight0;
    l.bias = bias0;
    add_layer(model, l);

    l = create_layer();
    l.act = TanH;
    l.numDims = 2;
    l.dims = malloc(2*sizeof(size_t));
    l.dims[0] = 10;
    l.dims[1] = 10;
    l.weights = weight1;
    l.bias = bias1;
    add_layer(model, l);

    l = create_layer();
    l.act = TanH;
    l.numDims = 2;
    l.dims = malloc(2*sizeof(size_t));
    l.dims[0] = 10;
    l.dims[1] = 2;
    l.weights = weight2;
    l.bias = bias2;
    add_layer(model, l);

    return model;
}