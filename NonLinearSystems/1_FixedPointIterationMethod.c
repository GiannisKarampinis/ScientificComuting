#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to calculate maximum norm between two vectors
double maxNorm(double x1[], double x2[], int n) {
    double maxVal = fabs(x1[0] - x2[0]);
    for (int i = 1; i < n; i++) {
        double tmp = fabs(x1[i] - x2[i]);
        if (tmp > maxVal) {
            maxVal = tmp;
        }
    }
    return maxVal;
}

int main()
{
    int     n = 2, iters = 0, maxIters = 100, i, j;
    double  x_old[2] = { 0.1, 0.1 };
    double  x_new[2] = { 0 };
    double  eps = 0.00001, error;

    do {
        x_new[0] = (x_old[0] * x_old[0] + x_old[1] * x_old[1] + 8) / 10;
        x_new[1] = (x_old[0] * x_old[1] * x_old[1] + x_old[0] + 8) / 10;

        error = maxNorm(x_new, x_old, n);
       
        memcpy(x_old, x_new, n * sizeof(double)); /* dest, source, size_t n*/

        iters++;

    } while (iters < maxIters && error > eps);
    
    printf("\nRequired number of iterations for convergence: %d\n", iters);

    printf("\nThe solution is: \n");
    for (i = 0; i < n; i++) {
        printf("\nx%d = %.10f\t", i, x_new[i]);    
    }    

    return 0;
}