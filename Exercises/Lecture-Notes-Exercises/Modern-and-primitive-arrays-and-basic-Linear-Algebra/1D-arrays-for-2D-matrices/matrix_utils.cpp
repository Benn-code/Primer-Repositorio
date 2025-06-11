#include "matrix_utils.h"

// Rellena una matriz de tamaño nrows x ncols con números aleatorios entre -1 y 1
void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed){
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(-1, 1);
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = dis(gen);
        }
    }

}

//Calcula la traza de una matriz aleatoria utilizando indexación 1D.
double matrix_trace(const std::vector<double> & M, const int n){
    double sum{0};

    if (n*n!=M.size()){
        std::cerr << "Invalid input\n";
        return 0;
    }
    
    for (int ii{0}; ii < n; ii++){
        sum+=M[ii*n+ii];
    }
    
    return sum;
}

//Rellena una matriz de Hilbert de tamaño nrows x ncols
void fill_matrix_hilbert(std::vector<double> & M, const int nrows, const int ncols){
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = 1.0/(ii + jj + 1);
        }
    }
}

//Multiplica dos matrices A y B de tamaño Arows x Acols y Brows x Bcols respectivamente, y almacena el resultado en C de tamaño Arows x Bcols.
void matrix_multiply_AB(const std::vector<double> A, const std::vector<double> B, std::vector<double> & C, const int Arows, const int Acols, const int Brows, const int Bcols){

    if (Acols!=Brows){
        std::cerr << "Invalid input\n";
    } else {
    
    C.resize(Arows*Bcols);
    
    for (int ii = 0; ii < Arows; ii++){
        for (int jj = 0; jj < Bcols; jj++){
            C[ii*Bcols + jj] = dot_product(row_extract(A,Arows,Acols,ii),col_extract(B,Brows,Bcols,jj));
        }
    }
    }
}

double dot_product(const std::vector<double> & x, const std::vector<double> & y){

    double sum{0};

    if (x.size()!=y.size()){
        std::cerr << "Los vectores deben tener el mismo tamaño\n";
        return 0;
    }

    for(long long int ii{0}; ii < x.size(); ii++){
        sum+=x[ii]*y[ii];
    }

    return sum;
}

std::vector<double> col_extract(const std::vector<double> M, const int m, const int n, const int k){
    std::vector<double> k_col(m);

    for ( int ii{0}; ii < m; ii++){

        k_col[ii]=M[ii*n + k];

    }

    return k_col;
}


std::vector<double> row_extract(const std::vector<double> M, const int m, const int n, const int k){
    std::vector<double> k_row(n);

    for ( int jj{0}; jj < n; jj++){

        k_row[jj]=M[k*n + jj];

    }

    return k_row;
}

void fill_matrix_identity(std::vector<double> & M, const int n){

    M.resize(n*n,0.0);

    for (int ii{0}; ii < n; ii++){
        M[ii*n+ii]=1;
    }

}

void matrix_pow(const std::vector<double> & M, std::vector<double> & Z, int n, int k){

    if (n*n!=M.size()){

        std::cerr << "Invalid input\n";

    } else if(k==0){

        fill_matrix_identity(Z,n);

    } else if (k==1){

        Z=M;

    } else {

        Z=M;
        for (int ii{2}; ii <= k; ii++){
            matrix_multiply_AB(M,Z,Z,n,n,n,n);
        }

    }

}

//Verifica si una matriz es idempotente, es decir, si M^k = M para un entero k dado y una tolerancia epsilon.
bool matrix_is_idempotent(const std::vector<double> & M, const int n, const int k, const double epsilon){

    std::vector<double> H;
    double check{0};
    bool flag{true};
    
    if (n*n!=M.size()){

        std::cerr << "Invalid input\n";
        return false;
    }

    matrix_pow(M,H,n,k);

    for ( int ii{0}; ii < n; ii++){
        for (int jj{0}; jj < n; jj++){

            check=std::abs( H[ii*n+jj]-M[ii*n+jj] );

            if (check>epsilon){
                flag=false;
                goto end;
            }
        }     
    }

    end:

    return flag;
}

//Verifica si dos matrices A y B son inversas entre sí, es decir, si AB = I y BA = I, donde I es la matriz identidad de tamaño n x n.
bool matrix_is_inverse (const std::vector<double> & A, const std::vector<double> & B, const int n, const double epsilon){
    if (n*n!=A.size() || n*n!=B.size()){

        std::cerr << "Invalid input\n";
        return false;
    }

    std::vector<double> identity;
    std::vector<double> AB;
    std::vector<double> BA;
    double check1{0};
    double check2{0};
    bool flag=true;

    fill_matrix_identity(identity,n);

    matrix_multiply_AB(A,B,AB,n,n,n,n);
    matrix_multiply_AB(B,A,BA,n,n,n,n);
    
    for ( int ii{0}; ii < n; ii++){
        for (int jj{0}; jj < n; jj++){
            check1=std::abs( AB[ii*n+jj]-identity[ii*n+jj] );
            check2=std::abs( BA[ii*n+jj]-identity[ii*n+jj] );

            if (check1>epsilon || check2>epsilon){
                flag=false;
                goto end;
            }

        }     
    }

    end:

    return flag;

}

bool matrix_commute(const std::vector<double> & A, const std::vector<double> & B, const int n, const double epsilon){
    if (n*n!=A.size() || n*n!=B.size()){

        std::cerr << "Invalid input\n";
        return false;
    }

    std::vector<double> AB;
    std::vector<double> BA;
    double check1{0};
    double check2{0};
    bool flag=true;

    matrix_multiply_AB(A,B,AB,n,n,n,n);
    matrix_multiply_AB(B,A,BA,n,n,n,n);
    
    for ( int ii{0}; ii < n; ii++){
        for (int jj{0}; jj < n; jj++){
            check1=std::abs( AB[ii*n+jj]-BA[ii*n+jj] );

            if (check1>epsilon || check2>epsilon){
                flag=false;
                goto end;
            }

        }     
    }

    end:

    return flag;
}


void matrix_transpose(const std::vector<double> & M, const int m, const int n,std::vector<double> & Z){
    for (int ii = 0; ii < m; ii++){
        for (int jj = 0; jj < n; jj++){
            Z[jj*m + ii] = M[ii*n + jj];
        }
    }  
}

//Verifica si una matriz A es ortogonal, es decir, si A^T = A^(-1), donde A^T es la transpuesta de A y A^(-1) es la inversa de A.
bool matrix_is_orthogonal(const std::vector<double> & A, const int n, const double epsilon){
    std::vector<double> Z(n*n,0.0);
    matrix_transpose(A,n,n,Z);
    return matrix_is_inverse(A,Z,n,epsilon);
}

std::vector<double> matrix_polynomial(const std::vector<double> & A, const int n, const std::vector<double> & u){
    std::vector<double> Z(n*n,0.0);
    std::vector<double> Apow(n*n,0.0);

    for (int ii{0}; ii < n; ii++){
        
        for (int jj{0}; jj < n; jj++){
            
            for (int kk{0}; kk < u.size(); kk++){
                
                matrix_pow(A,Apow,n,kk);
                Z[ii*n + jj] += u[kk]*Apow[ii*n + jj];

            }
        }
    }
    
    return Z;
}




//Matrices complejas:

void complex_fill_matrix_identity(std::vector<std::complex<double>> & M, const int n){

    M.resize(n*n,0.0);

    for (int ii{0}; ii < n; ii++){
        M[ii*n+ii]=1;
    }

}

void complex_matrix_transpose_conjugate(const std::vector<std::complex<double>> & M, int m, int n,std::vector<std::complex<double>> & Z){
    for (int ii = 0; ii < m; ii++){
        for (int jj = 0; jj < n; jj++){
            Z[jj*m + ii] = std::conj(M[ii*n + jj]);
        }
    }  
}

bool complex_matrix_is_hermitian(const std::vector<std::complex<double>> & M, const int n){
    std::vector<std::complex<double>> Z;
    complex_matrix_transpose_conjugate(M,n,n,Z);

    return complex_matrix_is_inverse(M,Z,n,1e-10);

}

void complex_matrix_multiply_AB(const std::vector<std::complex<double>> A, const std::vector<std::complex<double>> B, std::vector<std::complex<double>> & C, const int Arows, const int Acols, const int Brows, const int Bcols){

    if (Acols!=Brows){
        std::cerr << "Invalid input\n";
    } else {
    
    C.resize(Arows*Bcols);
    
    for (int ii = 0; ii < Arows; ii++){
        for (int jj = 0; jj < Bcols; jj++){
            C[ii*Bcols + jj] = complex_dot_product(complex_row_extract(A,Arows,Acols,ii),complex_col_extract(B,Brows,Bcols,jj));
        }
    }
    }
}

std::complex<double> complex_dot_product(const std::vector<std::complex<double>> & x, const std::vector<std::complex<double>> & y){

    std::complex<double> sum{0};

    if (x.size()!=y.size()){
        std::cerr << "Los vectores deben tener el mismo tamaño\n";
        return 0;
    }

    for(long long int ii{0}; ii < x.size(); ii++){
        sum=sum+x[ii]*y[ii];
    }

    return sum;
}

std::vector<std::complex<double>> complex_col_extract(const std::vector<std::complex<double>> M, const int m, const int n, const int k){
    std::vector<std::complex<double>> k_col(m);

    for ( int ii{0}; ii < m; ii++){

        k_col[ii]=M[ii*n + k];

    }

    return k_col;
}


std::vector<std::complex<double>> complex_row_extract(const std::vector<std::complex<double>> M, const int m, const int n, const int k){
    std::vector<std::complex<double>> k_row(n);

    for ( int jj{0}; jj < n; jj++){

        k_row[jj]=M[k*n + jj];

    }

    return k_row;
}


bool complex_matrix_is_inverse (const std::vector<std::complex<double>> & A, const std::vector<std::complex<double>> & B, const int n, const double epsilon){
    if (n*n!=A.size() || n*n!=B.size()){

        std::cerr << "Invalid input\n";
        return false;
    }

    std::vector<std::complex<double>> identity;
    std::vector<std::complex<double>> AB;
    std::vector<std::complex<double>> BA;
    double check1real{0};
    double check1img{0};
    double check2real{0};
    double check2img{0};
    bool flag=true;

    complex_fill_matrix_identity(identity,n);

    complex_matrix_multiply_AB(A,B,AB,n,n,n,n);
    complex_matrix_multiply_AB(B,A,BA,n,n,n,n);
    
    for ( int ii{0}; ii < n; ii++){
        for (int jj{0}; jj < n; jj++){
            check1real=std::abs( std::real(AB[ii*n+jj])-std::real(identity[ii*n+jj]) );
            check1img=std::abs( std::real(BA[ii*n+jj])-std::real(identity[ii*n+jj]) );
            check2real=std::abs( std::real(AB[ii*n+jj])-std::real(identity[ii*n+jj] ));
            check2img=std::abs( std::real(BA[ii*n+jj])-std::real(identity[ii*n+jj]) );    
            if (check1real>epsilon || check1img>epsilon || check2real>epsilon || check2img>epsilon){
                flag=false;
                goto end;
            }

        }     
    }

    end:

    return flag;

}

void complex_fill_matrix_pauli_base( std::vector<std::complex<double>> & sigma1, std::vector<std::complex<double>> & sigma2, std::vector<std::complex<double>> & sigma3){
    sigma1.resize(4,0.0);
    sigma2.resize(4,0.0);
    sigma3.resize(4,0.0);

    sigma1[0*2 + 1] = 1;
    sigma1[1*2 + 0] = 1;

    sigma2[0*2 + 1] = -std::complex<double>(0,1.0);
    sigma2[1*2 + 0] = std::complex<double>(0,1.0);

    sigma3[0*2 + 0] = 1;
    sigma3[1*2 + 1] = -1;
}

void complex_fill_matrix_pauli_vec(const std::vector<std::complex<double>> & u, std::vector<std::complex<double>> & M){
    M.resize(4);

    M[0] = u[2];
    M[0*2 + 1] = u[0] - std::complex<double>(0,1)*u[1];
    M[1*2 + 0] = u[0] + std::complex<double>(0,1)*u[1];
    M[1*2 + 1] = -u[2];

}