# Ordinary Differential Equations (ODEs)

## What's included?

### 1_euler_method: Problem Description

The differential equation is given by:

$$
y' = -y + x + 1, \quad 0 \leq x \leq 1
$$

The initial condition is:

$$
y(0) = 1
$$

Solve the above equation with Euler's method, assuming that $n = 10$. Calculate the error between the approximate and the analytical solution of the ODE, if the analytical solution of the ODE is:

$$
y(x) = x + e^{-x}
$$

### 2_euler_method: Problem Description

The differential equation is given by:

$$
y' = -y, \quad 0 \leq x \leq 1
$$

The initial condition is:

$$
y(0) = 1
$$

Solve the above equation with Euler's method, assuming that $n = 10$. Calculate the error between the approximate and the analytical solution of the ODE, if the analytical solution of the ODE is:

$$
y(x) = e^{-x}
$$

### 3_euler_method: Cooling of an Iron Ball

### 4_rk_sphere: Cooling of an Iron Ball

A steel ball with a temperature of 1200K is left to cool in air at an ambient temperature of 300K. Assuming heat loss occurs solely due to thermal radiation, the temperature of the ball follows the equation:

$$
 \frac{d\theta}{dt} = -2.2067 \times 10^{-12} \cdot (\theta^4 - 81 \times 10^8)
$$

where \( t \) is time in seconds and \( \theta \) is temperature in Kelvin. Find the temperature of the ball at time \( t = 480 \) seconds using the Euler's method and RK4 method.

### 5_ode_system_euler_function_pointers: System of Differential Equations

### 5_ode_system_euler_derivatives_array: System of Differential Equations

### 6_ode_system_RK4: System of Differential Equations

Consider the system:

$$
y_1' = y_1 - 2y_2, \quad y_1(0) = 1\\
y_2' = -3y_1 + y_2, \quad y_2(0) = 0
$$

Calculate the solution of the system at \( x = 0.2 \) using the Euler method with step size \( h = 0.1 \).
