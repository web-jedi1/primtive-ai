#ifndef NEURAL_H_
#define NEURAL_H_

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    size_t rows;
    size_t collumns;
    float *elements;
} Matrix;

#define ITERATOR(m, i, j) m.elements[(i)*(m).collumns+(j)] // acts as indexer for matrix for iteration
#define random_float (float) rand() / (float) RAND_MAX

Matrix matrix_alloc (size_t rows, size_t collumns); // dynamically allocates memory for new matrix
void matrix_randomize(Matrix m);
void matrix_print (Matrix m);
void matrix_dotproduct (Matrix a, Matrix b, Matrix c); // computes dot product of two matrices
void matrix_sum (Matrix a, Matrix b); // computes sum of two matrices

float random_float (void);

#endif // NEURAL_H_

#ifdef NEURAL_IMPLEMENTATION
/*
float random_float (void) {
    // define range of random number (min, max) 
    return (float) rand() / (float) RAND_MAX;
}
*/

Matrix matrix_alloc (size_t rows, size_t collumns) {
    Matrix m;
    m.rows = rows;
    m.collumns = collumns;
    m.elements = malloc(sizeof(*m.elements)*rows*collumns); // allocate enough memory based on dimensions
    assert(m.elements != NULL); // make sure memory was allocated successfully
    return m;
}

void matrix_randomize (Matrix m) {
    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.collumns; j++) {
            ITERATOR(m, i, j) = random_float();    
        }
    }
}

void matrix_print (Matrix m) {
    /* 
    TODO: add index legend eg:

            [,0]  [,1]  [,2]  [,3]

    [0,]    [0,     0,     0,   0]
    [1,]    [0,     0,     0,   0]
    [2,]    [0,     0,     0,   0]
    [3,]    [0,     0,     0,   0]
    */

    for (size_t i = 0; i < m.rows; i++) {
        printf("[ ");
        for (size_t j = 0; j < m.collumns; j++) {
            if (j < m.collumns - 1) {
                printf("%f, ", ITERATOR(m, i, j));
            } else {
                printf("%f ", ITERATOR(m, i, j));
            }
            
        }
        printf("]\n");
    }
}

void matrix_dotproduct (Matrix a, Matrix b, Matrix c) {
    (void) a;
    (void) b;
    (void) c;
}

void matrix_sum (Matrix a, Matrix b) {
    /*adds matrix a to matrix b*/
    assert(a.collumns == b.collumns);
    assert(a.rows == b.rows);

    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.collumns; j++) {
            ITERATOR(b, i, j) += ITERATOR(a, i, j);    
        }
    }
}

#endif // NEURAL_IMPLEMENTATION