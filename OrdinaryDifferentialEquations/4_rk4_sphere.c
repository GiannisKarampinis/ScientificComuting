#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double t, double theta) {
    return -2.2067 * pow(10, -12) * (pow(theta, 4) - 81 * pow(10, 8));
}

int main()
{
    double  theta = 1200;
    double  h = 10, target_t = 480;
    double  t = 0.0;
    double  k1, k2, k3, k4;

    while (t <= target_t) {
        
        /* During the first iter, y is defined by the initial condition */
        printf("t: %lf, theta: %lf\n", t, theta);
        
        k1 = h * f(t, theta);
        k2 = h * f(t + h/2, theta + k1/2);
        k3 = h * f(t + h/2, theta + k2/2);
        k4 = h * f(t + h, theta + k3);

        theta = theta + (k1 + 2 * k2 + 2 * k3 + k4)/6;
        
        t += h;
    }

    return 0;
}