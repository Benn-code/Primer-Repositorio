#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>
#include <random>

std::valarray<double> cross(const std::valarray<double> & A, const std::valarray<double> & B);

int main(void){
    std::valarray<double> A={1,0,0};
    std::valarray<double> B={0,1,0};
    std::valarray<double> C={0,0,1};

    std::valarray<double> D=cross(B,C);

    std::valarray<double> aux=A*D;
    double dot = aux.sum();
    std::cout << dot << "\n";  
    return 0;
}


std::valarray<double> cross(const std::valarray<double> & A, const std::valarray<double> & B){
    std::valarray<double> result(0.0,3);

    result[0] = A[1]*B[2] - A[2]*B[1];
    result[1] = A[2]*B[0] - A[0]*B[2];
    result[2] = A[0]*B[1] - A[1]*B[0];

    return result;
}