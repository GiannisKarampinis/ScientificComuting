#include <stdio.h>
#include <math.h>

#define N 4

void printMatrix(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.6f\t", A[i][j]);
        }
        printf("\n");
    }
}

void choleskyDecomposition(double A[N][N], double L[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            if (i == j) {
                for (int k = 0; k < j; k++) {
                    sum += L[j][k] * L[j][k];
                }
                double temp = A[j][j] - sum;
                if (temp <= 0) {
                    printf("Error: Matrix is not positive definite.\n");
                    return;
                }
                L[j][j] = sqrt(temp);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }
                if (L[j][j] == 0) {
                    printf("Error: Division by zero encountered.\n");
                    return;
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}


void forwardSubstitution(double L[N][N], double b[N], double y[N]) {
    for (int i = 0; i < N; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
}

void backwardSubstitution(double L[N][N], double y[N], double x[N]) {
    for (int i = N - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < N; j++) {
            x[i] -= L[j][i] * x[j];
        }
        x[i] /= L[i][i];
    }
}

int main() {
    double A[N][N] = {
        {5, 6, 0, 4},
        {6, 8, 3, 1},
        {0, 3, 9, -1},
        {4, 1, -1, 12}
    };

    double b[N] = {-9, 5, 7, 11};
    double L[N][N];
    double y[N], x[N];

    // Perform Cholesky decomposition
    choleskyDecomposition(A, L);

    // Print L matrix (optional)
    printf("Matrix L:\n");
    printMatrix(L);

    // Solve Ly = b
    forwardSubstitution(L, b, y);

    // Solve L^T x = y
    backwardSubstitution(L, y, x);

    // Print solution vector x
    printf("\nSolution vector x:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.6f\n", i+1, x[i]);
    }

    return 0;
}
