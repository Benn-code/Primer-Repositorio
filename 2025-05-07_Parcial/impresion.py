import matplotlib.pyplot as plt
import numpy as np

# Leer los datos del archivo
try:
    data = np.loadtxt('derivative_results.txt', skiprows=2)
    h = data[:, 0]
    error = data[:, 3]
except FileNotFoundError:
    print("Error: No se encontró el archivo derivative_results.txt")
    exit()
except Exception as e:
    print(f"Error al leer el archivo: {e}")
    exit()

# Crear la gráfica
plt.figure(figsize=(10, 6))
plt.loglog(h, error, marker='o', linestyle='-', color='blue')
plt.xlabel('Tamaño del paso h')
plt.ylabel('Error Absoluto')
plt.title('Error Absoluto de la Derivada Numérica (O(h^6)) vs. h')
plt.grid(True, which="both", ls="-")
plt.ticklabel_format(style="sci", axis="y", scilimits=(0, 0))
plt.gca().invert_xaxis() # Invertir el eje x para mostrar h decreciente de izquierda a derecha
plt.tight_layout()

# Guardar la gráfica como PDF
plt.savefig('derivative_error_plot.pdf')
plt.show()