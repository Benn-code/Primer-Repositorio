import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import linregress

# Leer datos
N, Error_Trapezoid, Error_Simpson, Error_Trapezoid_R, Error_Simpson_R = np.loadtxt("computing-errors.txt", unpack=True, skiprows=1)

# Definir función para ajuste lineal y gráfica
def plot_with_fit(N, errors, label, color, xmin=1000, xmax=100000):
    # Filtrar datos para el ajuste
    mask = (N >= xmin) & (N <= xmax)
    logN = np.log10(N[mask])
    logE = np.log10(errors[mask])
    
    # Ajuste lineal
    slope, intercept, _, _, _ = linregress(logN, logE)
    order = -slope

    # Recta ajustada
    N_fit = np.logspace(np.log10(xmin), np.log10(xmax), 100)
    E_fit = 10**(intercept + slope * np.log10(N_fit))
    
    # Graficar
    plt.plot(N, errors, marker='o', linestyle='-', label=f'{label} (orden ≈ {order:.2f})', color=color)
    plt.plot(N_fit, E_fit, linestyle='--', color=color)

    return order

# Crear gráfico
plt.figure(figsize=(10, 6))
plt.xscale('log')
plt.yscale('log')

# Graficar cada método y su orden
ord1 = plot_with_fit(N, Error_Trapezoid, "Trapecio", "blue")
ord2 = plot_with_fit(N, Error_Simpson, "Simpson", "orange")
ord3 = plot_with_fit(N, Error_Trapezoid_R, "Trapecio + Richardson", "green")
ord4 = plot_with_fit(N, Error_Simpson_R, "Simpson + Richardson", "red")

# Etiquetas
plt.xlabel('$N$')
plt.ylabel('Error relativo')
plt.title('Orden de convergencia estimado por ajuste lineal log-log')
plt.legend()
plt.grid(True, which="both", ls="--", lw=0.5)
plt.tight_layout()
plt.savefig("orden-convergencia-ajuste.pdf")
plt.show()

# También puedes imprimir los órdenes
print(f"Orden Trapecio: {ord1:.2f}")
print(f"Orden Simpson: {ord2:.2f}")
print(f"Orden Trapecio + Richardson: {ord3:.2f}")
print(f"Orden Simpson + Richardson: {ord4:.2f}")