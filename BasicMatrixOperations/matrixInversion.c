#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(double A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.6f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swapRows(double A[3][3], int i, int j) {
    for (int k = 0; k < 3; k++) {
        double temp = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = temp;
    }
}

void scaleRow(double A[3][3], int i, double scalar) {
    for (int k = 0; k < 3; k++) {
        A[i][k] *= scalar;
    }
}

void addRows(double A[3][3], int i, int j, double scalar) {
    for (int k = 0; k < 3; k++) {
        A[i][k] += scalar * A[j][k];
    }
}

int main() {
    double A[3][3] = {
        { 4.0, 3.0, 2.0 },
        { 1.0, 2.0, 3.0 },
        { 3.0, 1.0, 4.0 }
    };

    double A_inv[3][3] = {
        { 1.0, 0.0, 0.0 },
        { 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 1.0 }
    };

    // Print original matrix A
    printf("Original Matrix A:\n");
    printMatrix(A);

    // Perform Gaussian elimination with partial pivoting
    for (int i = 0; i < 3; i++) {
        // Partial pivoting: find pivot row
        int max_row = i;
        for (int k = i + 1; k < 3; k++) {
            if (fabs(A[k][i]) > fabs(A[max_row][i])) {
                max_row = k;
            }
        }
        if (max_row != i) {
            swapRows(A, i, max_row);
            swapRows(A_inv, i, max_row);
        }

        // Scale row to make pivot element 1
        double pivot = A[i][i];
        scaleRow(A, i, 1.0 / pivot);
        scaleRow(A_inv, i, 1.0 / pivot);

        // Eliminate elements below pivot
        for (int j = i + 1; j < 3; j++) {
            double factor = -A[j][i];
            addRows(A, j, i, factor);
            addRows(A_inv, j, i, factor);
        }
    }

    // Back substitution to make upper triangle into identity matrix
    for (int i = 2; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            double factor = -A[j][i];
            addRows(A_inv, j, i, factor);
        }
    }

    // Print inverted matrix A_inv
    printf("Inverse Matrix A_inv:\n");
    printMatrix(A_inv);

    return 0;
}
