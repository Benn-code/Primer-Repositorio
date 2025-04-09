/*
Juego de adivinar un número
Tener un número 
Preguntar al usuario un número
Informar si lo adivinó o no
*/
#include <iostream>

int main(void) {
    const int NUM = 10;
    int guessed_number;
    std::cout <<"Adivina un número entre 1 y 100:\n";
    std::cin >> guessed_number;

if (guessed_number == NUM) {
    std::cout <<"Muy bien, ¡era ese!\n";
}
    return 0;
}