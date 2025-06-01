#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

//declaration
double poly(double x, double h, fptr f);

int main (void){

    std::vector<double> data = {1, 3, 4.5}; // 1*x^0 + 3*x^1 + 4.5*x^2
    
    
    std::cout << data[0] << "\n";
    std::cout << &data[0] << "\n";

}

// Function to compute the derivative of a polynomial
std::vector<double> computePolynomialDerivative(const std::vector<double>& polynomialCoefficients) {
    std::vector<double> derivativeCoefficients;
    for (size_t i = 1; i < polynomialCoefficients.size(); ++i) {
        derivativeCoefficients.push_back(static_cast<double>(i) * polynomialCoefficients[i]);
        }

    return derivativeCoefficients;
}

double poly(double x, double h, fptr f){
    double result = 0.0;
    double N = std::vector<double>. pushback
    for (int ii=0; ii < data.size(); ii++){
        result += data[ii] * std::pow(x, ii);
    }


}

/*
Assume that a vector represents the coefficients of a n-degree polynomial. 
Compute the derivative of the polynomial and save the coefficients in another vector.
    data = {1 , 3, 4.5}; // 1*x^0 + 3*x^1 + 4.5*x^2
    newdata = {3, 9.0}; // 0 + 3*x^0 + 2*4.5*x^1
*/