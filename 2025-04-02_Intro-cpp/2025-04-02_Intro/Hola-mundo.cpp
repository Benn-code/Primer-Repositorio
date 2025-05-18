/*Este es un primer proyecto de prueba que simplemente ejecuta la salida "¿Hola?"
tal como tradicionalmente se hace en programación con "Hola mundo".
El objetivo es verificar que el compilador y el entorno de desarrollo están correctamente configurados.
*/

//Para iniciar se añade una librería que incluye los comandos basicos de entrada y salida
#include <iostream>

/*Ahora se define la función principal del programa.
Esta función se llama main.
Aquí main no recibe argumentos ((void)) y devuelve un entero (int). 
Luego, todo lo que esté entre corchetes ({}) es el cuerpo de la función.
*/
int main(void) {
    std::cout <<"¿Hola?\n"; //Comando básico para imprimir en pantalla.
    return 0; // La función main devuelve un entero, 0 para indicar que todo ha ido bien, cualquier otro valor para indicar un error.
}