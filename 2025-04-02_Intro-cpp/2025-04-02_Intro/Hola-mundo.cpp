/*Este es un primer proyecto de prueba que simplemente ejecuta la salida "¿Hola?"
tal como tradicionalmente se hace en programación con "Hola mundo".
El objetivo es verificar que el compilador y el entorno de desarrollo están correctamente configurados.
Todo lo que esté entre los simbolos de comentario, como este párrafo o las lineas con "//", no se ejecuta y es ignorado por el compilador. 
*/ 

    /*Para iniciar, se añade una librería que incluye los comandos básicos de entrada y salida.
    Las librerías son archivos que contienen código que se puede reutilizar en el programa.
    Para informar al compilador de que deseamos utilizar alguna de las funcionalidades de una biblioteca (en este caso "iostream"), 
    es necesario incluir su archivo de cabecera (header file) asociado, típicamente al principio del archivo.
    */

//Así se incluyen las librerías en C++.
#include <iostream>

    /*Ahora se define la función principal del programa.
    Esta función se llama main.
    Las funciones son bloques de código que realizan una tarea específica.
    En C++, la función main es el punto de entrada del programa, es decir, donde comienza la ejecución.
    Aquí main no recibe argumentos ((void)) y devuelve un entero (int) que indica el éxito del programa. 
    Luego, todo lo que esté entre corchetes ({}) es el cuerpo de la función.
    */

//Así se define la función main en C++.
int main(void) { 
    std::cout <<"¿Hola?\n"; // Comando básico para imprimir en pantalla. Se debe poner entre comillas dobles ("") el texto que se quiere mostrar.
    /* Nota: El uso de std:: es necesario porque cout es parte del espacio de nombres std (standard).
    Si no se desea usar std::, se puede añadir la línea "using namespace std;" después de incluir la librería iostream.
    Sin embargo, es una buena práctica mantener el uso de std:: para evitar conflictos con otros nombres en el código.
    La \n al final de la cadena indica un salto de línea, lo que significa que después de imprimir "¿Hola?", el cursor se moverá a la siguiente línea.
    Eso es útil para que la salida sea más legible.
    */
    return 0; // La función main retorna un entero: '0' para indicar que todo ha ido bien, cualquier otro número para indicar algún error.
}

/*Los punto y coma (;) al final de cada línea son necesarios en C++ para indicar el final de una instrucción.
No se ponen punto y coma después de las llaves que delimitan el cuerpo de la función o de las estructuras de control (como if, for, etc.),
ni al indicar los nombres de las librerías. 
*/

/* Compilación y ejecución:
Para compilar este código, se puede usar un compilador de C++ como g++:
Parado en la terminal, en el directorio donde se guarda el archivo Hola-mundo.cpp, se usa la siguiente línea de comando:
g++ Hola-mundo.cpp
Luego, para ejecutar el programa, se puede usar:
./Hola-mundo
o también: ./a.out
Este programa es un ejemplo básico de cómo se estructura un programa en C++.
*/