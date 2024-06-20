#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

double maxNorm(double x1[], double x2[], int n) {
	double  maxVal = fabs(x1[0] - x2[0]), tmp;
	int     i;

	for (i = 1; i < n; i++) {	
		tmp = fabs(x1[i] - x2[i]);
		if (tmp > maxVal) {
			maxVal = tmp;
        }
	}

	return maxVal;

} /* maxNorm */

int userInpSystemSize(void)
{
    int     n;

    printf("Enter the system's size: ");
    scanf("%d", &n);

} /* userInpSystemSize */

int jacobiOverRelaxationSolver(const double *A, const double *B, const double *C, const double *D, double *x_old, double *x_new, int n, double omega)
{
    double      error = DBL_MAX, sum1, sum2;
    int         iters = 0, i;

    do {
        for (i = 0; i < n; i++) {
            sum1 = 0.0;
            sum2 = 0.0;
            
            sum1 = B[i] * x_new[i - 1];
            sum2 = C[i] + x_old[i + 1];
            
            x_new[i] = (1-omega) * x_old[i] + omega/A[i] * (D[i] - sum1 - sum2);
        }
        iters++;
        error = maxNorm(x_old, x_new, n);
        for (i = 0; i < n; i++) {
            x_old[i] = x_new[i];
        }

    } while (error > 0.0000001 && iters < 3000);

    return iters;

} /* jacobiOverRelaxationSolver */

int main()
{
    double      *A;
    double      *B;
    double      *C;
    double      *D;
    double      *x_old;
    double      *x_new;

    int         i, j, iters = 0, n;
    double      omega = 1, best_omega = 0.01, min_iters = INT_MAX;

    //n = userInpSystemSize();
    n = 5;

    A = (double *)calloc(n, sizeof(double));
    B = (double *)calloc(n, sizeof(double));
    C = (double *)calloc(n, sizeof(double));
    D = (double *)calloc(n, sizeof(double));

    x_old = (double *)calloc(n, sizeof(double));
    x_new = (double *)calloc(n, sizeof(double));

    for (i = 0; i < n; i++) {
        A[i] = 4;
        B[i] = -1;
        C[i] = -1;
        D[i] = 1;
    }

    B[0] = C[n-1] = 0.0;

    omega = 0.01;
    while (omega < 2) {
        for (i = 0; i < n; i++) {
            x_old[i] = 0.0;
            x_new[i] = 0.0;
        }
        iters = jacobiOverRelaxationSolver(A, B, C, D, x_old, x_new, n, omega);
        printf("\nomega: %lf Required number of iterations for convergence: %d\n",omega,iters);
        
        omega += 0.01;
    }

    iters = jacobiOverRelaxationSolver(A, B, C, D, x_old, x_new, n, 0.01f);
    printf("\nRequired number of iterations for convergence: %d\n",iters);

	printf("\nThe solution is: \n");
    for (i = 0; i < n; i++) {
        printf("\nx%d = %.10f\t", i, x_new[i]);    
    }

    free(A);
    free(B);
    free(C);
    free(D);
    free(x_old); 
    free(x_new);   
    
    return 0;
}