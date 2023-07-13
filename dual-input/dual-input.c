#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
// and gate
int data[4][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1}
    // in, in, out
}
*/

// or gate
int data[4][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
    // in, in, out
};

#define size sizeof(data)/sizeof(data[0])
#define rand_float (float) rand() / (float) RAND_MAX 

float sigmoid (float x) {
    return 1.f / (1.f + expf(x));
}

// y = w1*x1 + w1*x2 + b
float cost(float w1, float w2) {
    float result = 0.0f;
    for (size_t i = 0; i < size; i++) {
        float x1 = data[i][0];
        float x2 = data[i][1];
        float y = sigmoid(x1*w1 + x2*w2);
        // compute MSE
        float mse = pow((y - data[i][2]), 2)
    }
    result /= size;
    return result;
}



int main (int argc, char *argv) {

    srand(420);
    float w1 = rand_float()*10.0f;
    float w2 = rand_float()*10.0f;

    // compute model

    return 0;
}