#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include <valarray>
#include <cmath>

void print(std::string msg, const std::valarray<double>& v)
{
    std::cout << msg << " ";
    for (auto n: v) { std::cout << " " << n; }
    std::cout << '\n';
}

int main(void){

    const int N = 10;
    //Create valarray with 1000 points
    std::valarray<double> v(N);
    //fill valarray 
    std::iota(std::begin(v), std::end(v), 0.0);
    //multiply the valarray for 
    v = v * 2.0*(M_1_PI/N);
    print("valarray per 2*PI/N:", v);

    std::valarray<double> v1 = std::sin(v);
    print("valarray sin", v1);

    std::valarray<double> filtered = v1 ; 
    print("valarray sin", filtered);
}