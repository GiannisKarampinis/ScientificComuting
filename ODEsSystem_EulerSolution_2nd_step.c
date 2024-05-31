#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N_ODE_EQS 2

typedef double (*ODE_FUNC) (double, double, double);


/* EULERs METHOD */
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
    double      h = 0.1, target_x = 0.2, x = 0;
    double      y[N_ODE_EQS] = { 1, 0 };
    int         i;

    while (x < target_x) {
        /* Mporw na krathsw ola ta palia x kai afou ta exw na trexw mia loopa gia na ypologisw ta nea */
        double  y_old[N_ODE_EQS];

        memcpy(y_old, y, sizeof(double) * N_ODE_EQS);

        for (i = 0; i < N_ODE_EQS; i++) {
            y[i] = y_old[i] + h * f_array[i](x, y_old[0], y_old[1]);
        }
        
        printf("x: %lf, y1: %lf, y2: %lf\n", x, y[0], y[1]);

        x += h;
    }

    return 0;
}