#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>
#include <random>

int main(void){
    std::random_device rd;                          // semilla aleatoria (hardware)
    std::mt19937 gen(rd());                         // generador Mersenne Twister
    std::uniform_int_distribution<> distrib(1000, 2500); // rango [1, 10]

    const int N = 10;
    std::valarray<int> v(0.0,N);

    for (int i = 0; i < N; ++i)
        v[i] = distrib(gen);

    for (auto val : v)
        std::cout << val << " ";
    
    std::cout << "\n";

    std::valarray<int> u = v[ v%2!=0 ];

    for (auto val : u)
        std::cout << val << " ";
    
}