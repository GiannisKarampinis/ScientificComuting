#include <stdio.h>
#include <string.h>

#define N_ODE_EQS 2



typedef double (*ODE_FUNC) (double, double, double);

/* RUNGE-KUTTAs 4th Method */
double f1(double x, double y1, double y2) {
    return y1 - 2 * y2;
}

double f2(double x, double y1, double y2) {
    return -3 * y1 + y2;
}

/* Global Array which will hold the function pointers */
ODE_FUNC    f_array[N_ODE_EQS] = { f1, f2 };

int main() 
{
    double      h = 0.001, target_x = 0.2, x = 0;
    double      y[N_ODE_EQS] = { 1, 0 };
    int         i;

    while (x < target_x) {
        double      k1[N_ODE_EQS], k2[N_ODE_EQS], k3[N_ODE_EQS], k4[N_ODE_EQS];
        double      y_old[N_ODE_EQS];

        memcpy(y_old, y, sizeof(double) * N_ODE_EQS);

        for (i = 0; i < N_ODE_EQS; i++) {
            k1[i] = h * f_array[i](x, y_old[0], y_old[1]);
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            k2[i] = h * f_array[i](x + h/2, y_old[0] + 0.5 * k1[0], y_old[1] + 0.5 * k1[1]);
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            k3[i] = h * f_array[i](x + h/2, y_old[0] + 0.5 * k2[0], y_old[1] + 0.5 * k2[1]);
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            k4[i] = h * f_array[i](x + h, y_old[0] + k3[0], y_old[1] + k3[1]);
        }
        
        for (i = 0; i < N_ODE_EQS; i++) {
            y[i] = y_old[i] + (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6;
        }
        
       printf("x: %lf, y1: %lf, y2: %lf\n", x, y[0], y[1]);

        x += h;
    }


    return 0;
}
