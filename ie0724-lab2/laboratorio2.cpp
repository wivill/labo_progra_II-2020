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
# mayor y menor, así como los pares de puntos con distancias iguales.
#
# Git repo: https://github.com/wivill/labo_progra_II-2020.git
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

#include <iostream> // Interacción básica con el usuario, prints, etc.
#include <string> // Manipulación de strings.
#include <cmath> // Operaciones matemáticas como sqrt.
#include <vector> // Considerar alterlativas por temas de overhead.
using namespace std;

// Definición de variables a emplear durante la ejecición del programa.
float coord_x, coord_y;
char coma;

int main () {
    // Definimos un arreglo de datos para almacenar los pares ordenados que ingrese el usuario.
    const size_t filas = 2;
    float** puntos; 
    int num_puntos;

    // Mensajes de bienvenida y solicitud de tamaño del arreglo.
    cout << "Este es un programa que le ayudará a calcular la distancia máxima y mínima entre cualquier par de puntos, entre una lista de puntos." << endl;
    cout << "¿Cuántos puntos va a introducir?: ";
    cin >> num_puntos;

    // Revisamos si el dato es válido.
    if (!cin) {
        cerr << "Ha ingresado un valor no permitido." << endl;
        return 1;
    }

    // Revisamos si es mayor o igual a 2.
    if (num_puntos < 2) {
        cerr << "Debe ingresar un valor mayor o igual a 2." << endl;
        return 1;
    }

    puntos = new float*[filas];
    cout << "Ha ingresado " << num_puntos << "." << endl;

    // Bucle para inicializar el arreglo de pares ordenados.
    for (size_t i = 0; i < filas; ++i) {
        puntos[i] = new float[num_puntos];
    }

    // Bucle para inicializar los pares oredenados.
    for (int i = 0; i < num_puntos; i++) {
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
        puntos[0][i] = {coord_x};
        puntos[1][i] = {coord_y};

        cout << "Ha ingresado el par ordenado (" << puntos[0][i] << coma << puntos[1][i] <<")" << endl;
    }

    // Borramos el arreglo de pares de puntos para evitar problemas de memoria.
    for (size_t i = 0; i < filas; ++i) {
        delete [] puntos[i];
    }

    delete [] puntos;

    return 0;
}