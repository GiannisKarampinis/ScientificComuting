#include <stdio.h>

#define N 3

// Function to perform matrix-vector multiplication
void matrix_vector_multiply(int A[N][N], int x[N], int y[N]) {
    for (int i = 0; i < N; i++) {
        y[i] = 0;
        for (int j = 0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int x[N] = {1, 2, 3};
    int y[N] = {0}; // Result vector
    
    // Perform matrix-vector multiplication
    matrix_vector_multiply(A, x, y);
    
    // Output the result vector y
    printf("Result vector y:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", y[i]);
    }

    return 0;
}
