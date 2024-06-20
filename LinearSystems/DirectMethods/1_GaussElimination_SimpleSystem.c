#include<stdio.h>

int main()
{
    int         i, j, k, n=3;
    double      A[3][4] = {
                    {9,3,4,7},
                    {4,3,4,8},
                    {1,1,1,3} };
    double      c, x[3], sum = 0.0;

/*  printf("\nEnter the order of matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n + 1); j++)
        {
            printf("A[%d][%d] : ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    */  
   
    /* Construction of Upper Triangular Matrix*/
    for (j = 0; j <= n; j++) {
        for (i = j + 1; i < n; i++) {
            c = A[i][j] / A[j][j];
            for (k = 0; k <= n ; k++) {
                A[i][k] = A[i][k] - c * A[j][k];
            }
        }
    }
        
    /* Backward Substitution*/
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }
    printf("\nThe solution is: \n");
    for (i = 0; i < n; i++) {
        printf("\nx%d = %lf\t", i, x[i]);
    }
}
