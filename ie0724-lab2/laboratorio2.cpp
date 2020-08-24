/*
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
# IE0724 - Laboratorio 2 - C++: Distancia euclidiana entre puntos.
# OS: Ubuntu 20.04 Focal Fossa
# C++: ISO C++17
#
# Autor: Willy Villalobos Marrero
# Correo: willy.villalobos@ucr.ac.cr
#
# Descripción: Este programa calcula la distancia euclidiana de una serie 
# de puntos euclidianos en un espacio de dos dimensiones. La cantida de
# puntos, así como sus coordenadas, son provistos por el usuario de manera
# interactiva. El programa devuelve los pares de puntos cuya distancia es
# mayor y menor.
#
# Git repo: https://github.com/wivill/labo_progra_II-2020.git
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

#include <iostream> // Interacción básica con el usuario, prints, etc.
#include <string> // Manipulación de strings.
#include <cmath> // Operaciones matemáticas como sqrt.
using namespace std;

// Definición de variables a emplear durante la ejecición del programa.
float coord_x, coord_y, dist_min, dist_max, distancia;
char coma;

int main () {
    // Se define un arreglo de datos para almacenar los pares ordenados que ingrese el usuario.
    const size_t filas = 2;
    float** puntos; 
    float** puntos_min; 
    float** puntos_max; 
    int num_puntos;
    int index_min = 0; 
    int index_max = 0;

    // Mensajes de bienvenida y solicitud de tamaño del arreglo.
    cout << "Este es un programa que le ayudará a calcular la distancia máxima y mínima entre cualquier par de puntos, entre una lista de puntos." << endl;
    cout << "¿Cuántos puntos va a introducir?: ";
    cin >> num_puntos;

    // Revisa si el dato es válido.
    if (!cin) {
        cerr << "Ha ingresado un valor no permitido." << endl;
        return 1;

    }

    // Revisa si es mayor o igual a 2.
    if (num_puntos < 2) {
        cerr << "Debe ingresar un valor mayor o igual a 2." << endl;
        return 1;

    }

    cout << "Ha ingresado " << num_puntos << "." << endl;

    // Crea los arreglos para almacenar los pares ordenados ingresados y los que tienen los puntos
    // con la misma distancia máxima y mínima.
    puntos = new float*[filas];
    puntos_min = new float*[filas];
    puntos_max = new float*[filas];

    // Bucles para inicializar el arreglo de pares ordenados, así como los de menor y mayor distancia.
    for (size_t i = 0; i < filas; ++i) {
        puntos[i] = new float[num_puntos];

    }

    for (size_t j = 0; j < filas; ++j) {
        puntos_min[j] = new float[(num_puntos/2) + 1];

    }

    for (size_t k = 0; k < filas; ++k) {
        puntos_max[k] = new float[(num_puntos/2) + 1];

    }

    // Bucle para inicializar los pares oredenados.
    for (int l = 0; l < num_puntos; l++) {
        cout << "Digite un punto bidimensional de la forma X.x,Y.y: ";
        cin >> coord_x;
        cin >> coma;
        cin >> coord_y;

        // Revisa si el dato ingresado corresponde al tipo de dato esperado (¿Es un número?).
        if (!cin) {
            cerr << "Ha ingresado un valor no permitido." << endl;
            break; // Valorar cambiar a continue y simplemente dar menos puntos.

        }

        // Guarda el par ordenado ingresado en la matriz de pares de puntos.
        puntos[0][l] = {coord_x};
        puntos[1][l] = {coord_y};

        cout << "Ha ingresado el par ordenado (" << puntos[0][l] << coma << puntos[1][l] <<")" << endl;

    }

    // Cálculo de distancia máxima y mínima entre los puntos.
    for (int i = 0; i < num_puntos; i++) {
        for (int j = 1; j < num_puntos; j++) {
            distancia = sqrt(pow(puntos[0][i] - puntos[0][j], 2) + pow(puntos[1][i] - puntos[1][j], 2));
            cout << distancia << endl;
            // Revisa si es la primera ejecución para determinar cómo se asignará la distancia calculada.
            if (num_puntos == 2) {
                dist_max = distancia;
                continue;

            } else if (i == 0 && j == 1) {
                dist_max = distancia;
                dist_min = distancia;

            } else if (distancia == dist_min) {
                // Si la distancia calculada es igual a la distancia mínima, se agrega el par de puntos resultante
                // al arreglo de puntos de distancia mínima.
                puntos_min[0][index_min] = puntos[0][i];
                puntos_min[1][index_min] = puntos[1][i];
                puntos_min[0][index_min + 1] = puntos[0][j];
                puntos_min[1][index_min + 1] = puntos[1][j];
                index_min = index_min + 2; 

            } else if (distancia < dist_min) {
                // Reinicia el índice del arreglo de distancia mínima y almacena los puntos correspondiente.s
                index_min = 0;
                puntos_min[0][index_min] = puntos[0][i];
                puntos_min[1][index_min] = puntos[1][i];
                puntos_min[0][index_min + 1] = puntos[0][j];
                puntos_min[1][index_min + 1] = puntos[1][j];
                index_min = index_min + 2; 

            } else if (distancia == dist_max) {
                // Si la distancia calculada es igual a la distancia máxima, se agrega el par de puntos resultante
                // al arreglo de puntos de distancia máxima.
                puntos_max[0][index_max] = puntos[0][i];
                puntos_max[1][index_max] = puntos[1][i];
                puntos_max[0][index_max + 1] = puntos[0][j];
                puntos_max[1][index_max + 1] = puntos[1][j];
                index_max = index_max + 2;

            } else if (distancia > dist_max) {
                // Reinicia el índice del arreglo de distancia máxima y almacena los puntos correspondientes.
                index_max = 0;
                puntos_max[0][index_max] = puntos[0][i];
                puntos_max[1][index_max] = puntos[1][i];
                puntos_max[0][index_max + 1] = puntos[0][j];
                puntos_max[1][index_max + 1] = puntos[1][j];
                index_max = index_max + 2;

            } else {
                continue;

            }

        }
    }
 
    // Procedemos a imprimir los resultados.
    if (num_puntos == 2) {
        cout << "La distancia entre los puntos (" << puntos[0][0] << coma << puntos[1][0] << ") y (" << puntos[0][1] << coma << puntos[1][1] << ") es: " << dist_max << "." << endl;
    
    } else {
        cout << "La distancia mínima se da entre los puntos: ";

        for (int m = 0; m < index_min; m = m + 2) {
            cout << "(" << puntos_min[0][m] << coma << puntos_min[1][m] << ") y (" << puntos_min[0][m + 1] << coma << puntos_min[1][m + 1] << "), ";

        }

        cout << endl;

        cout << "La distancia máxima se da entre los puntos: ";

        for (int m = 0; m < index_max; m = m + 2) {
            cout << "(" << puntos_max[0][m] << coma << puntos_max[1][m] << ") y (" << puntos_max[0][m + 1] << coma << puntos_max[1][m + 1] << "), ";

        }

        cout << endl;

    }

    // Borramos el arreglo de pares de puntos para evitar problemas de memoria.
    for (size_t i = 0; i < filas; ++i) {
        delete [] puntos[i];
        delete [] puntos_max[i];
        delete [] puntos_min[i];
        
    }

    delete [] puntos;
    delete [] puntos_max;
    delete [] puntos_min;

    return 0;
}