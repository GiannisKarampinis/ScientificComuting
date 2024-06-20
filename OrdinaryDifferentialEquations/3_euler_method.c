#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double t, double theta) {
    return -2.2067 * pow(10, -12) * (pow(theta, 4) - 81 * pow(10, 8));
}

int main()
{
    double  theta = 1200;
    double  h = 1, target_t = 480;
    double  t = 0.0;

    while (t <= target_t) {
        
        /* During the first iter, y is defined by the initial condition */
        printf("y_new: %lf\n", theta);
        
        t += h;
        theta = theta + h * f(t, theta);
    }

    return 0;
}
