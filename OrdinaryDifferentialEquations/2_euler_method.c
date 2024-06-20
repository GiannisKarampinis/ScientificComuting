#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x, double y) {
    return -y;
}

double f_analytical(double x) {
    return exp(-x);
}

int main()
{
    double  y = 1, y_analytical = 0;
    double  h = 0.2, target_x = 1;
    double  x = 0.0, error = 0;

    while (x <= target_x) {
        y_analytical = f_analytical(x);
        error = fabs(y - y_analytical);
        
        /* During the first iter, y is defined by the initial condition */
        printf("y_new: %lf, y_analytical: %lf, error: %lf\n", y, y_analytical, error);
        
        x += h;
        y = y + h * f(x, y);
    }

    return 0;
}
