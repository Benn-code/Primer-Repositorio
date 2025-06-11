import matplotlib.pyplot as plt
import numpy as np

# Nombre del archivo de datos generado por C++
filename = "velocity_data.txt" 

try:
    # Carga los datos, saltando las dos primeras líneas (encabezados)
    # y usando un delimitador de tabulación
    data = np.loadtxt(filename, skiprows=2, delimiter='\t')
except FileNotFoundError:
    print(f"Error: El archivo '{filename}' no se encontró. Asegúrate de que tu programa C++ lo generó.")
    exit()

# La primera columna es el tiempo, la segunda es la velocidad
time_values = data[:, 0]
velocity_values = data[:, 1]

# Crear el gráfico
plt.figure(figsize=(10, 6)) # Tamaño de la figura
plt.plot(time_values, velocity_values, 'b-o', markersize=6, linewidth=2, label='Velocidad Calculada') # Línea azul con círculos

# Añadir títulos y etiquetas
plt.title("Velocidad del Coche vs. Tiempo")
plt.xlabel("Tiempo (s)")
plt.ylabel("Velocidad (m/s)")
plt.grid(True) # Mostrar cuadrícula
plt.legend() # Mostrar leyenda

# Guardar el gráfico
plt.savefig('velocity_plot_python.png')

# Mostrar el gráfico (si ejecutas el script directamente)
plt.show()

print(f"Gráfico guardado como 'velocity_plot_python.png'")