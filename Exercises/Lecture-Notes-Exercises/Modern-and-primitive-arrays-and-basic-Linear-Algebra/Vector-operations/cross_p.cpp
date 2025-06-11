#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>
#include <random>

std::valarray<double> cross(const std::valarray<double> & A, const std::valarray<double> & B);

int main(void){
    std::random_device rd;                          // semilla aleatoria (hardware)
    std::mt19937 gen(rd());                         // generador Mersenne Twister
    std::uniform_int_distribution<> distrib(1000, 2500); // rango [1, 10]

    std::valarray<double> v(0.0,3);

    for (int i = 0; i < 3; ++i)
        v[i] = distrib(gen);
    
    for (auto val : v)
        std::cout << val << " ";

    std::cout << "\n";

    std::valarray<double> z = {0,0,1};

    std::valarray<double> u = cross(v,z);

    for (auto val : u)
        std::cout << val << " ";

    //angle
    double sin = u.sum() / (v.sum()*z.sum());
    std::cout << "\n" << std::asin(sin) << "\n";

    //perp unit vector
    double norm{0};
    for (auto val : u)
        norm+=val*val;
    norm=std::sqrt(norm);
    std::valarray<double> perp = u/norm;
    for (auto val : perp)
        std::cout << val << " ";

    return 0;
}


std::valarray<double> cross(const std::valarray<double> & A, const std::valarray<double> & B){
    std::valarray<double> result(0.0,3);

    result[0] = A[1]*B[2] - A[2]*B[1];
    result[1] = A[2]*B[0] - A[0]*B[2];
    result[2] = A[0]*B[1] - A[1]*B[0];

    return result;
}