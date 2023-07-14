#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dat[5][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}
//  {in, out}    
};

#define dat_size sizeof(dat)/sizeof(dat[0])
#define rand_float (float) rand() / (float) RAND_MAX 
/*
float rand_float(void) {
    return (float) rand() / (float) RAND_MAX;
}
*/


float cost (float w, float b) { // cost function accepts entire model as input, we want to minmize the cost function
    float err = 0.0f;
    for (size_t i = 0; i < dat_size; i++) {
        float x = dat[i][0]; // out input x
        float y = x*w + b;  // feed data into model and return output y
        //printf("actual: %f, expected %f\n", y, (float) dat[i][1]); // see results

        // compute MSE: MSE = (y-dat[i][1])^2
        err += pow((y - dat[i][1]), 2);
    }
    err /= dat_size; // divide sum by total to get mean square error, measure of how badly model performs. This is what we minimize.
    return err;
}

void print_model(float w) {
    for (size_t i = 0; i < dat_size; i++) {
        printf("{computed: %f, expected: %f, diff: %f}\n", dat[i][0]*w, (float) dat[i][1], (dat[i][0]*w)-((float) dat[i][1]));
    }
}

int main (int argc, char *argv[]) {

    if (argc > 2) {
        printf("[-] usage: ./main (integer)");
        return 1;
    }

    //char *iterc = argv[1];
    //int iterations = atoi(iterc);

    int iterations = atoi(argv[1]);

    printf("\n---- running model for %d iterations ----\n\n", iterations);

    // srand(time(0));
    srand(69);
    // y = x*w;
    float mu = 1e-3, rate = 1e-3;
    float w = rand_float()*10.0f; // the models single parameter
    float b = rand_float()*5.0f; // bias

    for (size_t i = 0; i < iterations; i++) {

        // COMPUTE OPTIMUM OF COST FUNCTION
        // change to actually compute true derivative instead of finite diff
        // what happens of cost function has multiple optimal solutions?
        float c = cost(w, b);
        float dcost = (cost(w + mu, b) - c)/mu;  // compute finite difference, change this to take actual derivative of cost func.
        float dbias = (cost(w, b + mu) - c)/mu;
        printf("cost: %f, w: %f, b: %f\n", c, w, b);
        //printf("[-] MSE pre opt: %f\n", cost(w)); // cost function before finite difference update (lim->0)
        w -= rate*dcost;
        b -= rate*dbias;
        //printf("[+] MSE: %f\n", cost(w)); // cost function after finite difference update
    }

    printf("---------------------------\n");
    printf("dcost: %f, dbias: %f\n", w, b);

    printf("---------------------------\n");
    print_model(w);

    return 0;

}