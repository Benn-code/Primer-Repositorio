#include <iostream>
#include <valarray>
#include <fstream>
#include <cmath>    // Para std::cos, std::sin, std::sqrt, M_PI
#include <iomanip>  // Para std::fixed, std::setprecision
#include "ivp_solver.h"

// Parámetro del oscilador armónico
// Elegimos omega = 1.234 rad/s como se sugiere en la imagen e9cc20.png
const double OMEGA = 1.234; // rad/s

typedef std::valarray<double> state_t; // alias for state type

// Declaraciones de funciones
void initial_conditions(state_t & y);
void print(const state_t & y, double time);
void fderiv_harmonic(const state_t & y, state_t & dydt, double t);

int main(int argc, char **argv)
{
    // El sistema ahora tiene 2 componentes: posicion (x) y velocidad (v)
    int N = 2; 
    state_t y_euler(N); // Estado para Euler
    state_t y_heun(N);  // Estado para Heun
    state_t y_rk4(N);   // Estado para RK4

    // Condiciones iniciales para cada método
    initial_conditions(y_euler);
    initial_conditions(y_heun);
    initial_conditions(y_rk4);

    // Parámetros de integración
    double t_init = 0.0;
    // Escoger un intervalo de tiempo adecuado para al menos varias oscilaciones
    // Periodo T = 2*PI / OMEGA
    // Queremos al menos 4 oscilaciones (arbitrario para una buena visualización)
    double num_oscillations = 4.0;
    double period = (2.0 * M_PI) / OMEGA;
    double t_end = num_oscillations * period; // Asegura varias oscilaciones

    // Pasos de tiempo sugeridos
    // Para el oscilador armónico, diferentes dt mostrarán mejor la estabilidad/inestabilidad
    double dt = 0.1; // Puedes probar 0.2, 0.5, 1.0 como sugiere el problema

    // Imprimir el encabezado para los archivos de datos
    // Columnas: Tiempo, Posicion_Euler, Posicion_Heun, Posicion_RK4, Posicion_Teorica
    // Para simplificar, guardaremos en archivos separados y luego los combinaremos con gnuplot
    // O puedes modificar la función print para imprimir todos a la vez si quisieras un solo archivo

    // --------------- Solución con Euler ----------------
    std::cout << "Running Euler method for dt = " << dt << std::endl;
    // Redirige la salida a un archivo para Euler
    std::ofstream euler_output("harmonic_euler.txt");
    auto euler_writer = [&](const state_t & s, double time) {
        euler_output << std::fixed << std::setprecision(8) << time << "\t" << s[0] << "\t" << s[1] << std::endl;
    };
    integrate_euler(fderiv_harmonic, y_euler, t_init, t_end, dt, euler_writer);
    euler_output.close();

    // --------------- Solución con Heun ----------------
    std::cout << "Running Heun method for dt = " << dt << std::endl;
    // Redirige la salida a un archivo para Heun
    std::ofstream heun_output("harmonic_heun.txt");
    auto heun_writer = [&](const state_t & s, double time) {
        heun_output << std::fixed << std::setprecision(8) << time << "\t" << s[0] << "\t" << s[1] << std::endl;
    };
    initial_conditions(y_heun); // Reinicia las condiciones iniciales para Heun
    integrate_heun(fderiv_harmonic, y_heun, t_init, t_end, dt, heun_writer);
    heun_output.close();

    // --------------- Solución con RK4 ----------------
    std::cout << "Running RK4 method for dt = " << dt << std::endl;
    // Redirige la salida a un archivo para RK4
    std::ofstream rk4_output("harmonic_rk4.txt");
    auto rk4_writer = [&](const state_t & s, double time) {
        rk4_output << std::fixed << std::setprecision(8) << time << "\t" << s[0] << "\t" << s[1] << std::endl;
    };
    initial_conditions(y_rk4); // Reinicia las condiciones iniciales para RK4
    integrate_rk4(fderiv_harmonic, y_rk4, t_init, t_end, dt, rk4_writer);
    rk4_output.close();

    // --------------- Solución Teórica ----------------
    // También plotearemos la solución teórica para comparar
    std::cout << "Generating Theoretical Solution for dt = " << dt << std::endl;
    std::ofstream theoretical_output("harmonic_theoretical.txt");
    double A = 1.0; // Amplitud (de las condiciones iniciales: x(0)=1)
    double phi = 0.0; // Fase (de las condiciones iniciales: v(0)=0)
                      // x(t) = A*cos(OMEGA*t + phi)
                      // v(t) = -A*OMEGA*sin(OMEGA*t + phi)

    for (double t = t_init; t <= t_end; t += dt) {
        double x_theoretical = A * std::cos(OMEGA * t + phi);
        double v_theoretical = -A * OMEGA * std::sin(OMEGA * t + phi);
        theoretical_output << std::fixed << std::setprecision(8) << t << "\t" << x_theoretical << "\t" << v_theoretical << std::endl;
    }
    theoretical_output.close();

    std::cout << "Data files generated: harmonic_euler.txt, harmonic_heun.txt, harmonic_rk4.txt, harmonic_theoretical.txt" << std::endl;
    std::cout << "Now, use Gnuplot to visualize." << std::endl;

    return 0;
}

// Condiciones iniciales: x(0) = 1.0, v(0) = 0.0
void initial_conditions(state_t & y)
{
    y[0] = 1.0; // Posición inicial x
    y[1] = 0.0; // Velocidad inicial v
}

// La función print ya no se usa directamente para la salida a cout,
// sino que se usa una lambda en main para escribir a archivos.
// Sin embargo, la mantengo si la necesitas para depuración a consola.
void print(const state_t & y, double time)
{
    // Esta función no se llama directamente en main para la escritura de archivos.
    // En su lugar, se usan lambdas para dirigir la salida a archivos específicos.
    // Solo para fines de ejemplo o depuración si se desea imprimir a consola.
    std::cout << std::fixed << std::setprecision(8) << time << "\t" << y[0] << "\t" << y[1] << std::endl;
}

// Función de derivada para el oscilador armónico
// dydt[0] = dx/dt = v = y[1]
// dydt[1] = dv/dt = -omega^2 * x = -omega^2 * y[0]
void fderiv_harmonic(const state_t & y, state_t & dydt, double t)
{
    dydt[0] = y[1];
    dydt[1] = -OMEGA * OMEGA * y[0];
}