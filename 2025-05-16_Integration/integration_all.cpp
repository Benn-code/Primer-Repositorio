
#include <iostream>
#include <cmath>
#include <vector>

typedef double (*fptr)(double);
typedef double (*algptr)(double, double, int, fptr);

double trapezoid(double a, double b, int N, fptr fun) {
    double Deltax = (b-a)/N;
    double suma = 0.0;
    for(int k = 1; k <= N-1; k++) {
        double xk = a + k*Deltax;
        suma += fun(xk);
    }
    return Deltax*(0.5*fun(a) + suma + 0.5*fun(b));
}

double simpson(double a, double b, int N, fptr fun) {
    if (N % 2 != 0) N++;
    double Deltax = (b-a)/N;
    double suma1 = 0.0;
    for(int k = 1; k <= N/2; k++) {
        double xk = a + (2*k - 1)*Deltax;
        suma1 += fun(xk);
    }
    double suma2 = 0.0;
    for(int k = 1; k <= N/2 - 1; k++) {
        double xk = a + (2*k)*Deltax;
        suma2 += fun(xk);
    }
    return Deltax*(fun(a) + 4*suma1 + 2*suma2 + fun(b))/3.0;
}

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha) {
    double aux = std::pow(2.0, alpha);
    double val1 = alg(a, b, N, f);
    double val2 = alg(a, b, 2*N, f);
    return (aux*val2 - val1)/(aux - 1.0);
}

void legendre_poly_and_derivative(int n, double x, double& Pn, double& dPn) {
    double P0 = 1.0;
    double P1 = x;
    double dP0 = 0.0;
    double dP1 = 1.0;
    for (int k = 2; k <= n; ++k) {
        double Pk = ((2.0*k - 1.0)*x*P1 - (k - 1.0)*P0)/k;
        double dPk = (k/(x*x - 1.0)) * (x*Pk - P1);
        P0 = P1;
        P1 = Pk;
        dP0 = dP1;
        dP1 = dPk;
    }
    Pn = P1;
    dPn = dP1;
}

void gauss_legendre_nodes_weights(int n, std::vector<double>& x, std::vector<double>& w) {
    x.resize(n);
    w.resize(n);
    const double EPS = 1e-14;
    int m = (n + 1)/2;
    for (int i = 0; i < m; ++i) {
        double xi = std::cos(M_PI * (i + 0.75)/(n + 0.5));
        double Pn, dPn;
        for (int it = 0; it < 100; ++it) {
            legendre_poly_and_derivative(n, xi, Pn, dPn);
            double dx = -Pn/dPn;
            xi += dx;
            if (std::abs(dx) < EPS) break;
        }
        x[i] = -xi;
        x[n - i - 1] = xi;
        w[i] = w[n - i - 1] = 2.0 / ((1.0 - xi*xi)*dPn*dPn);
    }
}

double gaussN(int n, double a, double b, fptr fun) {
    std::vector<double> x, w;
    gauss_legendre_nodes_weights(n, x, w);
    double result = 0.0;
    double c1 = (b - a)/2.0;
    double c2 = (b + a)/2.0;
    for (int i = 0; i < n; ++i) {
        result += w[i] * fun(c1 * x[i] + c2);
    }
    return c1 * result;
}

double f(double x) {
    return 7*x*x*x - 8*x*x + 3*x + 3;
}

int main() {
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    std::cout << "Trapecio (N=10):     " << trapezoid(-1.0, 1.0, 10, f) << "\n";
    std::cout << "Simpson (N=10):      " << simpson(-1.0, 1.0, 10, f) << "\n";
    std::cout << "Richardson(Trap):    " << richardson(-1.0, 1.0, 10, f, trapezoid, 2) << "\n";
    std::cout << "Richardson(Simp):    " << richardson(-1.0, 1.0, 10, f, simpson, 4) << "\n";
    std::cout << "Gauss N=2:           " << gaussN(2, -1.0, 1.0, f) << "\n";
    std::cout << "Gauss N=3:           " << gaussN(3, -1.0, 1.0, f) << "\n";
    std::cout << "Gauss N=5:           " << gaussN(5, -1.0, 1.0, f) << "\n";
    std::cout << "Gauss N=7:           " << gaussN(7, -1.0, 1.0, f) << "\n";
    std::cout << "Gauss N=13:          " << gaussN(13, -1.0, 1.0, f) << "\n";
    std::cout << "Gauss N=30:          " << gaussN(30, -1.0, 1.0, f) << "\n";

    return 0;
}
