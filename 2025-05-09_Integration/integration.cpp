#include "integration.h"

double trapezoid (double a, double b, int N, fptr fun){

    double Deltax = (b-a)/N;
    double suma = 0;
    for (int k=1; k <= N-1; k++){
        double xk = a + k*Deltax;
        suma = suma + fun(xk);
    }
    double result = Deltax*(0.5*fun(a) + suma + 0.5*fun(b));
    return result; 
}

double simpson (double a, double b, int N, fptr fun){

if (N % 2 != 0){ 
    N = N+1; 
}
double Deltax = (b-a)/N;
double suma = 0;
for (int k = 1; k <= N/2; k++){
    double x2k-1 =

}


}


