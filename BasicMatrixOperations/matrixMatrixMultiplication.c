#include <stdio.h>
#include <omp.h>

#define     N   5000

int     a[N][N], b[N][N], c[N][N];
double  startTime, endTime;

int main()
{
    int     i, j, k;
    omp_set_num_threads(12);
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = 1;
            b[i][j] = 1;
            c[i][j] = 0;
        }
    }

    startTime = omp_get_wtime();
#pragma omp parallel for private(j,k)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    endTime = omp_get_wtime();

    printf("Execution time: %f\n", endTime - startTime);

   //  for (i = 0; i < N; i++)
   //      printf("a[%d]=%d\n", i, c[i]);
}