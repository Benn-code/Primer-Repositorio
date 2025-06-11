#include "functions-arrays.h"

//Calcula la norma de un vector
double vector_norm(std::vector<double> &v){
    double sum{0};

    for (auto val : v){
        sum+=val*val;
    }
    
    return std::sqrt(sum);
}

//Calcula la derivada de un polinomio representado por un vector
std::vector<double> poly_deriv(std::vector<double> &v){
    for ( long int ii{0}; ii < v.size(); ii++){
        v[ii]*=ii;
    }

    v.erase(v.begin());

    return v;
}

//Calcula el índice del máximo y mínimo de un vector
long int argmax(const std::vector<double> & u){
    auto maxit = std::max_element(u.begin(),u.end());
    auto maxin = std::distance(u.begin(),maxit);

    return maxin;
}

long int argmin(const std::vector<double> & u){
    auto minit = std::min_element(u.begin(),u.end());
    auto minin = std::distance(u.begin(),minit);

    return minin;
}

//Calcula la norma p de un vector
double p_norm(const std::vector<double> & u, long long int p){
    double sum{0};
    
    for (auto val : u){
        sum+=std::pow(val,p);
    }

    return std::pow(sum,1.0/p);
}

//Calcula la mediana de un vector
double median(std::vector<double> u){

    std::sort(u.begin(),u.end());
    long long int N=u.size();
    double result{0};

    if (N%2!=0){
        result = u[ ( (N+1)/2 ) - 1 ];
    } else {
        result = ( u[ (N/2) - 1 ] + u[ (N/2) ] ) / 2.0;
    }
    
    return result;
}   

//Calcula el percentil i de un vector
double percentil(std::vector<double> u, double i){

    std::sort(u.begin(),u.end());

    long long int N = u.size();
    double aux = (N*i)/100.0;
    double E{0};
    double result{0};

    double D = std::modf(aux, &E);
    long long int index = static_cast<long long int>(E);

    if (D==0){
        result = (u[E-1] + u[E]) / 2.0;
    } else {
        result = u[E];
    }
    
    return result;
}

// Rellena un vector con números aleatorios
void fill_randomly(std::vector<double> & u){
    srand(time(0));
    long long int N=u.size();

    for (long long int ii{0}; ii<N; ii++){
        u[ii]=rand();
    }
}

//Calcula el histograma de un vector de enteros
void int_counter_histogram(std::vector<int> u){
    std::sort(u.begin(),u.end());
    int aux=u[0];
    int num{0};
    std::vector<int> result;
    long long int count{0};

    for (const auto &val : u){
        if (val==aux){
            count++;
        }   else {
            result.push_back(aux);
            result.push_back(count);
            count=1;
            num++;
            aux=val;
        }
    }

    result.push_back(aux);
    result.push_back(count);
    num++;

    for (int ii{0}; ii < num; ii++){
        std::cout << result[ii*2] << "|";

        for (int kk{0}; kk<result[ii*2+1]; kk++){
            std::cout << "*";
        }

        std::cout << "\n";
    }

}

//Calcula un vector de Weibull
std::vector<double> weibull_vector(int N, double shape, double scale, int seed){

    std::vector<double> result;
    std::mt19937 gen(seed);
    std::weibull_distribution<double> weibull(shape, scale);
    
    for (int ii{0}; ii < N; ii++){
        result.push_back(weibull(gen));
    }
    
    return result;
}

std::vector<double> dbl_counter_histogram(const std::vector<double> & u, double delta){

    const double max_element=u[argmax(u)];
    const double min_element=u[argmin(u)];
    const long long int intervals = static_cast<int>(std::ceil((max_element - min_element) / delta));
    std::vector<double> result(2*intervals,0.0);
    long long int idx{0};
    

    for (int ii = 0; ii < intervals; ii++){
        result[ii*2]=min_element + (ii+1)*delta;
    }
   
    for (const auto &val : u){
        if (val==min_element){
            idx=0;
        } else {
        idx = static_cast<int>(std::floor( (val-min_element) / delta ));
        }
        
        result[idx*2+1]++;
    }

    return result;
}

// Calcular el producto escalar entre dos vectores. 
double dot_product(const std::vector<double> &v1, const std::vector<double> &v2) {
    if (v1.size() != v2.size()) {
        throw std::runtime_error("Los vectores deben tener el mismo tamaño para calcular el producto escalar.");
    }
    // std::inner_product(primer_inicio, primer_fin, segundo_inicio, valor_inicial)
    // El cuarto argumento es el valor inicial de la suma.
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0.0);
}

// Usa la libreria estándar para ordenar un vector
// Usamos una plantilla para que funcione con cualquier tipo de vector (int, double, etc.)
template <typename T>
void sort_vector(std::vector<T> &vec) {
    std::sort(vec.begin(), vec.end());
}

// Crea un vector de enteros y luego usar std::shuffle para mezclarlos aleatoriamente.
std::vector<int> create_and_shuffle_int_vector(int size, int min_val, int max_val) {
    if (size <= 0) return {};

    std::vector<int> vec(size);
    // Llenar el vector con valores secuenciales o aleatorios iniciales
    // Aquí lo llenaremos con valores secuenciales para que el efecto de shuffle sea claro.
    // Si quieres valores aleatorios iniciales, usa std::uniform_int_distribution.
    for (int i = 0; i < size; ++i) {
        vec[i] = min_val + (max_val - min_val) * i / (size - 1.0); // Escalado lineal
        if (size == 1) vec[i] = min_val; // Evitar división por cero si size es 1
    }

    // Inicializar el motor de números aleatorios
    // std::random_device es una fuente de entropía no determinista (si está disponible)
    // std::mt19937 es un generador de números pseudoaleatorios de Mersenne Twister
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
    // También podrías usar std::random_device rd; std::mt19937 rng(rd()); para una semilla más aleatoria

    // Mezclar el vector aleatoriamente
    std::shuffle(vec.begin(), vec.end(), rng);

    return vec;
}

// Es importante definir las especializaciones explícitas para la plantilla
// si no están en el encabezado o si se compilan por separado.
// Para el uso directo en un único archivo cpp, el compilador las instanciará.
// Si tuvieras sort_vector en un .cpp separado de main.cpp,
// tendrías que instanciar explícitamente:
// template void sort_vector<int>(std::vector<int> &vec);
// template void sort_vector<double>(std::vector<double> &vec);