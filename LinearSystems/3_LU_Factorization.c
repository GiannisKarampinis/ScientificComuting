#include <stdio.h>

#define N 4

void printMatrix(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf\t", A[i][j]);
        }
        printf("\n");
    }
}

void luDecomposition(double A[N][N], double L[N][N], double U[N][N]) {
    // Initialize L as identity matrix and U as zero matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                L[i][j] = 1.0;
                U[i][j] = A[i][j];
            } else if (i < j) {
                L[i][j] = 0.0;
                U[i][j] = A[i][j];
            } else {
                L[i][j] = A[i][j];
                U[i][j] = 0.0;
            }
        }
    }

    // Perform LU decomposition
    for (int k = 0; k < N - 1; k++) {
        for (int i = k + 1; i < N; i++) {
            L[i][k] = U[i][k] / U[k][k];
            for (int j = k; j < N; j++) {
                U[i][j] = U[i][j] - L[i][k] * U[k][j];
            }
        }
    }
}

void forwardSubstitution(double L[N][N], double b[N], double y[N]) {
    // Solve Ly = b using forward substitution
    for (int i = 0; i < N; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
}

void backwardSubstitution(double U[N][N], double y[N], double x[N]) {
    // Solve Ux = y using backward substitution
    for (int i = N - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < N; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
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
    double L[N][N], U[N][N];
    double y[N], x[N];

    // Perform LU decomposition
    luDecomposition(A, L, U);

    // Print L and U matrices (optional)
    printf("Matrix L:\n");
    printMatrix(L);
    printf("Matrix U:\n");
    printMatrix(U);

    // Solve Ly = b
    forwardSubstitution(L, b, y);

    // Solve Ux = y
    backwardSubstitution(U, y, x);

    // Print solution vector x
    printf("\nSolution vector x:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %lf\n", i+1, x[i]);
    }

    return 0;
}
