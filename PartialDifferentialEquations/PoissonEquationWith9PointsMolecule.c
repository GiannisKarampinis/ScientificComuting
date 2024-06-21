#include <stdio.h>
#include <math.h>

int main()
{
    double  A[72][72] = { 0 };
    int     i, j;

    for (i = 0; i < 72; i++) {
        A[i][i] = (double)-10.0/3.0;
        A[i][i + 1] = (double)2.0/3.0;
        
        if (i >= 1) {
            A[i][i - 1] = (double)2.0/3.0;
        }

        
    }

    for (i = 0; i < 72; i++) {
        for (j = 0; j < 72; j++) {
            printf("%.1lf ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}