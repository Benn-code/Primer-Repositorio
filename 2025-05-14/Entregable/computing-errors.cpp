/* Este programa calcula el error de los métodos de integración numérica
   (Trapecio y Simpson) y su extrapolación de Richardson. 
   Se utiliza la función f(x) = sin(exp(x)) como ejemplo.
   El resultado se guarda en un archivo "computing-errors.txt".
*/

#include <iostream>
#include <fstream>
#include <functional>
#include <cmath>

//Definición de punteros a funciones
using fptr = std::function<double(double)>;
using algptr = std::function<double(double, double, int, fptr)>; 

//Declaración de funciones
double trapezoid (double a, double b, int N, fptr fun);
double simpson (double a, double b, int N, fptr fun);
double richardson(double a, double b, int N, fptr fun, algptr alg, int alpha);
double fun(double x);

int main(void) {
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double a = -5.0;
    double b = 5.0;
    int N = 2000000;
    double exact_result = 1.56898093601156; // sin(e^x), donde e^x es exp(x)

    std::ofstream file("computing-errors.txt");
    file << "N\tError_Trapezoid\tError_Simpson\tError_Trapezoid_R\tError_Simpson_R\n"; // Añadir encabezado, cuando se grafíque toca omitir esta primera fila
    for (int n = 2; n <= N; n *= 2) {
        if (n % 2 != 0) continue; // Asegurar que N sea par para Simpson, aunque parece redundante ya que el bucle multiplica por 2, lo dejo para otros casos
        double trapezoid_result_n = trapezoid(a, b, n, fun);
        double simpson_result_n = simpson(a, b, n, fun);

        // Extrapolación de Richardson para el trapecio (orden alpha = 2)
        double trapezoid_richardson_result = richardson(a, b, n, fun, trapezoid, 2);

        // Extrapolación de Richardson para Simpson (orden alpha = 4)
        double simpson_richardson_result = richardson(a, b, n, fun, simpson, 4);

        double error_trapezoid = std::abs(1.0 - trapezoid_result_n / exact_result);
        double error_simpson = std::abs(1.0 - simpson_result_n / exact_result);
        double error_trapezoid_r = std::abs(1.0 - trapezoid_richardson_result / exact_result);
        double error_simpson_r = std::abs(1.0 - simpson_richardson_result / exact_result);

        file << n << "\t" << error_trapezoid << "\t" << error_simpson << "\t"
            << error_trapezoid_r << "\t" << error_simpson_r << "\n";
    }
    file.close();
    return 0;
}

//Función a integrar
double fun(double x){
    return std::sin(std::exp(x));
}

//Implementación de la regla del trapecio
double trapezoid (double a, double b, int N, fptr fun){
    double Deltax = (b-a)/N;
    double suma = 0.0;
    for (int k=1; k <= N-1; k++){
        double xk = a + k*Deltax;
        suma = suma + fun(xk);
    }
    double result = Deltax*(0.5*fun(a) + suma + 0.5*fun(b));
    return result;
}

//Implementación de la regla de Simpson
double simpson (double a, double b, int N, fptr fun){
    if (N % 2 != 0){
        N = N + 1;
    }
    double Deltax = (b-a)/N;
    double suma_impar = 0.0;
    double suma_par = 0.0;
    for (int k = 1; k <= N / 2; ++k) {
        double x2k_menos_1 = a + (2 * k - 1) * Deltax;
        suma_impar += fun(x2k_menos_1);
    }
    for (int k = 1; k <= N / 2 - 1; ++k) {
        double x2k = a + 2 * k * Deltax;
        suma_par += fun(x2k);
    }
    double result = (Deltax / 3.0) * (fun(a) + 4.0 * suma_impar + 2.0 * suma_par + fun(b));
    return result;
}

//Implementación de la extrapolación de Richardson
double richardson(double a, double b, int n, fptr fun, algptr alg, int alpha){
    double integral1 = alg(a, b, n, fun);
    double integral2 = alg(a, b, 2*n, fun); // Usamos el doble de puntos (mitad del paso)
    double aux = std::pow(2.0, alpha);
    return (aux * integral2 - integral1) / (aux - 1.0);
}

  
