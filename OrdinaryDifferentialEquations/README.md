# Ordinary Differential Equations (ODEs)

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

### 3_euler_method Cooling of an Iron Ball

### 4_rk_sphere Cooling of an Iron Ball

A steel ball with a temperature of 1200K is left to cool in air at an ambient temperature of 300K. Assuming heat loss occurs solely due to thermal radiation, the temperature of the ball follows the equation:

$$
 \frac{d\theta}{dt} = -2.2067 \times 10^{-12} \cdot (\theta^4 - 81 \times 10^8)
$$

where \( t \) is time in seconds and \( \theta \) is temperature in Kelvin. Find the temperature of the ball at time \( t = 480 \) seconds using the Euler's method and RK4 method.
