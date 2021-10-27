#include <SNN_Config.h>
#include <Activations.h>

typedef struct Node {
    uint8_t *weights;
    uint8_t value;
};