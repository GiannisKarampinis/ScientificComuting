#include <stdio.h>
#include <math.h>

// Define M_PI if not already defined (some compilers might not have it in math.h)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define TOLERANCE 1e-6  // Tolerance for convergence
#define MAX_ITERATIONS 1000  // Maximum number of iterations

// Function to calculate the equations that define the system
void equations(double x1, double x2, double *eq1, double *eq2) {
    *eq1 = x1*x1 + x2*x2 - 16;
    *eq2 = x1*x1 + x2*x2 - 4*x2 - 5;
}

// Function to calculate the Jacobian matrix of the system
void jacobian(double x1, double x2, double *J11, double *J12, double *J21, double *J22) {
    *J11 = 2 * x1;
    *J12 = 2 * x2;
    *J21 = 2 * x1;
    *J22 = 2 * x2 - 4;
}

// Function to perform Newton's method without matrix inversion
void newton_method(double *x1, double *x2) {
    int     i;
    double  eq1, eq2, J11, J12, J21, J22;
    double  delta_x1, delta_x2;

    // Initial guesses for theta1 and theta2
    double  x1_guess = 3;  // or -3
    double  x2_guess = 4;  // or -4

    // Iterate using Newton's method
    for (i = 0; i < MAX_ITERATIONS; ++i) {
        // Calculate current equations and their Jacobian matrix
        equations(x1_guess, x2_guess, &eq1, &eq2);
        jacobian(x1_guess, x2_guess, &J11, &J12, &J21, &J22);

        // Solve the linear system using Newton's method without inverting the Jacobian
        double determinant = J11 * J22 - J12 * J21;
        if (fabs(determinant) < TOLERANCE) {
            printf("Jacobian determinant is close to zero. Exiting.\n");
            return;
        }

        delta_x1 = (eq1 * J22 - eq2 * J12) / determinant;
        delta_x2 = (eq2 * J11 - eq1 * J21) / determinant;

        // Update x1 and x2
        x1_guess -= delta_x1;
        x2_guess -= delta_x2;

        // Check for convergence
        if (fabs(delta_x1) < TOLERANCE && fabs(delta_x2) < TOLERANCE)
            break;
    }

    // Assign the final values
    *x1 = x1_guess;
    *x2 = x2_guess;
}

int main() {
    double  x1, x2;

    newton_method(&x1, &x2); // Solve using Newton's method

    if (isnan(x1) || isnan(x2)) { // Check for NaN (Not-a-Number) results
        printf("Failed to converge. Check initial guesses or system configuration.\n");
    } else {
        printf("x1 : %.6f\n", x1);
        printf("x2 : %.6f\n", x2);
    }

    
    {
        double eq1 = x1 * x1 + x2 * x2 - 16;
        double eq2 = x1 * x1 + x2 * x2 - 4 * x2 - 5;

        printf("\nValidation:\n");
        printf("Equation 1 (x1^2 + x2^2 - 16) = %.6f\n", eq1);
        printf("Equation 2 (x1^2 + x2^2 - 4*x2 - 5) = %.6f\n", eq2);
    }

    return 0;
}
