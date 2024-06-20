#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define N 2

typedef double (*f) (double, double, double);

void derivatives(double d[N], double x, double y[]) 
{ /* Generalization wih a function of derivatives */
    d[0] = y[0] - 2 * y[1];
    d[1] = -3 * y[0] + y[1];
}

int main()
{
    double      h = 0.1;
    double      target_x = 0.2;
    double      x = 0;
    double      d[N] = { 0 };
    double      y[N] = { 1, 0 };

    while (x < target_x) {

        int     i;
        double  y_old[N];
        
        memcpy(y_old, y, N * sizeof(double));

        derivatives(d, x, y_old);

        for (i = 0; i < N; i++) {
            y[i] = y_old[i] + h*d[i];
        }

        printf("y1: %lf, y2: %lf\n", y[0], y[1]);
    
        x += h;
    }

    return 0;
}