/*Este programa busca un número específico en un vector de enteros.
 * Si el número se encuentra, imprime su posición; si no, indica que no se encontró.
 * Utiliza un bucle for para recorrer el vector y una variable booleana para controlar el flujo.
*/

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 60;
    bool found = false;

    std::cout << "Buscando " << target << " en la lista:\n";

    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << "Revisando el número: " << numbers[i] << std::endl;
        if (numbers[i] == target) {
            std::cout << "¡Encontrado! El número " << target << " está en la posición " << i << ".\n";
            found = true;
            break; // ¡Sale del bucle for inmediatamente!
        }
    }

    if (!found) {
        std::cout << "El número " << target << " no se encontró en la lista.\n";
    }

    std::cout << "El programa continúa después del bucle.\n";

    return 0;
}
