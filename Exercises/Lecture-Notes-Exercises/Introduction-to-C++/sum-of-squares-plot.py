import matplotlib.pyplot as plt
import numpy as np

# Nombre del archivo de datos generado por C++
filename = "Squares less than20.txt" 

# Cargar los datos. np.loadtxt es excelente para esto.
# Se puede especificar el tipo de datos (dtype=int)
try:
    data = np.loadtxt(filename, dtype=int)
except FileNotFoundError:
    print(f"Error: El archivo '{filename}' no se encontró. Asegúrate de que tu programa C++ lo generó.")
    exit()

# La primera columna es 'n' (índice), la segunda es 'primo'
n_values = data[:, 0]
prime_values = data[:, 1]

# Crear el gráfico
plt.figure(figsize=(10, 6)) # Tamaño de la figura
plt.plot(n_values, prime_values, 'o-', markersize=4, label='Números Primos') # 'o-' para puntos y líneas

# Añadir títulos y etiquetas
plt.title(f"Suma de los cuadrados menores a n")
plt.xlabel("Índice del número (n)")
plt.ylabel("Valor la suma de los cuadrados menores")
plt.grid(True) # Añadir una cuadrícula
plt.legend() # Mostrar la leyenda

# Opcional: ajustar límites de los ejes
# plt.xlim(0, n_values.max() + 1)
# plt.ylim(0, prime_values.max() + 10)

# Guardar el gráfico como imagen (ej. PNG)
plt.savefig('sum-of-squares-less.png')

# Mostrar el gráfico (opcional, si ejecutas el script de forma interactiva)
plt.show() 

print(f"Gráfico guardado como 'sum-of-squares-less.png'")