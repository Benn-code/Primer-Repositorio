import matplotlib.pyplot as plt
import numpy as np

# Leer los datos del archivo
try:
    data = np.loadtxt('twin_primes_data.txt', delimiter=',', skiprows=1)
    n = data[:, 0]
    norma = data[:, 1]
except FileNotFoundError:
    print("Error: No se encontró el archivo twin_primes_data.txt")
    exit()

# Crear la gráfica
plt.figure(figsize=(10, 6))
plt.scatter(n, norma, marker='o', s=30)
plt.xlabel('n (Índice de la pareja de primos gemelos)')
plt.ylabel('Norma (sqrt(p^2 + 25))')
plt.title('Norma de las Primeras 100 Parejas de Primos Gemelos en Función de n')
plt.grid(True)
plt.xticks(np.arange(1, 101, 5)) # Mostrar marcas cada 5 en el eje x
plt.tight_layout()

# Guardar la gráfica como PDF
plt.savefig('twin_primes_graph.pdf')
plt.show()