import matplotlib.pyplot as plt
import numpy as np
import math
from math import tanh

def sigmoid(x):
    return 1/(1+math.exp(-x))

def main():
    x = range(256)
    x = np.array(x) / 48
    y = []
    for i in x:
        y.append(round(255*sigmoid(i)))
    np.savetxt("LUT.txt", y,fmt="%d",delimiter=',', newline=',')
    ny = 255 - np.flip(np.array(y))
    y = np.concatenate((ny,y))
    x = np.concatenate((np.flip(x)*-1, x))
    plt.plot(x,y)
    plt.grid(True)
    plt.show()
        


if __name__ == "__main__":
    main()