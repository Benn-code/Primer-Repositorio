#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>


double vector_norm(std::vector<double> v);
std::vector<double> poly_deriv(std::vector<double> v);
long int argmax(const std::vector<double> & u);
long int argmin(const std::vector<double> & u);
double p_norm(const std::vector<double> & u, long long int p);
double median(std::vector<double> u);
double percentil(std::vector<double> u, double i);
void fill_randomly(std::vector<double> & u);

template<typename T>
void v_printer(const std::vector<T> & u){
    for (auto val : u){
        std::cout << val << "\n";
    }
}

template<typename T>
void matrix_printer(const std::vector<T> & u,int m,int n){
    for (int ii{0}; ii < m; ii++){
        for (int jj{0}; jj < n; jj++){
            std::cout << u[ii*n + jj] << " ";
        }
        std::cout << "\n";
    }
    
}

void int_counter_histogram(std::vector<int> u);
std::vector<double> dbl_counter_histogram(const std::vector<double> & u, double delta);
std::vector<double> weibull_vector(int N, double shape, double scale, int seed);