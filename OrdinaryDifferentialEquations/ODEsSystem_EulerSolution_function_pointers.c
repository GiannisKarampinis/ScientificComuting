#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define N 2

typedef double (*f) (double, double, double);

double f1(double x, double y1, double y2) 
{
    return y1 - 2 * y2;
}

double f2(double x, double y1, double y2) 
{
    return -3 * y1 + y2;
}

int main()
{
    double      h = 0.1;
    double      target_x = 0.2;
    double      x = 0;
    f           f_array[N] = { f1, f2 };
    double      y[N] = { 1, 0 };

    while (x < target_x) {

        double y_old[N];
        memcpy(y_old, y, N * sizeof(double));

        y[0] = y_old[0] + h * f_array[0](x, y_old[0], y_old[1]);
        y[1] = y_old[1] + h * f_array[1](x, y_old[0], y_old[1]);
    
        printf("y1: %lf, y2: %lf\n", y[0], y[1]);
    
        x += h;
    }

    return 0;
}