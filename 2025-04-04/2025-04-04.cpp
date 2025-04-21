#include <iostream>
#include <string>

int main(void) {
    std::string nombre;  // Variable para almacenar el nombre del usuario

    // Pedir al usuario que ingrese su nombre
    std::cout << "¿Cómo te llamas? ";
    std::getline(std::cin, nombre);  // Obtener el nombre ingresado

    // Saludar al usuario
    std::cout << "¡Hola, " << nombre << "!" << std::endl;

    return 0;
}