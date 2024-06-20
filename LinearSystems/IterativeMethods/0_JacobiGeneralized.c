#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

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

// Function to perform Jacobi iteration
void jacobiIteration(double A[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE], int n, double eps, int maxIters) {
    double x_old[MAX_SIZE], sum, error;
    int iters = 0;

    // Initialize x_old with initial guess (typically all zeros)
    for (int i = 0; i < n; i++) {
        x_old[i] = x[i];
    }

    do {
        for (int i = 0; i < n; i++) {
            sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x_old[j];
                }
            }
            x[i] = 1 / A[i][i] * (b[i] - sum);
        }
        iters++;
        error = maxNorm(x_old, x, n);
        // Update x_old with x for next iteration
        for (int i = 0; i < n; i++) {
            x_old[i] = x[i];
        }
    } while (error > eps && iters < maxIters);

    printf("\nRequired number of iterations for convergence: %d\n", iters);
    printf("\nThe solution is: \n");
    for (int i = 0; i < n; i++) {
        printf("x%d=%.10f\t", i, x[i]);    
    }
    printf("\n");
}

int main() {
    int n = 3; // Change this for different matrix sizes if needed
    double A[MAX_SIZE][MAX_SIZE] = {
           { 2, -1,  0},
           {-1,  2, -1},
           { 0, -1,  2}
           };
    double b[MAX_SIZE] = { 1, 0, 1 }; // Right-hand side vector
    double x[MAX_SIZE] = { 0, 0, 0 }; // Initial guess (can be adjusted)

    double eps = 0.0000001; // Convergence tolerance
    int maxIters = 100; // Maximum number of iterations

    // Call Jacobi iteration function
    jacobiIteration(A, b, x, n, eps, maxIters);

    return 0;
}
