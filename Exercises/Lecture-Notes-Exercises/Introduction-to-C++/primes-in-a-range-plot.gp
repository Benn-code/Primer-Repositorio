# Establece el formato de salida a PNG (puedes elegir otros como SVG, PDF, etc.)
set terminal pngcairo font "arial,10" size 800,600
# Establece el nombre del archivo de salida de la imagen
set output 'primes_plot-gp.png'

# Establece el título del gráfico
set title "Distribución de Números Primos en el Rango [2-200]"

# Etiqueta el eje X
set xlabel "Índice del Primo (n)"
# Etiqueta el eje Y
set ylabel "Valor del Primo"

# Ajusta el rango del eje X si es necesario (opcional)
# set xrange [0:50] 
# Ajusta el rango del eje Y si es necesario (opcional)
# set yrange [0:200]

# Dibuja los datos del archivo.
# 'filename' será el nombre de tu archivo de texto (ej. primes-between[2-200].txt)
# using 1:2 -> usa la primera columna para X, la segunda para Y
# with points -> dibuja puntos (puedes usar 'with lines', 'with linespoints', etc.)
# title "Números Primos" -> Etiqueta la serie de datos en la leyenda
plot "primes-between[2-200].txt" using 1:2 with points title "Números Primos"