import numpy as np
import matplotlib.pyplot as plt

N_ODE_EQS = 12
M_A = 1.1
M_B = 0.907
G = 39.47841760435743

def denom(y):
    a = np.power(y[0] - y[3], 2) + np.power(y[1] - y[4], 2) + np.power(y[2] - y[5], 2)
    b = np.power(a, 1.5)
    return b

def calc_f_arr(y):
    # In complete accordance with y vector
    f_arr = np.zeros(N_ODE_EQS)
    den = denom(y)
    f_arr[0] = y[6]   # VAx
    f_arr[1] = y[7]   # VAy
    f_arr[2] = y[8]   # VAz
    f_arr[3] = y[9]   # VBx
    f_arr[4] = y[10]  # VBy
    f_arr[5] = y[11]  # VBz
    f_arr[6] = -G * M_B * (y[0] - y[3]) / den  # dVx_A/dt
    f_arr[7] = -G * M_B * (y[1] - y[4]) / den  # dVy_A/dt
    f_arr[8] = -G * M_B * (y[2] - y[5]) / den  # dVz_A/dt
    f_arr[9] = -G * M_A * (y[3] - y[0]) / den  # dVx_B/dt
    f_arr[10] = -G * M_A * (y[4] - y[1]) / den # dVy_B/dt
    f_arr[11] = -G * M_A * (y[5] - y[2]) / den # dVz_B/dt

    return f_arr

def runge_kutta_4th_order(y, h):

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


if __name__ == "__main__":        
    h           = 0.01
    target_t    = 100
    t           = 0
    y           = np.array([0, 11.29, 0, 0, -11.29, 0, 0.1, 0, 0.295, -0.061, 0, -0.362])

    positions_A = []
    positions_B = []

    print("Execution started...")
    while t < target_t:
        y = runge_kutta_4th_order(y, h)
        positions_A.append(y[:3].copy())  # Append x,y,z pos of Planet A
        positions_B.append(y[3:6].copy())  # Append x,y,z pos of Planet B
        # usage of copy() to pass by value, else it is passed by reference
        t += h

        print(f"Time: {t:.2f} - Planet A's Position: {y[:3]}, Planet B's Position: {y[3:6]}")

    print("Execution finished!")
    
    # Convert lists to numpy arrays for plotting
    positions_A = np.array(positions_A)
    positions_B = np.array(positions_B)

    # print(positions_A)
    
    X_A, Y_A, Z_A = positions_A[:, 0], positions_A[:, 1], positions_A[:, 2]
    X_B, Y_B, Z_B = positions_B[:, 0], positions_B[:, 1], positions_B[:, 2]

    fig = plt.figure(figsize=(10, 8))
    ax = plt.axes(projection ="3d")

    ax.scatter3D(X_A, Y_A, Z_A, label='Alpha Centauri A', color='blue')
    ax.scatter3D(X_B, Y_B, Z_B, label='Alpha Centauri B', color='red')

    # Set labels and title
    ax.set_xlabel('X (AU)')
    ax.set_ylabel('Y (AU)')
    ax.set_zlabel('Z (AU)')
    ax.set_title('Movement Trace of Planets A and B')
    ax.legend()

    # Show plot
    plt.show()
