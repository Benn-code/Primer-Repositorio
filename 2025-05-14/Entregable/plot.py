import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# Estilo
sns.set_context("notebook")
sns.set_style("whitegrid")
plt.rcParams.update({'font.size': 12})

# read data
N, Error_Trapezoid, Error_Simpson, Error_Trapezoid_R, Error_Simpson_R = np.loadtxt("computing-errors.txt", unpack=True, skiprows=1)

# plot 
fig, ax = plt.subplots()
ax.plot(N, Error_Trapezoid, '-o', label='Error Trapezoid')
ax.plot(N, Error_Simpson, '-s', label='Error Simpson')
ax.plot(N, Error_Trapezoid_R, '-*', label='Error Richardson-Trapezoid')
ax.plot(N, Error_Simpson_R, '-*', label='Error Richardson-Simpson')

# Ejes logarítmicos
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('$N$')
ax.set_ylabel('Error relativo')
ax.set_title('Error relativo en integración numérica')
ax.legend()
fig.tight_layout()
fig.savefig('integration.pdf')
# fig.savefig('integration.png', dpi=300)



