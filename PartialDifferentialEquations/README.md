# Partial Differential Equations - PDEs

## Theory

### General

$$
a \frac{\partial^2 u}{\partial x^2} + b \frac{\partial^2 u}{\partial x \partial y} + c \frac{\partial^2 u}{\partial y^2} + d \frac{\partial u}{\partial x} + e \frac{\partial u}{\partial y} + fu = g, \quad (x, y) \in \Omega
$$

where:

- $a, b, c, d, e, f$ are coefficients.
- $u$ is the unknown function.
- $g$ is a given function.
- $\Omega$ is the domain of the problem.

f-function is usually in the form:

- $f(x_1, x_2, x_3, ..., x_n)$
  This is actually a function of many variables, so it has no meaning to calculate the derivatives for all the variables. Usually we are referring to the rate of a particular variable so we have to calculate partial derivatives as per the variable of interest.

### Categories

Partial Differential Equations (PDEs) can be classified into three main types based on the form of the equation and the characteristics of their solutions. The classification depends on the nature of the eigenvalues of the coefficient matrix in the second-order terms of the PDE. The three main types are:

1. Elliptic PDEs, where $b^2 - ac < 0$
2. Parabolic PDEs, where $b^2 - ac = 0$
3. Hyperbolic PDEs, where $b^2 - ac > 0$

## Solution of a PDE

The analytical solution would lead to a $u(x, y)$ which satisfies the PDE, but in PDEs we are trying to approximate this $u(x, y)$ in some particular points. It is necessary to have the initial and/or boundary conditions which satisfy the solution. Initial conditions are utilized in problems with time dependency.

<br>
<br>

# Types of Partial Differential Equations (PDEs)

Partial Differential Equations (PDEs) can be classified into three main types based on their characteristics:

## 1. Elliptic PDEs

Elliptic PDEs are typically used to describe steady-state phenomena. They are characterized by the absence of real characteristic curves in the domain.

### Example:

The Laplace equation:

$$
\Delta u = \frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2} = 0
$$

The Poisson equation (Potential Equation):

$$
\Delta u = \frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2} = f(x, y)
$$

## 2. Parabolic PDEs

Parabolic PDEs describe phenomena with time evolution, such as heat diffusion.

### Example:

The heat equation:

$$
\frac{\partial u}{\partial t} = \alpha \left( \frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2} \right)
$$

## 3. Hyperbolic PDEs

Hyperbolic PDEs describe wave propagation and are characterized by real characteristic curves.

### Example:

The wave equation:

$$
\frac{\partial^2 u}{\partial t^2} = c^2 \left( \frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2} \right)
$$

<br>
<br>

# Boundary Conditions in Partial Differential Equations (PDEs)

Boundary conditions are essential for defining a well-posed problem in PDEs. The three main types of boundary conditions are:

## 1. Dirichlet Boundary Conditions

Dirichlet boundary conditions specify the value of the solution on the boundary of the domain.

### Example:

For a function $u(x, y)$, a Dirichlet boundary condition on the boundary $\partial \Omega$ might look like:

$$
u(x, y) = g(x, y) \quad \text{for} \quad (x, y) \in \partial \Omega
$$

## 2. Neumann Boundary Conditions

Neumann boundary conditions specify the value of the derivative (normal to the boundary) of the solution on the boundary of the domain.

### Example:

For a function $u(x, y)$, a Neumann boundary condition on the boundary $\partial \Omega$ might look like:

$$
\frac{\partial u}{\partial n} = h(x, y) \quad \text{for} \quad (x, y) \in \partial \Omega
$$

where $\frac{\partial u}{\partial n}$ denotes the normal derivative of $u$ at the boundary.

## 3. Robin Boundary Conditions

Robin boundary conditions are a weighted combination of Dirichlet and Neumann boundary conditions.

### Example:

For a function $u(x, y)$, a Robin boundary condition on the boundary $\partial \Omega$ might look like:
$a u + b \frac{\partial u}{\partial n} = c(x, y) \quad \text{for} \quad (x, y) \in \partial \Omega$
where $a$ and $b$ are constants, and $c(x, y)$ is a given function.

$$
$$
