## Matrix-Vector Multiplication

Matrix-vector multiplication is defined as follows:

Given:

- **Matrix \( A \)**: An \( m \times n \) matrix.
- **Vector \( x \)**: A column vector of size \( n \).

The resulting vector \( y \), where \( y = A \cdot x \), is computed as:
$$ y*i = \sum*{j=0}^{n-1} A\_{ij} \cdot x_j $$

### Practical Example

Consider the following matrix \( A \) and vector \( x \):

$$
A = \begin{pmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{pmatrix}, \quad x = \begin{pmatrix}
1 \\
2 \\
3
\end{pmatrix}
$$

To compute \( y = A \cdot x \):
$$ y_0 = 1 \cdot 1 + 2 \cdot 2 + 3 \cdot 3 = 14 $$
$$ y_1 = 4 \cdot 1 + 5 \cdot 2 + 6 \cdot 3 = 32 $$
$$ y_2 = 7 \cdot 1 + 8 \cdot 2 + 9 \cdot 3 = 50 $$

Therefore, \( y = \begin{pmatrix} 14 \\ 32 \\ 50 \end{pmatrix} \).

### Conclusion

Matrix-vector multiplication is a fundamental operation in linear algebra and computational mathematics. Understanding its computation and implementing efficient algorithms for it is crucial for various applications.

## Matrix-Matrix Multiplication

Given two matrices \( A \) and \( B \), their product \( C = A \times B \) is calculated as follows:

- Let $A$ be an $m \times n$ matrix.
- Let $B$ be an $n \times p$ matrix.
- The resulting matrix $C$ will be an $m \times p$ matrix.

The element $C[i][j]$ in the resulting matrix $C$ is computed by:

$$
C[i][j] = \sum_{k=0}^{n-1} A[i][k] \times B[k][j]
$$

## Practical Example

Consider the following matrices $A$ and $B$:

$$
A = \begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \end{bmatrix}
$$

(2x3 matrix)

$$
B = \begin{bmatrix} 7 & 8 \\ 9 & 10 \\ 11 & 12 \end{bmatrix}
$$

(3x2 matrix)

Their product $C = A \times B$ will be:

$$
C = \begin{bmatrix} (1 \cdot 7 + 2 \cdot 9 + 3 \cdot 11) & (1 \cdot 8 + 2 \cdot 10 + 3 \cdot 12) \\ (4 \cdot 7 + 5 \cdot 9 + 6 \cdot 11) & (4 \cdot 8 + 5 \cdot 10 + 6 \cdot 12) \end{bmatrix}
$$

Calculating the elements:

$$
C = \begin{bmatrix} 58 & 64 \\ 139 & 154 \end{bmatrix}
$$
