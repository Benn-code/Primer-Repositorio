#include <iostream>
#include <valarray> // Para std::valarray
#include <cmath>    // Para std::sqrt, std::sin, etc.
#include <numeric>  // Para std::iota (útil para inicializar)

// Función auxiliar para imprimir un valarray
void print_valarray(const std::valarray<double>& va, const std::string& name) {
    std::cout << name << " = [";
    for (size_t i = 0; i < va.size(); ++i) {
        std::cout << va[i] << (i == va.size() - 1 ? "" : ", ");
    }
    std::cout << "]\n";
}

int main() {
    // 1. Construcción
    std::valarray<double> va1(5); // valarray de 5 doubles, inicializados a 0.0
    print_valarray(va1, "va1 (default)");

    std::valarray<double> va2(3.14, 4); // valarray de 4 doubles, todos 3.14
    print_valarray(va2, "va2 (fill)");

    std::valarray<double> va3 = {1.0, 2.0, 3.0, 4.0, 5.0}; // Inicialización con lista
    print_valarray(va3, "va3 (list)");

    // 2. Operaciones Element-wise
    std::valarray<double> va4 = va3 * 2.0; // Multiplicar cada elemento por 2
    print_valarray(va4, "va4 = va3 * 2.0");

    std::valarray<double> va5 = va3 + va4; // Suma elemento a elemento
    print_valarray(va5, "va5 = va3 + va4");

    // Aplicar funciones matemáticas
    std::valarray<double> va_sqrt = std::sqrt(va3); // Raíz cuadrada de cada elemento
    print_valarray(va_sqrt, "va_sqrt = sqrt(va3)");

    std::valarray<double> va_sin = std::sin(va3); // Seno de cada elemento
    print_valarray(va_sin, "va_sin = sin(va3)");

    // 3. Operaciones de agregación
    std::cout << "Suma de va3: " << va3.sum() << "\n";
    std::cout << "Min de va3: " << va3.min() << "\n";
    std::cout << "Max de va3: " << va3.max() << "\n";
    std::cout << "Tamaño de va3: " << va3.size() << "\n";

    // 4. Slicing con std::slice (para acceder a sub-rangos regulares)
    // slice(start, count, stride)
    // Acceder a los elementos pares (índice 0, 2, 4...)
    std::valarray<double> va_even_indices = va3[std::slice(0, (va3.size() + 1) / 2, 2)];
    print_valarray(va_even_indices, "va3[even_indices]");

    // Acceder a los elementos impares (índice 1, 3...)
    std::valarray<double> va_odd_indices = va3[std::slice(1, va3.size() / 2, 2)];
    print_valarray(va_odd_indices, "va3[odd_indices]");

    // Modificar elementos usando slice
    va3[std::slice(0, (va3.size() + 1) / 2, 2)] = 99.0; // Cambiar elementos pares a 99.0
    print_valarray(va3, "va3 after even_indices modification");

    // 5. Slicing con std::mask_array (para acceso condicional)
    // Crear una máscara booleana (true si el elemento es > 3.0)
    std::valarray<bool> mask = (va3 > 3.0); 
    std::cout << "Mask (va3 > 3.0): [";
    for (size_t i = 0; i < mask.size(); ++i) {
        std::cout << (mask[i] ? "true" : "false") << (i == mask.size() - 1 ? "" : ", ");
    }
    std::cout << "]\n";

    std::valarray<double> va_filtered = va3[mask]; // Obtener elementos donde la máscara es true
    print_valarray(va_filtered, "va_filtered (va3 > 3.0)");

    // Modificar elementos usando mask
    va3[mask] = 0.0; // Cambiar elementos > 3.0 a 0.0
    print_valarray(va3, "va3 after mask modification (va3 > 3.0)");

   // 6. Slicing con std::indirect_array (para acceso por índices arbitrarios)
    std::valarray<size_t> indices = {0, 4, 2}; // Índices en un orden arbitrario

    // CORRECCIÓN: Simplemente pasa el std::valarray<size_t> 'indices' directamente
    // El operador[] de va3 se encargará de crear y usar el proxy std::indirect_array internamente.
    std::valarray<double> va_indirect = va3[indices];
    print_valarray(va_indirect, "va_indirect (indices 0, 4, 2)");

    // Modificar elementos usando indirect_array
    // CORRECCIÓN: De nuevo, simplemente pasa el std::valarray<size_t> 'indices'.
    va3[indices] = -1.0; // Cambiar elementos en esos índices
    print_valarray(va3, "va3 after indirect_array modification");

    return 0;
}