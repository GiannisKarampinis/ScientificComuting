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
    double      k1[N], k2[N], k3[N], k4[N];
    double      y_modified[N] = { 0 };

    while (x < target_x) {
        int     i;

        derivatives(d, x, y);
        for (i = 0; i < N; i++) {
            k1[i] = h * d[i];
            y_modified[i] = y[i] + 0.5 * k1[i];
        }

        derivatives(d, x, y_modified);
        for (i = 0; i < N; i++) {
            k2[i] = h * d[i];
            y_modified[i] = y[i] + 0.5 * k2[i];
        }

        derivatives(d, x, y_modified);
        for (i = 0; i < N; i++) {
            k3[i] = h * d[i];
            y_modified[i] = y[i] + k3[i];
        }
 
        derivatives(d, x, y_modified);
        for (i = 0; i < N; i++) {
            k4[i] = h * d[i];
        }
        
        for (i = 0; i < N; i++) {
            y[i] = y[i] + (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6;
        }
        
        printf("y1: %lf, y2: %lf\n", y[0], y[1]);
    
        x += h;
    }

    return 0;
}