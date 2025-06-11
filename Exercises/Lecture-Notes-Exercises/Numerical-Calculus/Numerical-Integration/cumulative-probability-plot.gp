set terminal pngcairo font "arial,10" size 1000,700
set output 'gamma_cdf_plot.png'

set title "Función de Densidad Acumulativa (CDF) de la Distribución Gamma\n(alpha=7.5, beta=1.0)"
set xlabel "x"
set ylabel "F(x)"
set grid
set key top left # Posición de la leyenda
set xrange [0:20]
set yrange [0:1.05] # La CDF va de 0 a 1

plot "gamma_cdf_data.txt" using 1:2 with lines title "Método de Simpson", \
     "" using 1:3 with lines title "Cuadratura Gaussiana (n=7)"