import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
data = np.loadtxt('Neuman.txt', delimiter=',', skiprows=1)
ii = data[:, 0]
r = data[:, 1]

# plot 
fig, ax = plt.subplots()
plt.plot(ii, r, '*',  label='neuman')
ax.set_xlabel('$Iteración$')
ax.set_ylabel('Valor')
plt.title('Valor de las primeras 300 iteraciones de Neuman para 5761')
ax.legend()

# Guardar la gráfica como PDF
plt.savefig('Neuman5761-300.pdf')
plt.show()