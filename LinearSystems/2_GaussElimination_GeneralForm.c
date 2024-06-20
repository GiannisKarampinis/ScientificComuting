#include <stdio.h>
#include <stdlib.h>

void gaussElimination(double** A, double* b, int n) {
    int i, j, k;
    // Forward Elimination
    for (i = 0; i < n; i++) {
        // Perform partial pivoting to avoid division by small numbers (or zero).
        for (k = i + 1; k < n; k++) {
            if (abs(A[i][i]) < abs(A[k][i])) {
                // Swap rows
                double* temp = A[i];
                A[i] = A[k];
                A[k] = temp;
                
                double t = b[i];
                b[i] = b[k];
                b[k] = t;
            }
        }
        // Make upper triangular
        for (k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }
    // Back Substitution
    double* x = (double*)malloc(n * sizeof(double));
    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] = x[i] / A[i][j];
    }
    // Print solution
    printf("Solution: \n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }
    free(x);
}

int main() {
    int n, i, j;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double** A = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
    }

    double* b = (double*)malloc(n * sizeof(double));

    printf("Enter the coefficients of the matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the constants vector b:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    gaussElimination(A, b, n);

    for (i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);

    return 0;
}
