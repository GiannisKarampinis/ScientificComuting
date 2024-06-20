#include<stdio.h>
#include<math.h>


double maxNorm(double x1[], double x2[], int n) 
{
	double  maxVal = fabs(x1[0] - x2[0]);
	int     i;

	for (i = 1; i < n; i++ ) {	
		double  tmp = fabs(x1[i] - x2[i]);
		if(tmp > maxVal) {
			maxVal=tmp;
        }
	}

	return maxVal;
}

int main()
{
    int     i, j, k, iters = 0, maxIters = 100, n = 3;
    double A[3][3] = {
           { 2, -1,  0},
           {-1,  2, -1},
           { 0, -1,  2}
           }, b[3] = { 1, 0, 1 }, x_old[3] = { 0, 0, 0 }, x_new[3], sum = 0.0, eps = 0.0000001, error;
  
   	do{
   		for (i = 0; i < n; i++) {
   			sum = 0.0;
   			for (j = 0; j < n; j++) {
   				if (i != j) {
   					sum += A[i][j] * x_old[j];
                }
			}
			x_new[i] = 1 / A[i][i] * (b[i] - sum);
		}
		iters++;
		error = maxNorm(x_old, x_new, n);
		for (i = 0; i < n; i++) {
			x_old[i] = x_new[i];
        }
   	} while (error > eps && iters < maxIters);
   	
   	printf("\nRequired number of iterations for convergence: %d\n", iters);
   	
	printf("\nThe solution is: \n");
    for (i = 0; i < n; i++) {
        printf("\nx%d=%.10f\t", i, x_new[i]);    
    }    
}
