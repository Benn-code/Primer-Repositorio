# Configuración del terminal de salida
set terminal pngcairo font "arial,10" size 1000,700
set output 'dilogarithm_plot.png'

# Título y etiquetas
set title "Función Di-logaritmo Li_2(x)"
set xlabel "x"
set ylabel "Li_2(x)"
set grid
set key top left # Posición de la leyenda

# Rango para x (el mismo que en el código)
set xrange [0:1.0] 
# Rango para y (la función Di-logaritmo va de 0 a -pi^2/6 ~ -1.645)
set yrange [-1.7:0.1] 

# Plotear las tres series de datos
plot "dilogarithm_data.txt" using 1:2 with linespoints title "Simpson + Richardson (Error < 1e-6)", \
     "" using 1:3 with linespoints title "Gauss Cuadrature (Order 7)", \
     "" using 1:4 with linespoints title "Gauss Cuadrature (Order 13)"