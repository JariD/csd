import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


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

# Normalise Ikeda Attractor point (per point)
def normalise(point=float) -> float:
    # round to 1 decimal
    point = round(point, 2)

    # make positive
    point = point * -1 if point < 0 else point

    # round to closest 0.5 number
    point = round(point * 2) / 2

    return point

def transform_to_event_sequence(array=tuple) -> list:
    # remove all 0 values in the array, except the first one
    # this so the first impact can be at ts 0 but later ts don't get overlays
    # add all numbers up throughout the array
   
    # used for testing the function
    """
    print(
        transform_to_event_sequence(
            [0.0, 1,0, 0.0, 0.0, 0.0, 0.5, 0.5, 1.0]
        )
    )"""

    # remove all 0 values except for the first one
    array = [array[0]] + [num for num in array[1:] if num != 0]

    # add all numbers up throughout the array
    event_sequence = []
    previous_num = 0
    for num in array:
        event_sequence.append(previous_num + num)
        previous_num = previous_num + num

    # gives cleaned up list
    return list(event_sequence)


# Returns 3 lists (one for x, y, z-axis) (def function from chat-gpt)
def gen_sequence_ikeda_output(u=0.918, x0=0, y0=0, z0=1, num_points=100, seq_start=0, seq_end=-1, save_to_file='output.txt'):
    
    # if no seq_end is given into the function, take the whole set of the Ikeda equation
    # -1 because list starts at 0
    if seq_end == -1:
        seq_end = num_points - 1
    
    # Generate raw Ikeda data e.g. [0.273459, -0.60935, 1.429385] (from chat GPT)
    x, y, z = ikeda_map_3D(u, x0, y0, z0, num_points)

    # filter out all data (from all axis) which y needs to be lower than 1.5
        # works great with the u=0.918 but needs ajustments for other 
    x, y, z = x[seq_start:seq_end], y[seq_start:seq_end], z[seq_start:seq_end]

    # normalise the data so that result will be [0.0, 0.5, 1.5] per list
    x = [normalise(num) for num in x]
    y = [normalise(num) for num in y]
    z = [normalise(num) for num in z]

    # transform it to an event sequence which looks like [0.0, 0.5, 1.5] per list
    x = transform_to_event_sequence(x)
    y = transform_to_event_sequence(y)
    z = transform_to_event_sequence(z)

    # save the data to a separate text file
    if save_to_file:
        with open(save_to_file, 'w+') as f:
            # zip x, y, z so all index is zipped together
            for c in zip(x, y, z):
                f.write(str(c) + '\n')

    return x, y, z

# another sequence to test
def ikeda_sequence_v1():
    return gen_sequence_ikeda_output(u=0.915, x0=0, y0=0, z0=1, num_points=1000, seq_start=0, seq_end=400)

# another sequence to test
def ikeda_sequence_v2():
    return gen_sequence_ikeda_output(u=0.915, x0=0, y0=0, z0=1, num_points=1000, seq_start=0, seq_end=400)

def ikeda_sequence_tornado():
    return gen_sequence_ikeda_output(u=1.001, x0=0.0, y0=0.0, z0=1, num_points=1000)


# make seperate lists (from all axis) used in testing
"""
x, y, z = gen_sequence_ikeda_output()
print(x)
"""

# following function is copied from chat-gpt
# Test different parameters and visualise them
def show_figure(u=float,x0=float,y0=float,z0=float,num_points=int):
    x, y, z = ikeda_map_3D(u, x0, y0, z0, num_points)

    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    # display a line 
    ax.plot(x, y, z)
    title_text = f"u={u}, x0={x0}, y0={y0}, z0={z0}, num_points={num_points}"
    ax.set_title(title_text)
    plt.show()

# some amazingly beautifull plot data
def plot_tornado():
    return show_figure(u=1.001, x0=0.0, y0=0.0, z0=1, num_points=1000)

def plot_tol():
    return show_figure(u=1.020, x0=0.0, y0=0.0, z0=1, num_points=1000)

# use plot_"name" to make a visual presentation of the ikeda attractor data
plot_tornado()


