# 1D Bar - Isogeometric Analysis
## Analysis - What happens under the hood?
The governing differential equation for the static structural problem of the 1D Bar is given by:

$$Δu(x) = -f(x)$$

where $Δ$ represents the Laplacian operator. This equation is well known as the Poisson's equation. 

By expanding the laplacian for the 1D Bar problem we end up with the following:

$$\frac{\partial ^ 2u(x)}{\partial x^2} = -f(x)$$

This is known as the "Strong form" of the poisson's equation. This equation can provide the exact solution for particular (finite) points inside the domain or for particular points at the boundaries, caclulated by solving the respective equations for the boundaries (they can be Dirichlet, Neumann or Robin). However, both the domain and boundaries are described by an infinite number of point and in between the selected/particular points for the exact solution of the strong form equations we will end up probably with oscillations, unveiling a huge drawback of the strong form methods. To provide a control between the selected points of the equations the Weak Formulation is recommended. As an example we could apply an averaging technique  between the particular points, which is somewhat the case in Finite Element Analysis (FEA) as well. We will not cover the whole derivation procedure for the Weak Formulation of the poisson's equation but the basic idea behind it is that we multiply the strong form by a test function (the so-called weight function) and integrate over the domain. The test functions are chosen specifically for each problem.

So, returning back to our methodology, to derive the weak formulation we multiply the strong form by a test function v(x) and integrate over the domain:

$$
\int_Ω  \frac{\partial ^ 2u(x)}{\partial x^2}v(x) dΩ = - \int_Ω f(x)v(x) dΩ
$$

By applying the integration by parts (Green's Theorem) to the left-hand side to move the derivative from $u(x)$ to the test function $v(x)$:

$$
\int_{a}^{b} \frac{\partial^2 u(x)}{\partial x^2} v(x) \, dx = \left[ \frac{\partial u(x)}{\partial x} v(x) \right]_{a}^{b} - \int_{a}^{b} \frac{\partial u(x)}{\partial x} \frac{\partial v(x)}{\partial x} \, dx
$$


$$
\int_{a}^{b} \frac{\partial^2 u(x)}{\partial x^2}v(x) dx = \left[ \frac{\partial u(x)}{\partial x} v(x) \right]_{a}^{b} - \int_{a}^{b} \frac{\partial u(x)}{\partial x} \frac{\partial v(x)}{\partial x} dx 
$$

Here the term $\left[ \frac{\partial u(x)}{\partial x} v(x) \right]_{a}^{b}$ is the boundary term evaluated at the boundaries of the domain a and b. For the domain $Ω = [0,1]$ this becomes:

$$
\left[ \frac{\partial u(x)}{\partial x} v(x) \right]_{0}^{1} - \int_{0}^{1} \frac{\partial u(x)}{\partial x} \frac{\partial v(x)}{\partial x} \, dx 
$$

Assuming Dirichlet boundary conditions, where $u(0) = u(1) = 0$ we also consider $v(0)=v(1)=0$. This simplifies the boundary term to zero because the test function v(x) is zero at the boundaries:

$$
\left[ \frac{\partial u(x)}{\partial x} v(x) \right]_{0}^{1} = 0
$$

Thus, the weak form of the equation reduces to:
$$
\int_{0}^{1} \frac{\partial u(x)}{\partial x} \frac{\partial v(x)}{\partial x} \, dx = \int_{0}^{1} f(x)v(x)\, dx
$$

### Handling Boundary Conditions
In the weak form, the boundary conditions are naturally incorporated through the choice of test functions. For Dirichlet boundary conditions, the test functions are chosen such that they are zero at the boundaries. This ensures that the boundary terms vanish, simplifying the formulation. For Neumann or Robin boundary conditions, the boundary term would not vanish and would need to be included in the weak form. The weak form provides a flexible and stable way to incorporate these conditions and solve the problem numerically.

> This can also be found as:
>$$
\int_Ω \nabla u(x) \nabla v(x) \, dΩ - \int_Ω \frac{\partial u}{\partial n} \, dΓ = \int_Ω f(x)v(x) \, dΩ
>$$
>Given that the boundary condition v(x) = 0 on ${\partial Ω}$:
>$$
\int_Ω \nabla u(x) \nabla v(x) \, dΩ = \int_Ω f(x)v(x) \, dΩ
>$$

## Discretization
In the context of the finite element method and isogeometric analysis, the choice of approximating the solution $u(x)$ and the test function $v(x)$ using a finite set of basis function NI(x) and NJ(x), respectively, is grounded in the method of weighted residuals and the principle of Galerkin's method.

## Weighted Residuals and Galerkin's Method
The primary goal in numerical methods for partial differential equations (PDEs) is to approximate the continuous solution $u(x)$ by a discrete function that satisfies the PDE in an average sense over the domain. This is achieved through the method of weighted residuals, where the residual (the error in satisfying the PDE) is minimized in an integral sense.

The idea behind the weighted residuals method is to convert the differential equation into an integral form where the residuals (errors) are weighted and forced to be zero over the domain. The residual $R(u)$ of the differential equation is given by:

$$
R(u) = - \frac{\partial^2u(x)}{\partial x^2} - f(x)
$$

To ensure that the residuals are minimized, we integrate the residual multiplied by a set of weighting functions $v(x)$ over the domain:
$$
\int_Ω R(u)v(x)\, dΩ = 0
$$

Galerkin's Method

Galerkin's method is a specific case of the weighted residuals method where the weighting functions are chosen to be the same as the basis functions used to approximate the solution. This means we use the basis functions Nj(x) as our weighting functions:
$$
\int_Ω (- \frac{\partial^2u(x)}{\partial x^2} - f(x))Nj(x)\, dΩ = 0
$$

We saw previously the technique for eliminating the second derivative by intergating by parts, thus by applying the same principle for the enclosed in parentheses term we end up with:

$$
\int_Ω \frac{\partial^2u(x)}{\partial x^2} Nj(x) dΩ = -\int_Ω \frac{\partial u(x)}{\partial x} \frac{\partial Νj(x)}{\partial x} dΩ
$$

Substituting this into the weighted residuals equation we get:
$$
\int_Ω \nabla u(x) \nabla Nj(x)\, dΩ = \int_Ω f(x)Nj(x)\, dΩ
$$

## Approximation using Basis Functions

Now, we approximate the solution u(x) as a linear combination of basis functions Ni(x)
$$
u(x) = \sum_{i=Ι} u(i)Ni(x) 
$$
and
$$
v(x) = NJ(x)
$$
ui: in case of Isogeometric Analysis this corresponds to the control points.

## Formulating the System of Equations
Substituting the approximation into the weak form, we get:
$$
\int_Ω  \nabla (\sum_{i=I} uiNi(x)) \nabla Nj(x) dΩ = \int_Ω f(x)Nj(x)dΩ
$$

By linearity of the integral and the dot product, this simplifies to:
$$
\sum_{i=I}ui \int_Ω \nabla ( Ni(x)) \nabla Nj(x) dΩ = \int_Ω f(x)Nj(x)dΩ
$$

This leads to a system of linear equations for the coefficients ui:
$$
\sum_{i=I}Kijui = Fj
$$
where
$$
Kij = \int_Ω \nabla Ni(x) \nabla Nj(x) dΩ
$$
$$
Fj = \int_Ω f(x)Nj(x)dΩ
$$

In matrix form we write: $Ku = F$.

---
## Problem Description

Consider a bar of Length L = 1 m, subjected to a uniform load $f(x) = 1$ unit per length. The bar is fixed at both ends with Dirichlet boundary conditions: $u(0) = u(1) = 0$. Solve the above problem using the Isogeometric Analysis with a discretization of 2 elements and B-Spline basis functions.

## Construct the basis functions

Knot vector:  
$$ξ = [0,0,0,0.5,1,1,1]$$
___
>For degree 0, the basis functions are defined as:
>$$
N_{i,0}(ξ) =
\begin{cases}
1 & \text{if } \xi_i \leq \xi < \xi_{i+1} \\
0 & \text{otherwise}
\end{cases}
>$$

For $ξ_0 = 0$ and $ξ_1 = 0$

$$
N_{0,0}(ξ) = 
\begin{cases}
1 & \text{if } 0 \leq \xi < 0 \\
0 & \text{otherwise}
\end{cases}
$$

So: $N_{0,0}(ξ) = 0$



For $ξ_1 = 0$ and $ξ_2 = 0$

$$
N_{1,0}(ξ) = 
\begin{cases}
1 & \text{if } 0 \leq \xi < 0 \\
0 & \text{otherwise}
\end{cases}
$$
So: $N_{1,0}(ξ) = 0$



For $ξ_2 = 0$ and $ξ_3 = 0.5$

$$
N_{2,0}(ξ) = 
\begin{cases}
1 & \text{if } 0 \leq \xi < 0.5 \\
0 & \text{otherwise}
\end{cases}
$$




For $ξ_3 = 0.5$ and $ξ_4 = 1$

$$
N_{3,0}(ξ) = 
\begin{cases}
1 & \text{if } 0.5 \leq \xi < 1 \\
0 & \text{otherwise}
\end{cases}
$$


For $ξ_4 = 1$ and $ξ_5 = 1$

$$
N_{4,0}(ξ) = 
\begin{cases}
1 & \text{if } 1 \leq \xi < 1 \\
0 & \text{otherwise}
\end{cases}
$$
So: $N_{4,0}(ξ) = 0$


For $ξ_5 = 1$ and $ξ_6 = 1$

$$
N_{5,0}(ξ) = 
\begin{cases}
1 & \text{if } 1 \leq \xi < 1 \\
0 & \text{otherwise}
\end{cases}
$$
So: $N_{5,0}(ξ) = 0$

___
>For degree 1, the basis functions are defined as:
>$$
N_{i,1}(ξ) = \frac{ξ - ξ_i}{ξ_{i+i} - ξ_{i}} Ν_{i,0}(ξ) + \frac{ξ_{i+2} - ξ}{ξ_{i+2} - ξ_{i+1}}Ν_{i+1, 0}(ξ)
>$$

Calculate $N_{0,1}$ :

$ξ_{0} = 0$, $ξ_{1} = 0$, $ξ_{2} = 0$

$$
Ν_{0,1}(ξ) = \frac{ξ-ξ_0}{ξ_1-ξ_0}Ν_{0,0}(ξ) + \frac{ξ_2-ξ}{ξ_2-ξ_1}Ν_{1,0}(ξ)
$$

$$
Ν_{0,1}(ξ) = \frac{ξ-0}{0-0}0 + \frac{0-ξ}{0-0}0
$$

Since both terms involve division by zero, we define generally: $N_{0,1}(ξ) = 0$.


Calculate $N_{1,1}$ :

$ξ_{1} = 0$, $ξ_{2} = 0$, $ξ_{3} = 0.5$

$$
Ν_{1,1}(ξ) = \frac{ξ-ξ_1}{ξ_2-ξ_1}Ν_{1,0}(ξ) + \frac{ξ_3-ξ}{ξ_3-ξ_2}Ν_{2,0}(ξ)
$$

$$
Ν_{1,1}(ξ) = \frac{ξ-0}{0-0}0 + \frac{0.5-ξ}{0.5-0}Ν_{2,0}(ξ)
$$

$$
Ν_{1,1}(ξ) = \frac{0.5-ξ}{0.5}Ν_{2,0}(ξ)
$$

$$
Ν_{1,1}(ξ) = (1-2ξ)Ν_{2,0}(ξ)
$$

By substituting $N_{2,0}$ from above:

$$
N_{1,1}(ξ) = 
\begin{cases}
1 - 2ξ & \text{if } 0 \leq \xi < 0.5 \\
0 & \text{otherwise}
\end{cases}
$$

Calculate $N_{2,1}$ :

$ξ_{1} = 0$, $ξ_{2} = 0.5$, $ξ_{3} = 1$

$$
Ν_{2,1}(ξ) = \frac{ξ-ξ_2}{ξ_3-ξ_2}Ν_{2,0}(ξ) + \frac{ξ_4-ξ}{ξ_4-ξ_3}Ν_{3,0}(ξ)
$$

$$
Ν_{2,1}(ξ) = \frac{ξ-0}{0.5-0}N_{2,0}(ξ) + \frac{1-ξ}{1-0.5}Ν_{3,0}(ξ)
$$

$$
Ν_{2,1}(ξ) = 2ξ Ν_{2,0}(ξ) +(2-2ξ)Ν_{3,0}(ξ) 
$$

By substituting $N_{2,0}$ and $N_{3,0}$ from above:

$$
N_{2,1}(ξ) = 
\begin{cases}
2ξ & \text{if } 0 \leq \xi < 0.5 \\
2-2ξ & \text{if } 0.5 \leq \xi < 1 \\
0 & otherwise
\end{cases}
$$
