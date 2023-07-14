#define NEURAL_IMPLEMENTATION
#include "neural.h"

int main (void) {
    Matrix m = matrix_alloc(8, 8);
    srand(time(0));
    matrix_randomize(m);
    matrix_print(m);
    //printf("%d", time(0));
    return 0;
}