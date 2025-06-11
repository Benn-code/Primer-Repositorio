#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>

int main(void){

    const double m = 0.987;              // masa
    const double dt = 0.01;              // paso de tiempo
    const int steps = 100;              // número de pasos
    const int b = 0.5;
    std::valarray<double> g = {0.0, 0.0, -9.8}; // gravedad
    std::valarray<double> R = {0.0, 0.0, 4.3};  // posición inicial
    std::valarray<double> V = {0.123, 0.0, 0.98};
    std::valarray<double> F = m*g;
    std::valarray<double> f = -b*V;

    for ( int ii = 0; ii < steps; ii++){
        R += dt * V;
        V += dt * (F+f)/m;
        f = -b*V;

        if (R[2] < 0){ R[2]=0; V[2]*=-1;} 

        std::cout << "t= " << ii*dt << "\n"
                << "R=( " << R[0] << " , " << R[1] << " , " << R[2] << ")\t"
                << "V=( " << V[0] << " , " << V[1] << " , " << V[2] << ")\n";

    }
    

    return 0;
}