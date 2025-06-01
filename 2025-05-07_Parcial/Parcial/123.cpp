#include <iostream>
#include <string>

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

int rng_von_neumann(int init, int nsteps)
{
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