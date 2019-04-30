import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("datos.dat")
x = np.arange(0,101,1)
y = np.arange(0,101,1)
fig = plt.figure()
ax = Axes3D(fig)
ax.plot_trisurf(x,y, data)
plt.savefig("fig.png")