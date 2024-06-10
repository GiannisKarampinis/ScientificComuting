#include <stdio.h>
#include <string.h>
#include <math.h>

#define N_ODE_EQS   12
#define M_A         1.1
#define M_B         0.907
#define G           39.47841760435743

typedef double (*ODE_FUNC) (double, double[]);

/* RUNGE-KUTTAs 4th Method */
double denom(double y[]) 
{
    double a = pow(y[0] - y[3], 2) + pow(y[1] - y[4], 2) + pow(y[2] - y[5], 2);
    double b = pow(a, 1.5);

    return b;
} /* denom */

void calc_f_arr(double f_arr[], double y[]) 
{
    double den = denom(y);

    f_arr[0] = y[6];
    f_arr[1] = y[7];
    f_arr[2] = y[8];
    f_arr[3] = y[9];
    f_arr[4] = y[10];
    f_arr[5] = y[11];
    f_arr[6] = - G * M_B * (y[0] - y[3]) / den;
    f_arr[7] = - G * M_B * (y[1] - y[4]) / den;
    f_arr[8] = - G * M_B * (y[2] - y[5]) / den;
    f_arr[9] = - G * M_A * (y[3] - y[0]) / den;
    f_arr[10] = - G * M_A * (y[4] - y[1]) / den;
    f_arr[11] = - G * M_A * (y[5] - y[2]) / den;
 
} /* calc_f_arr */

int main() 
{
    double      h = 0.01, target_t = 100, t = 0;
    double      y[N_ODE_EQS] = { 0, 11.29, 0, 0, -11.29, 0, 0.1, 0, 0.295, -0.061, 0, -0.362 };
    double      y_modified[N_ODE_EQS] = { 0 };
    int         i;
    double      f_array[N_ODE_EQS] = { 0 };

    while (t < target_t) {
        double      k1[N_ODE_EQS], k2[N_ODE_EQS], k3[N_ODE_EQS], k4[N_ODE_EQS];

        calc_f_arr(f_array, y);

        for (i = 0; i < N_ODE_EQS; i++) {
            k1[i] = h * f_array[i];
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            y_modified[i] = y[i] + 0.5 * k1[i];
        }

        calc_f_arr(f_array, y_modified);

        for (i = 0; i < N_ODE_EQS; i++) {
            k2[i] = h * f_array[i];
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            y_modified[i] = y[i] + 0.5 * k2[i];
        }

        calc_f_arr(f_array, y_modified);

        for (i = 0; i < N_ODE_EQS; i++) {
            k3[i] = h * f_array[i];
        }
 
        for (i = 0; i < N_ODE_EQS; i++) {
            y_modified[i] = y[i] + k3[i];
        }

        calc_f_arr(f_array, y_modified);

        for (i = 0; i < N_ODE_EQS; i++) {
            k4[i] = h * f_array[i];
        }
        
        for (i = 0; i < N_ODE_EQS; i++) {
            y[i] = y[i] + (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6;
        }
        
        t += h;
        
        printf("t: %lf, x_A: %lf, y_A: %lf, z_A: %lf, x_B: %lf, y_B: %lf, z_B: %lf\n", t, y[0], y[1], y[2], y[3], y[4], y[5]);
    }

    return 0;
}
