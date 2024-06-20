#include <stdio.h>

int main()
{
    double A[4] = { 4, 4, 4, 4 };
    double B[] = { 1, 1, 1, 1 }; /* One excessive element */
    double C[3] = { 2, 2, 2 };
    double D[4] = { 1, 1, 1, 1 };
    double X[4] = { 0 };

    int     i, j, k, n = 4;
    double  lambda;

    /* Create the upper triangular matrix */
    for (i = 1; i < n; i++) {
        lambda = B[i] / A[i - 1];
        B[i] = B[i] - lambda * A[i - 1];
        A[i] = A[i] - lambda * C[i - 1];
        D[i] = D[i] - lambda * D[i - 1];
    }

    for (i = 0; i < n; i++) {
        printf("B[%d] = %lf  ", i, B[i]);
    }

    /* Backward substitution */
    X[n - 1] = D[n - 1]/A[n - 1];
    for (i = n-2; i >= 0; i--) {
        X[i] = (D[i] - C[i] * X[i+1]) / A[i];
    }
    printf("\n");

    for (i = 0; i < n; i++) {
         printf("X[%d] = %lf  ", i, X[i]);
    }
}