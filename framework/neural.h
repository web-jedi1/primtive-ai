#ifndef NEURAL_H_
#define NEURAL_H_

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct {
    size_t rows;
    size_t collumns;
    float *elements;
} Matrix;

Matrix matrix_alloc (size_t rows, size_t collumns); // dynamically allocates memory for new matrix
void matrix_print (Matrix m);
/* matrix operations return void, as otherwise returning new matric after operation may result in segfault*/
void matrix_dotproduct (Matrix a, Matrix b, Matrix c); // computes dot product of two matrices
void matrix_sum (Matrix a, Matrix b); // computes sum of two matrices

#endif // NEURAL_H_

#ifdef NEURAL_IMPLEMENTATION

Matrix matrix_alloc (size_t rows, size_t collumns) {
    Matrix m;
    m.rows = rows;
    m.collumns = collumns;
    m.elements = malloc(sizeof(*m.elements)*rows*collumns); // allocate enough memory based on dimensions
    assert(m.elements != NULL); // make sure memory was allocated successfully
    return m;
}

void matrix_print (Matrix m) {
    (void) m;
}

void matrix_dotproduct (Matrix a, Matrix b, Matrix c) {
    (void) a;
    (void) b;
    (void) c;
}
void matrix_sum (Matrix a, Matrix b) {
    (void) a;
    (void) b;
}

#endif // NEURAL_IMPLEMENTATION