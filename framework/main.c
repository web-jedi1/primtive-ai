#define NEURAL_IMPLEMENTATION
#include "neural.h"
#include <stdio.h>

int main (void) {
    Matrix m = matrix_alloc(2, 2);
    matrix_print(m);
    return 0;
}