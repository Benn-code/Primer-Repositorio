import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
data = np.loadtxt('twin_primes_data.txt', delimiter=',', skiprows=1)
n = data[:, 0]
norma = data[:, 1]

# plot 
fig, ax = plt.subplots()
ax.plot(n, norma, '-o', label='norma')
ax.set_xlabel('$n$')
ax.set_ylabel('norma')
ax.legend()
fig.savefig('twin_primes_2.pdf')