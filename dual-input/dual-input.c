#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// and gate
int data[4][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1}
    // in, in, out
};

/*
// or gate
int data[4][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
    // in, in, out
};
*/
#define size sizeof(data)/sizeof(data[0])
#define rand_float (float) rand() / (float) RAND_MAX 

float sigmoid (float x) {
    return 1.f / (1.f + expf(x));
}

/*
// can use this activation function to better model & gate?
float heaviside_step (float x) {
    return (x >= 0.5f) ? 1.f: 0.f;
}
*/

// y = w1*x1 + w1*x2 + b
float cost (float w1, float w2) {
    float mse = 0.0f;
    for (size_t i = 0; i < size; i++) {
        float x1 = data[i][0];
        float x2 = data[i][1];
        float y = sigmoid(x1*w1 + x2*w2);
        mse += pow((y - data[i][2]), 2);
    }
    mse /= size;
    return mse;
}

void printModel (float w1, float w2) {
    printf("\n--------------------------------------\n\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d | %d = %f (expected: %d)\n", data[i][0], data[i][1], sigmoid(data[i][0]*w1 + data[i][1]*w2), data[i][2]);
    }
}

int main (int argc, char *argv) {

    if (argc > 2) {fprintf(stderr, "Usage: ./main [(int) iterations]\n"); return 1;}
    int iterations = 50000;//atoi(&argv[1]);

    srand(69);
    float mu = 1e-1;
    float rate = 1e-1;
    float w1 = rand_float*10.0f;
    float w2 = rand_float*10.0f;

    for (size_t i = 0; i < iterations; i++) {
        float c = cost(w1, w2);
        printf("c: %f, w1: %f, w2: %f\n", c, w1, w2);
        float dw1 = (cost(w1 + mu, w2) - c)/mu;
        float dw2 = (cost(w1, w2 + mu) - c)/mu;
        w1 -= rate*dw1;
        w2 -= rate*dw2;
    }
    printModel(w1, w2);
    return 0;
}