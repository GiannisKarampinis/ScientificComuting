#include <stdio.h>
#include <math.h>

// Define M_PI if not already defined (some compilers might not have it in math.h)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define TOLERANCE 1e-6  // Tolerance for convergence
#define MAX_ITERATIONS 1000  // Maximum number of iterations

// Function to calculate the equations that define the system
void equations(double l1, double l2, double x, double y, double theta1, double theta2, double *eq1, double *eq2) {
    *eq1 = l1 * cos(theta1) + l2 * cos(theta2) - x;
    *eq2 = l1 * sin(theta1) + l2 * sin(theta2) - y;
}

// Function to calculate the Jacobian matrix of the system
void jacobian(double l1, double l2, double theta1, double theta2, double *J11, double *J12, double *J21, double *J22) {
    *J11 = -l1 * sin(theta1);
    *J12 = -l2 * sin(theta2);
    *J21 = l1 * cos(theta1);
    *J22 = l2 * cos(theta2);
}

// Function to perform Newton's method without matrix inversion
void newton_method(double l1, double l2, double x, double y, double *theta1, double *theta2) {
    int i;
    double eq1, eq2, J11, J12, J21, J22;
    double delta_theta1, delta_theta2;

    // Initial guesses for theta1 and theta2
    double theta1_guess = 0.0;  // in radians
    double theta2_guess = M_PI / 2.0;  // in radians

    // Iterate using Newton's method
    for (i = 0; i < MAX_ITERATIONS; ++i) {
        // Calculate current equations and their Jacobian matrix
        equations(l1, l2, x, y, theta1_guess, theta2_guess, &eq1, &eq2);
        jacobian(l1, l2, theta1_guess, theta2_guess, &J11, &J12, &J21, &J22);

        // Solve the linear system using Newton's method without inverting the Jacobian
        double determinant = J11 * J22 - J12 * J21;
        if (fabs(determinant) < TOLERANCE) {
            printf("Jacobian determinant is close to zero. Exiting.\n");
            return;
        }

        delta_theta1 = (eq1 * J22 - eq2 * J12) / determinant;
        delta_theta2 = (eq2 * J11 - eq1 * J21) / determinant;

        // Update theta1 and theta2
        theta1_guess -= delta_theta1;
        theta2_guess -= delta_theta2;

        // Check for convergence
        if (fabs(delta_theta1) < TOLERANCE && fabs(delta_theta2) < TOLERANCE)
            break;
    }

    // Assign the final values
    *theta1 = theta1_guess;
    *theta2 = theta2_guess;
}

int main() {
    double  l1 = 2.0;  // Length of the first rod
    double  l2 = 5.0;  // Length of the second rod
    double  x = 1.0;   // Desired x-coordinate of point B
    double  y = 6.0;   // Desired y-coordinate of point B
    double  theta1, theta2;

    
    newton_method(l1, l2, x, y, &theta1, &theta2); // Solve using Newton's method

    if (isnan(theta1) || isnan(theta2)) { // Check for NaN (Not-a-Number) results
        printf("Failed to converge. Check initial guesses or system configuration.\n");
    } else {
        printf("Angles (in degrees):\n");
        printf("Theta1 (angle for first rod): %.6f degrees\n", theta1 * 180.0 / M_PI);
        printf("Theta2 (angle for second rod): %.6f degrees\n", theta2 * 180.0 / M_PI);
    }

    return 0;
}
