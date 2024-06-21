#include <stdio.h>

void transpose(double A[3][3], double A_transpose[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A_transpose[j][i] = A[i][j];
        }
    }
}

void printMatrix(double A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.1f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    double A[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    double A_transpose[3][3];

    // Print original matrix A
    printf("Original Matrix A:\n");
    printMatrix(A);

    // Compute transpose of matrix A
    transpose(A, A_transpose);

    // Print transposed matrix A_transpose
    printf("Transposed Matrix A_transpose:\n");
    printMatrix(A_transpose);

    return 0;
}
