/* Este programa recibe un vector de coordenadas (3D) y tres ángulos de rotación para devolver la rotación de ese vector con esos ángulos. 
Main recibe seis argumentos de consola: 
tres para las coordenadas del vector original y tres para los valores de rotación (en radianes). 
Main envía ese vector y los angulos a una función que los rota (rotateVector), 
la cual utiliza la función multiplyMatrixVector para hacer las operaciones. 
Luego, main recibe el resultado y lo imprime.  
*/

#include <iostream>
#include <cmath>
//#include <iomanip> Se requiere solo en caso de dejar de comentar la línea 37
#include <vector>

//Declaración de funciones
std::vector <double> rotateVector(const std::vector<double>& originalCoords, double thetax, double thetay, double thetaz);
std::vector <double> multiplyMatrixVector(const std::vector<double>& matrix, const std::vector<double>& vector); 

int main(int argc, char **argv){
    if (argc != 7) { //Validar de los datos de entrada
        std::cerr <<"The program requires six inputs.\n"
                    "Use the first three to indicate the coordinates, and the remaining three (in radians) to indicate the rotation along each axis.\n"
                    "Example:" << argv[0] << " <vx> <vy> <vz> <thetax> <thetay> <thetaz>\n";
        return 1;
    }

    //Declar variables de entrada
    double vx = std::stod(argv[1]);
    double vy = std::stod(argv[2]);
    double vz = std::stod(argv[3]);
    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    //Enviar datos a función de rotación e imprimir resultado
    std::vector<double> original_coords = {vx, vy, vz};
    std::vector<double> new_coords = rotateVector(original_coords, thetax, thetay, thetaz);
    //std::cout << std::fixed << std::setprecision(7); // Para mayor precisión en la salida 
        //Había puesto la línea anterior buscando más precisión, pero me di cuenta de que quitándola las respuestas se imprimían tal y como las de los casos de prueba.
        //La dejo para otros contextos.
    std::cout << new_coords[0] << ", "
              << new_coords[1] << ", " << new_coords[2] << "\n";
    return 0;    
}

// Función para rotar un vector 3D dado un ángulo de rotación alrededor de los ejes X, Y y Z
std::vector <double> rotateVector(const std::vector<double>& original_coords, double thetax, double thetay, double thetaz){
    
   //Calcular senos y cosenos
    double cos_thetax = std::cos(thetax);
    double sin_thetax = std::sin(thetax);
    double cos_thetay = std::cos(thetay);
    double sin_thetay = std::sin(thetay);
    double cos_thetaz = std::cos(thetaz);
    double sin_thetaz = std::sin(thetaz);

    //Matrices de rotación 
    std::vector<double> rotationMatrixX={ //R_x
        1.0, 0.0, 0.0,
        0.0, cos_thetax, -sin_thetax,
        0.0, sin_thetax, cos_thetax
    };
    std::vector<double> rotationMatrixY={ //R_y
        cos_thetay, 0.0, sin_thetay,
        0.0, 1.0, 0.0,
        -sin_thetay, 0.0, cos_thetay 
    };
    std::vector<double> rotationMatrixZ={ //R_z
        cos_thetaz, -sin_thetaz, 0.0,
        sin_thetaz, cos_thetaz, 0.0,
        0.0, 0.0, 1.0
    };

    // Multiplicar las matrices de rotación por el vector original 
    std::vector<double> rotatedVectorX = multiplyMatrixVector(rotationMatrixX, original_coords);
    std::vector<double> rotatedVectorXY = multiplyMatrixVector(rotationMatrixY, rotatedVectorX);
    std::vector<double> finalRotatedVector = multiplyMatrixVector(rotationMatrixZ, rotatedVectorXY);

    return finalRotatedVector;
}

// Función para multiplicar una matriz 3x3 por un vector 3x1
std::vector<double> multiplyMatrixVector(const std::vector<double>& matrix, const std::vector<double>& vector) {
    const int N_ROWS = 3; // Número de filas del resultado (y de la matriz)
    const int N_COLS = 3; // Número de columnas de la matriz (y elementos del vector de entrada)

    // Creamos un nuevo vector para almacenar el resultado, inicializado con ceros.
    std::vector<double> result(N_ROWS, 0.0);

    // Bucle para cada fila del vector resultado
    for (int ii = 0; ii < N_ROWS; ++ii) {
        // Bucle para cada columna de la matriz (y elemento del vector de entrada)
        for (int jj = 0; jj < N_COLS; ++jj) {
            // Suma el producto del elemento de la matriz con el elemento del vector
            // Acceso a la matriz: matrix[fila * N_COLS + columna]
            result[ii] += matrix[ii * N_COLS + jj] * vector[jj];
        }
    }
    return result;
}



