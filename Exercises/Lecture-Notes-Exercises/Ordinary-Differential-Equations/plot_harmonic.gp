# Configuración del terminal y salida
set terminal pdf
set output 'harmonic_oscillator_comparison.pdf'

# Títulos y etiquetas
set title "Oscilador Armónico Simple (dt = 0.1)"
set xlabel "Tiempo (t)"
set ylabel "Posición (x)"

# Rango de los ejes (opcional, gnuplot los ajustará automáticamente si no se especifican)
# set xrange [0:10]
# set yrange [-1.2:1.2]

# Malla para mejor visualización
set grid

# Leyenda
set key top right # Coloca la leyenda en la parte superior derecha

# Graficar múltiples archivos
plot 'harmonic_euler.txt'     using 1:2 with lines title 'Euler', \
     'harmonic_heun.txt'      using 1:2 with lines title 'Heun', \
     'harmonic_rk4.txt'       using 1:2 with lines title 'RK4', \
     'harmonic_theoretical.txt' using 1:2 with lines lw 2 lc rgb "blue" title 'Teórica' #lw = linewidth, lc rgb = linecolor RGB