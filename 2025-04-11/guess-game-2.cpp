/*
Juego de adivinar un número
Tener un número 
Preguntar al usuario un número
Informar si lo adivinó o no
*/
#include <iostream>
#include <random>

// declaracion
void play(int success, int min_val, int max_val);

int main(void) {
    play(1, 100);
    play(1, 200);

    return 0;
}

// implementacion
void play(int success, int min_val, int max_val)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution(min_val, max_val)

    const int NUM =

    int guessed_number = NUM/2;
    const int MIN = min_val;
    const int MAX = max_val;

    while(guessed_number != NUM) {
    std::cout <<"Adivina un número entre "<<MIN<<" y "<<MAX <<":\n";
    std::cin >> guessed_number;
    std::cout <<"Escribiste: " << guessed_number <<"\n";

    //Validación del rango
    if (guessed_number <= MIN or guessed_number > MAX){
        std::cout <<"Eso nisiquiera está dentro del rango, adiós.\n";
        break;
    }
    if (guessed_number == NUM) {
        std::cout <<"Muy bien, ¡era ese!\n";
     //Con el while, aquí habría el break en caso de acertar;
    } else if (guessed_number > NUM) {
    std::cout <<"Te pasaste\n";
    }      else { // es menor, no es necesario ponerlo, pues es la única posibilidad restante
    std::cout <<"Te falta\n"; }
    }
}