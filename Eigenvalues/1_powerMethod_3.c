#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double A[5][5] = {
        { 0, 1, 0, 0, 0 },
        { 1, 0, 1, 1, 1 },
        { 0, 1, 0, 0, 1 },
        { 0, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 0 }
    };
    
    double x[5] = { 0, 0, 0, 0, 0 }, x_old[5] = { 1, 1, 1, 0, 0 }, y[5];
    double error = 1.0, eps = 0.0001, maxValue;
    int i, j, maxIters = 1000, iters = 0, n = 5;  // Note: n should be 5 to match the size of A
    
    do {
        // Multiplication A*x_old
        for (i = 0; i < n; i++) {
            y[i] = 0.0;
            for (j = 0; j < n; j++) {
                y[i] += A[i][j] * x_old[j];
            }
        }
        
        // Compute max norm of vector y
        maxValue = fabs(y[0]);
        for (i = 1; i < n; i++) {
            if (maxValue < fabs(y[i])) {
                maxValue = fabs(y[i]);
            }
        }
        
        // Normalize vector y and store it in x
        for (i = 0; i < n; i++) {
            x[i] = y[i] / maxValue;
        }
        
        // Compute error
        error = fabs(x[0] - x_old[0]);
        for (i = 1; i < n; i++) {
            if (error < fabs(x[i] - x_old[i])) {
                error = fabs(x[i] - x_old[i]);
            }
        }
        
        // Update vector x_old
        for (i = 0; i < n; i++) {
            x_old[i] = x[i];
        }
        
        iters++;
        printf("Iteration: %d, approximate eigenvalue: %.10f\n", iters, maxValue);
    } while (iters < maxIters && error >= eps);
    
    printf("Converged after %d iterations.\n", iters);
    printf("Largest eigenvalue: %.10f\n", maxValue);
    printf("Corresponding eigenvector:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.10f\n", i, x[i]);
    }
    
    return 0;
}
