#include <iostream> // Para std::cout, std::cerr
#include <fstream>  // Para std::ifstream, std::ofstream
#include <vector>   // Para std::vector
#include <string>   // Para std::string (para std::to_string si se usa en el nombre de archivo)
#include <iomanip>  // Para std::fixed, std::setprecision (opcional, para formato de salida)

// Estructura para almacenar cada punto de datos (tiempo y aceleración)
struct DataPoint {
    double time;
    double acceleration;
};

int main() {
    std::string input_filename = "accel.txt"; // Nombre del archivo de entrada
    std::string output_filename = "velocity_data.txt"; // Nombre del archivo de salida
    
    std::ifstream inputFile(input_filename);   // Objeto para leer el archivo de entrada

    // 1. Verificar si el archivo de entrada se abrió correctamente
    if (!inputFile.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de entrada '" << input_filename << "'\n";
        return 1; // Salir con código de error
    }

    std::vector<DataPoint> data_points; // Vector para almacenar los puntos de tiempo y aceleración
    double time_val, acceleration_val; // Variables temporales para lectura

    // 2. Leer los datos del archivo de entrada
    while (inputFile >> time_val >> acceleration_val) {
        data_points.push_back({time_val, acceleration_val}); // Agrega el par al vector
    }

    inputFile.close(); // Cierra el archivo de entrada después de leer

    // 3. Verificar si se leyeron datos
    if (data_points.empty()) {
        std::cerr << "Error: El archivo de entrada '" << input_filename << "' está vacío o no contiene datos válidos.\n";
        return 1;
    }

    // 4. Abrir el archivo de salida para escritura
    std::ofstream outputFile(output_filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: No se pudo crear/abrir el archivo de salida '" << output_filename << "' para escritura.\n";
        return 1;
    }

    // 5. Calcular la velocidad por integración numérica y escribir los resultados
    double current_velocity = 0.0; // Asumimos velocidad inicial en t=0 es 0.0
    
    // Escribir el encabezado en el archivo de salida y consola
    outputFile << "Tiempo\tVelocidad\n";
    outputFile << "-------------------------\n";
    std::cout << "Tiempo\tAceleración\tVelocidad\n";
    std::cout << "----------------------------------------\n";
    
    // Imprimir el primer punto de datos con su velocidad inicial calculada
    // Asumimos que la aceleración del primer punto (data_points[0].acceleration)
    // es constante desde t=0 hasta data_points[0].time.
    double initial_dt = data_points[0].time;
    current_velocity = data_points[0].acceleration * initial_dt;
    
    std::cout << std::fixed << std::setprecision(2) 
              << data_points[0].time << "\t" 
              << data_points[0].acceleration << "\t\t"
              << current_velocity << " (Velocidad en el primer punto de datos)\n";
    
    outputFile << std::fixed << std::setprecision(2) // Formato de salida para el archivo
               << data_points[0].time << "\t" << current_velocity << "\n";
    
    double prev_time = data_points[0].time; // Tiempo del punto anterior para calcular delta_time

    // Iterar desde el segundo punto de datos
    for (size_t i = 1; i < data_points.size(); ++i) {
        double current_time = data_points[i].time;
        double current_acceleration = data_points[i].acceleration;
        
        double delta_time = current_time - prev_time;
        
        // Integración numérica: Velocidad = Velocidad_anterior + Aceleración_actual * Delta_tiempo
        current_velocity += current_acceleration * delta_time; 
        
        // Imprimir en consola
        std::cout << std::fixed << std::setprecision(2) // Formato para consola
                  << current_time << "\t" 
                  << current_acceleration << "\t\t" 
                  << current_velocity << "\n";
        
        // Escribir en el archivo de salida
        outputFile << std::fixed << std::setprecision(2) // Formato para el archivo
                   << current_time << "\t" << current_velocity << "\n";
        
        prev_time = current_time; // Actualiza el tiempo anterior para la siguiente iteración
    }

    // 6. Cerrar el archivo de salida
    outputFile.close();
    std::cout << "\nDatos de velocidad guardados en '" << output_filename << "'\n";

    return 0; // Salir con éxito
}