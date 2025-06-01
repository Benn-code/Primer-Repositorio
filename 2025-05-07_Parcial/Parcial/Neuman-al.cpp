#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int rng_von_neumann(int init, int nsteps);

int main(int argc, char **argv){ 


    if (argc != 3) { 
        std::cerr << "Use: " << argv[0] << " <number> <number>\n";
        return 1;
    }
    int valor = std::stoi(argv[1]);
    int steps = std::stoi(argv[2]);
    int result = rng_von_neumann (valor,steps);
    std::cout << result << '\n';
    return 0;

    
}

int rng_von_neumann(int init, int nsteps){
    std::ofstream outfile("Neuman.txt");
    if (outfile.is_open()) {
        outfile << "ii,r" << std::endl; // Escribir encabezado
        if (init < 0 or init > 9999) return 0;
        int r = init;
        for (int ii = 1; ii <= nsteps; ++ii) {
            r = r*r;
            std::cout << "cuadrado: " << r;
            r /= 100;
            r %= 10000;
            outfile << ii << "," << std::fixed << r << std::endl;
    }
  return r;
}
outfile.close();
        std::cout << "Los datos se han guardado en el archivo Neuman.txt" << std::endl;
}
        
/*
        
        while (count < n_max) {
            if (isprime(ii) && isprime(ii + 2)) {
                count++;
                long p = ii;
                double norma = std::sqrt(std::pow(p, 2) + std::pow(p+2, 2) );
                outfile << count << "," << std::fixed << std::setprecision(6) << norma << std::endl;
            }
            ii++;
        }
        outfile.close();
        std::cout << "Los datos se han guardado en el archivo twin_primes_data.txt" << std::endl;


  if (init < 0 or init > 9999) return 0;
  int r = init;
  for (int ii = 1; ii <= nsteps; ++ii) {
    r = r*r;
    std::cout << "cuadrado: " << r;
    r /= 100;
    r %= 10000;
    std::cout << "   num" << ii << ": " << r << '\n';
  }
  return r;
}
}
*/

 