import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Constants
N_ODE_EQS = 12
M_A = 1.1
M_B = 0.907
G = 39.47841760435743  # Gravitational constant in AU^3/(yr^2*solar mass)

# Functions representing the system of ODEs
def denom(y):
    a = np.power(y[0] - y[3], 2) + np.power(y[1] - y[4], 2) + np.power(y[2] - y[5], 2)
    b = np.power(a, 1.5)
    return b

def calc_f_arr(y):
    f_arr = np.zeros(N_ODE_EQS)
    den = denom(y)
    f_arr[0] = y[6]
    f_arr[1] = y[7]
    f_arr[2] = y[8]
    f_arr[3] = -G * M_B * (y[0] - y[3]) / den
    f_arr[4] = -G * M_B * (y[1] - y[4]) / den
    f_arr[5] = -G * M_B * (y[2] - y[5]) / den
    f_arr[6] = y[9]
    f_arr[7] = y[10]
    f_arr[8] = y[11]
    f_arr[9] = -G * M_A * (y[3] - y[0]) / den
    f_arr[10] = -G * M_A * (y[4] - y[1]) / den
    f_arr[11] = -G * M_A * (y[5] - y[2]) / den
    return f_arr

# Runge-Kutta 4th Order Method
def runge_kutta_4th_order(y, h, t):
    k1 = np.zeros(N_ODE_EQS)
    k2 = np.zeros(N_ODE_EQS)
    k3 = np.zeros(N_ODE_EQS)
    k4 = np.zeros(N_ODE_EQS)
    y_modified = np.zeros(N_ODE_EQS)

    f_arr = calc_f_arr(y)

    for i in range(N_ODE_EQS):
        k1[i] = h * f_arr[i]

    for i in range(N_ODE_EQS):
        y_modified[i] = y[i] + 0.5 * k1[i]

    f_arr = calc_f_arr(y_modified)
    
    for i in range(N_ODE_EQS):
        k2[i] = h * f_arr[i]

    for i in range(N_ODE_EQS):
        y_modified[i] = y[i] + 0.5 * k2[i]

    f_arr = calc_f_arr(y_modified)

    for i in range(N_ODE_EQS):
        k3[i] = h * f_arr[i]

    for i in range(N_ODE_EQS):
        y_modified[i] = y[i] + k3[i]

    f_arr = calc_f_arr(y_modified)

    for i in range(N_ODE_EQS):
        k4[i] = h * f_arr[i]

    for i in range(N_ODE_EQS):
        y[i] = y[i] + (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6.0

    return y

# Initial conditions in AU and AU/yr
h = 0.01  # Time step in years
target_t = 100  # Total time in years
t = 0
y = np.array([0, 11.29, 0, 0, -11.29, 0, 0.1, 0, 0.295, -0.061, 0, -0.362])

# Lists to store results for plotting
positions_A = []
positions_B = []

# Main loop
print("Starting simulation...")
while t < target_t:
    y = runge_kutta_4th_order(y, h, t)
    positions_A.append(y[:3])  # Extracting (x, y, z) for Planet A
    positions_B.append(y[3:6])  # Extracting (x, y, z) for Planet B
    t += h

    if t % 1 == 0:  # Print progress every 1 unit of time
        print(f"Time: {t:.2f} - Planet A Position: {y[:3]}, Planet B Position: {y[3:6]}")

print("Simulation finished.")
print(f"Total points for Planet A: {len(positions_A)}, Total points for Planet B: {len(positions_B)}")

# Convert lists to numpy arrays for plotting
positions_A = np.array(positions_A)
positions_B = np.array(positions_B)

# Ensure the positions have been collected
print(f"Positions A: {positions_A[:5]}...")  # Print first 5 positions for verification
print(f"Positions B: {positions_B[:5]}...")

# Separate X, Y, Z coordinates
X_A, Y_A, Z_A = positions_A[:, 0], positions_A[:, 1], positions_A[:, 2]
X_B, Y_B, Z_B = positions_B[:, 0], positions_B[:, 1], positions_B[:, 2]

# Ensure we have valid data
print(f"X_A: {X_A[:5]}, Y_A: {Y_A[:5]}, Z_A: {Z_A[:5]}")
print(f"X_B: {X_B[:5]}, Y_B: {Y_B[:5]}, Z_B: {Z_B[:5]}")

# Plotting the movement trace in 3D
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Scatter plot for Planet A
ax.scatter(X_A, Y_A, Z_A, label='Planet A', s=1)

# Scatter plot for Planet B
ax.scatter(X_B, Y_B, Z_B, label='Planet B', s=1)

# Set labels and title
ax.set_xlabel('X (AU)')
ax.set_ylabel('Y (AU)')
ax.set_zlabel('Z (AU)')
ax.set_title('Movement Trace of Planets A and B')

# Set limits to zoom into a specific region
ax.set_xlim(-20, 20)
ax.set_ylim(-20, 20)
ax.set_zlim(-20, 20)

ax.legend()

# Show plot
plt.show()
