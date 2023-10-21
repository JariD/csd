import numpy as np


#framework to make the ikeda attractor algorithm

# this function is a modified copy from chat-gpt
def ikeda_map_3D(u, x0, y0, z0, num_points):
    x, y, z = np.zeros(num_points), np.zeros(num_points), np.zeros(num_points)
    x[0], y[0], z[0] = x0, y0, z0
    
    for i in range(1, num_points):
        t = 0.4 - 6.0 / (1.0 + x[i-1]**2 + y[i-1]**2)
        x[i] = 1 + u * (x[i-1]*np.cos(t) - y[i-1]*np.sin(t))
        y[i] = u * (x[i-1]*np.sin(t) + y[i-1]*np.cos(t))
        
        # Make z a function of x, y, and the iteration index i
        z[i] = z[i-1] + 0.1 * np.sin(0.3 * i + 0.2 * x[i] + 0.2 * y[i])
    
    return x, y, z


# Returns 3 lists (one for x, y, z-axis) 
def gen_sequence_ikeda_output(u=0.918, x0=0, y0=0, z0=1, num_points=100, seq_start=0, seq_end=-1, save_to_file='output.txt'):
    
    # if no seq_end is given into the function, take the whole set of the Ikeda equation
    # -1 because list starts at 0
    if seq_end == -1:
        seq_end = num_points - 1
    
    # Generate raw Ikeda data e.g. [0.273459, -0.60935, 1.429385] (from chat GPT)
    x, y, z = ikeda_map_3D(u, x0, y0, z0, num_points)

    return x, y, z

# make seperate lists (from all axis)
x, y, z = gen_sequence_ikeda_output()
print(x)


#TODO

# filter data


#Normalise the data from the lists


#transform it into an event sequence





# following function is copied from chat-gpt
# Test different parameters and visualise them
def show_figure():
    x, y, z = ikeda_map_3D(u=0.5, x0=0.0, y0=0.0, z0=1.0, num_points=1000)

    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    # display a line 
    ax.plot(x, y, z)
    plt.show()