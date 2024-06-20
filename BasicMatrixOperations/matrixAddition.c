#include <stdio.h>
#include <omp.h>

#define N 20

int a[N], b[N], c[N];
double startTime, endTime;

int main()
{
    int     i;
    int     no_procs = omp_get_num_procs();
    omp_set_num_threads(1);


    printf("Available processors: %d\n", no_procs);
    for (i = 0; i < N; i++)
    {
        b[i] = 1;
        c[i] = 1;
    }
    startTime = omp_get_wtime();
#pragma omp parallel for
    for (i = 0; i < N; i++) {
        a[i] = b[i] + c[i];
    }
    endTime = omp_get_wtime();

    printf("Execution time: %f\n", endTime-startTime);

    for (i = 0; i < N; i++)
        printf("a[%d]=%d\n", i, a[i]);
}