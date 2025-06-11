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
#include <complex>

template<typename T>
void matrix_printer(const std::vector<T> & u,int m,int n){
    for (int ii{0}; ii < m; ii++){
        for (int jj{0}; jj < n; jj++){
            std::cout << u[ii*n + jj] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

template<typename T>
void general_matrix_substract(const std::vector<T> & A, const std::vector<T> & B, std::vector<T> & C){

    if (A.size()!=B.size()){
        std::cerr << "Invalid input\n";
        return;
    }
    
    C.resize(A.size(),0.0);

    for (int ii{0}; ii < A.size(); ii++){
        C[ii]= A[ii] - B[ii];
    }
    
}

template<typename T>
void general_matrix_add(const std::vector<T> & A, const std::vector<T> & B, std::vector<T> & C){

    if (A.size()!=B.size()){
        std::cerr << "Invalid input\n";
        return;
    }
    
    C.resize(A.size(),0.0);

    for (int ii{0}; ii < A.size(); ii++){
        C[ii]= A[ii] + B[ii];
    }
    
}

template<typename T>
void general_fill_matrix_zeros(std::vector<T> & M){
    for (long long int ii{0}; ii < M.size(); ii++){
        M[ii]=T(0);
    }
    
}


template<typename T>
void general_matrix_multiply_AB(const std::vector<T> A, const std::vector<T> B, std::vector<T> & C, const int Arows, const int Acols, const int Brows, const int Bcols){

    if (Acols!=Brows){
        std::cerr << "Invalid input\n";
        return;
    }
    
    C.resize(Arows*Bcols, T(0.0));
    general_fill_matrix_zeros(C);

    for (int ii = 0; ii < Arows; ii++){

        for (int jj = 0; jj < Bcols; jj++){

            for (int kk = 0; kk < Acols; kk++){

                C[ii*Bcols + jj] += A[ii*Acols + kk] * B[kk*Bcols + jj];

            }
            
        }

    }
}


void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed);
void fill_matrix_hilbert(std::vector<double> & M, const int nrows, const int ncols);
double matrix_trace(const std::vector<double> & M, const int n);
void matrix_multiply_AB(const std::vector<double> A, const std::vector<double> B, std::vector<double> & C, const int Arows, const int Acols, const int Brows, const int Bcols);
double dot_product(const std::vector<double> & x, const std::vector<double> & y);
std::vector<double> col_extract(const std::vector<double> M, const int m, const int n, const int k);
std::vector<double> row_extract(const std::vector<double> M, const int m, const int n, const int k);
void fill_matrix_identity(std::vector<double> & M, const int n);
void matrix_pow(const std::vector<double> & M, std::vector<double> & Z, const int n, const int k);
bool matrix_is_idempotent(const std::vector<double> & M, const int n, const int k, const double epsilon);
bool matrix_is_inverse (const std::vector<double> & A, const std::vector<double> & B, const int n, const double epsilon);
bool matrix_commute(const std::vector<double> & A, const std::vector<double> & B, const int n, const double epsilon);
void matrix_transpose(const std::vector<double> & M, const int m, const int n,std::vector<double> & Z);
bool matrix_is_orthogonal(const std::vector<double> & A, const int n, const double epsilon);
std::vector<double> matrix_polynomial(const std::vector<double> & A, const int n, const std::vector<double> & u);


void complex_fill_matrix_identity(std::vector<std::complex<double>> & M, const int n);
void complex_matrix_transpose_conjugate(const std::vector<std::complex<double>> & M, int m, int n,std::vector<std::complex<double>> & Z);
bool complex_matrix_is_hermitian(const std::vector<std::complex<double>> & M, const int n);
void complex_matrix_multiply_AB(const std::vector<std::complex<double>> A, const std::vector<std::complex<double>> B, std::vector<std::complex<double>> & C, const int Arows, const int Acols, const int Brows, const int Bcols);
std::complex<double> complex_dot_product(const std::vector<std::complex<double>> & x, const std::vector<std::complex<double>> & y);
std::vector<std::complex<double>> complex_col_extract(const std::vector<std::complex<double>> M, const int m, const int n, const int k);
std::vector<std::complex<double>> complex_row_extract(const std::vector<std::complex<double>> M, const int m, const int n, const int k);
bool complex_matrix_is_inverse (const std::vector<std::complex<double>> & A, const std::vector<std::complex<double>> & B, const int n, const double epsilon);
void complex_fill_matrix_pauli_base( std::vector<std::complex<double>> & sigma1, std::vector<std::complex<double>> & sigma2, std::vector<std::complex<double>> & sigma3);
void complex_fill_matrix_pauli_vec(const std::vector<std::complex<double>> & u, std::vector<std::complex<double>> & M);
