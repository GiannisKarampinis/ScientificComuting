# Non Linear Systems

## What's included?

### 1_FixedPointIterationMethod.c: Fixed-Point Iteration Method for Solving Nonlinear Equations

The system of nonlinear equations to be solved is:

$$ x_1^2 - 10x_1 + x_2^2 + 8 = 0 $$
$$ x_1 x_2^2 + x_1 - 10x_2 + 8 = 0 $$

The goal is to find the values of $x_1$ and $x_2$ that satisfy both equations simultaneously.
The initial guess is $x^{(0)} = [0.1,0.1]^T$

<br>
# Robotic Arm Kinematics

## 2_NewtonRaphson_RoboticArm.c: Newton Method

A robotic arm moves in the $xOy$ plane, anchored at the origin of the coordinate system. It consists of two rigid rods connected at a joint $A$. The position of the free end $B(x, y)$ of the arm is determined by the lengths of the rods $l_1 = 2$ and $l_2 = 5$, and the angles $\theta_1$ and $\theta_2$.

Given the lengths of the rods $l_1 = 2$ and $l_2 = 5$, and the desired position of the free end $B$ at $(1, 6)$, we need to find the values of angles $\theta_1$ and $\theta_2$ such that the robotic arm positions its free end accurately.

## Solution Approach

To solve this problem, we use the laws of robotic arm kinematics, specifically the equations derived from the cosine rule and trigonometric relationships:

<div style="text-align:center;">
    <img src="../Resources/RoboticArm.png" alt="Robotic Arm Image">
</div>

$$ x_A = l_1\cos(\theta_1) = 2\cos(\theta_1) $$
$$ y_A = l_1\sin(\theta_1) = 2\sin(\theta_1) $$

Point B has coordinates:

$$ x = l1\cos(\theta_1) + l2\cos(\theta_2) = 2\cos(theta_1) + 5\cos(\theta_2) $$
$$ y = l1\sin(\theta_1) + l2\sin(\theta_2) = 2\sin(theta_1) + 5\sin(\theta_2) $$

### See Cramer's Rule below to understand what is the method used to solve the linear system.

<br>
<br>

# Newton's Method and Cramer's Rule

## Overview

This document explains the use of Newton's method and Cramer's Rule for solving a system of nonlinear equations. Specifically, it includes an example in C code where these methods are applied, and a trick for Newton's method to avoid matrix inversion.

## Newton's Method Without Matrix Inversion

Newton's method is an iterative method for finding successively better approximations to the roots (or zeroes) of a real-valued function. For a system of nonlinear equations, it can be expressed as:

$$
\mathbf{F}(\mathbf{x}) = \begin{pmatrix}
f_1(x_1, x_2, \ldots, x_n) \\
f_2(x_1, x_2, \ldots, x_n) \\
\vdots \\
f_n(x_1, x_2, \ldots, x_n)
\end{pmatrix} = \mathbf{0}
$$

Given an initial guess $\mathbf{x}^{(0)}$, Newton's method updates this guess using the formula:

$$
\mathbf{x}^{(k+1)} = \mathbf{x}^{(k)} - J^{-1}(\mathbf{x}^{(k)}) \mathbf{F}(\mathbf{x}^{(k)})
$$

where $J$ is the Jacobian matrix of $\mathbf{F}$.

### Trick for Avoiding Matrix Inversion

To avoid directly inverting the Jacobian matrix, we solve the linear system using Cramer's Rule. This involves computing the determinant of the Jacobian matrix and the determinants of matrices formed by replacing columns of the Jacobian with the negative equations vector.

## Cramer's Rule

Cramer's Rule provides a method for solving a system of linear equations using determinants. Consider the system of linear equations:

$$
\begin{cases}
a_{11} x_1 + a_{12} x_2 = b_1 \\
a_{21} x_1 + a_{22} x_2 = b_2
\end{cases}
$$

This can be written in matrix form as:

$$
A \mathbf{x} = \mathbf{b}
$$

where

$$
A = \begin{pmatrix}
a_{11} & a_{12} \\
a_{21} & a_{22}
\end{pmatrix}, \quad
\mathbf{x} = \begin{pmatrix}
x_1 \\
x_2
\end{pmatrix}, \quad
\mathbf{b} = \begin{pmatrix}
b_1 \\
b_2
\end{pmatrix}
$$

### Determinant of the Coefficient Matrix

First, compute the determinant of the coefficient matrix $A$:

$$
\text{det}(A) = a_{11} a_{22} - a_{12} a_{21}
$$

### Determinants for the Numerators

To find $x_1$ and $x_2$ using Cramer's Rule, replace the corresponding column in $A$ with the vector $\mathbf{b}$ and compute the determinants of these new matrices.

For $x_1$:

$$
A_{x_1} = \begin{pmatrix}
b_1 & a_{12} \\
b_2 & a_{22}
\end{pmatrix}
$$

The determinant of $A_{x_1}$ is:

$$
\text{det}(A_{x_1}) = b_1 a_{22} - a_{12} b_2
$$

For $x_2$:

$$
A_{x_2} = \begin{pmatrix}
a_{11} & b_1 \\
a_{21} & b_2
\end{pmatrix}
$$

The determinant of $A_{x_2}$ is:

$$
\text{det}(A_{x_2}) = a_{11} b_2 - b_1 a_{21}
$$

### Solutions Using Cramer's Rule

Now, using Cramer's Rule, the solutions for $x_1$ and $x_2$ are:

$$
x_1 = \frac{\text{det}(A_{x_1})}{\text{det}(A)}, \quad x_2 = \frac{\text{det}(A_{x_2})}{\text{det}(A)}
$$

## Application in the C Code

In the provided C code, the Jacobian matrix $J$ is analogous to the coefficient matrix $A$ in the linear system. The right-hand side vector $\mathbf{b}$ consists of the negative values of the equations $eq1$ and $eq2$.

So for the specific example:

$$
J = \begin{pmatrix}
J_{11} & J_{12} \\
J_{21} & J_{22}
\end{pmatrix}, \quad
\mathbf{b} = \begin{pmatrix}
eq1 \\
eq2
\end{pmatrix}
$$

The determinant of $J$ is:

$$
\text{det}(J) = J_{11} J_{22} - J_{12} J_{21}
$$

Using Cramer's Rule:

$$
\Delta x_1 = \frac{eq1 \cdot J_{22} - eq2 \cdot J_{12}}{\text{det}(J)}, \quad \Delta x_2 = \frac{eq2 \cdot J_{11} - eq1 \cdot J_{21}}{\text{det}(J)}
$$

These values are used to update the current guesses $x_1$ and $x_2$ in each iteration of Newton's method. Here, $\Delta x_1$ and $\Delta x_2$ are the corrections to the current guesses $x_1$ and $x_2$.

## Summary

Cramer's Rule provides a straightforward way to solve a system of linear equations using determinants. In the provided code, it helps solve the linear system derived from the Jacobian matrix and the equations, allowing Newton's method to iteratively find the roots of the nonlinear system.

<br>
<br>
<br>

# Intersecting Circles

## Problem Description

Given two circles defined by the following equations:

$$ x_1^2 + x_2^2 = 16 $$
$$ x_1^2 + x_2^2 - 4x_2 - 5 = 0 $$

The goal is to find the points of intersection of these two circles using Newton's method.

## Equations

1. The first circle has a radius of 4 units and is centered at the origin (0, 0):
   $$ x_1^2 + x_2^2 = 16 $$

2. The second circle is translated vertically and has a modified radius:
   $$ x_1^2 + x_2^2 - 4x_2 - 5 = 0 $$

## Approach

- **Define the system of equations**: Create functions that represent the system of equations.
- **Compute the Jacobian matrix**: Create functions to calculate the partial derivatives of the system, forming the Jacobian matrix.
- **Newton's Method**: Implement Newton's method to iteratively solve for \( x_1 \) and \( x_2 \) using the Jacobian matrix and the system of equations.
- **Initial Guesses**: Start with initial guesses for \( x_1 \) and \( x_2 \). These guesses are important for the convergence of the method.
- **Convergence**: Determine the solution by iterating until the changes in \( x_1 \) and \( x_2 \) are smaller than a specified tolerance.

## Requirements

- Define the equations and Jacobian matrix functions.
- Implement Newton's method to find the roots.
- Use a specified tolerance for convergence and set a maximum number of iterations to prevent infinite loops.
- Check for the determinant of the Jacobian matrix to avoid division by zero.
- Print the results of \( x_1 \) and \( x_2 \).

## Example Solution

The provided C code implements the above approach to solve for the intersection points of the given circles.
