#include <stdio.h>
#include <string.h>
#include <math.h>

#define N_ODE_EQS 12
#define M_A 1.1
#define M_B 0.907
#define G 39.47841760435743

typedef double (*ODE_FUNC) (double, double[]);

/* RUNGE-KUTTAs 4th Method */
double f1(double x, double y[]) {
    return y[6];
}

double f2(double x, double y[]) {
    return y[7];
}

double f3(double x, double y[]) {
    return y[8];
}

double f4(double x, double y[]) {
    double a = pow(y[0] - y[3], 2) + pow(y[1] - y[4], 2) + pow(y[2] - y[5], 2);
    double b = pow(a, 1.5);
    return -G * M_B * (y[0] - y[3]) / b;
}

double f5(double x, double y[]) {
    double a = pow(y[0] - y[3], 2) + pow(y[1] - y[4], 2) + pow(y[2] - y[5], 2);
    double b = pow(a, 1.5);
    return -G * M_B * (y[1] - y[4]) / b;
}

double f6(double x, double y[]) {
    double a = pow(y[0] - y[3], 2) + pow(y[1] - y[4], 2) + pow(y[2] - y[5], 2);
    double b = pow(a, 1.5);
    return -G * M_B * (y[2] - y[5]) / b;
}

double f7(double x, double y[]) {
    return y[9];
}

double f8(double x, double y[]) {
    return y[10];
}

double f9(double x, double y[]) {
    return y[11];
}

double f10(double x, double y[]) {
    double a = pow(y[0] - y[3], 2) + pow(y[1] - y[4], 2) + pow(y[2] - y[5], 2);
    double b = pow(a, 1.5);
    return -G * M_A * (y[3] - y[0]) / b;
}

double f11(double x, double y[]) {
    double a = pow(y[0] - y[3], 2) + pow(y[1] - y[4], 2) + pow(y[2] - y[5], 2);
    double b = pow(a, 1.5);
    return -G * M_A * (y[4] - y[1]) / b;
}

double f12(double x, double y[]) {
    double a = pow(y[0] - y[3], 2) + pow(y[1] - y[4], 2) + pow(y[2] - y[5], 2);
    double b = pow(a, 1.5);
    return -G * M_A * (y[5] - y[2]) / b;
}

/* Global Array which will hold the function pointers */
ODE_FUNC    f_array[N_ODE_EQS] = { f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12 };

int main() 
{
    double      h = 0.01, target_t = 100, t = 0;
    double      y[N_ODE_EQS] = { 0, 11.29, 0, 0, -11.29, 0, 0.1, 0, 0.295, -0.061, 0, -0.362 };
    double      y_modified[N_ODE_EQS] = { 0 };
    int         i;

    while (t < target_t) {
        double      k1[N_ODE_EQS], k2[N_ODE_EQS], k3[N_ODE_EQS], k4[N_ODE_EQS];
        double      y_old[N_ODE_EQS];

        memcpy(y_old, y, sizeof(double) * N_ODE_EQS);

        for (i = 0; i < N_ODE_EQS; i++) {
            k1[i] = h * f_array[i](t, y_old);
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            y_modified[i] = y_old[i] + 0.5 * k1[i];
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            k2[i] = h * f_array[i](t + h/2, y_modified);
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            y_modified[i] = y_old[i] + 0.5 * k2[i];
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            k3[i] = h * f_array[i](t + h/2, y_modified);
        }
 
        for (i = 0; i < N_ODE_EQS; i++) {
            y_modified[i] = y_old[i] + k3[i];
        }

        for (i = 0; i < N_ODE_EQS; i++) {
            k4[i] = h * f_array[i](t + h, y_modified);
        }
        
        for (i = 0; i < N_ODE_EQS; i++) {
            y[i] = y_old[i] + (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6;
        }
        
        printf("t: %lf, x_A: %lf, y_A: %lf, z_A: %lf, x_B: %lf, y_B: %lf, z_B: %lf\n", t, y[0], y[1], y[2], y[3], y[4], y[5]);

        t += h;
    }


    return 0;
}
