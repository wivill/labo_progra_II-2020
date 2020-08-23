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
using namespace std;

// Definición de variables a emplear durante la ejecición del programa.
int num_puntos;
float coord_x, coord_y;
char coma;

int main () {
    cout << "Este es un programa que le ayudará a calcular la distancia máxima y mínima entre cualquier par de puntos, entre una lista de puntos." << endl;
    cout << "¿Cuántos puntos va a introducir?: ";
    cin >> num_puntos;
    cout << num_puntos << endl;

    float puntos[num_puntos][2];

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
        puntos[i][0] = coord_x;
        puntos[i][1] = coord_y;

        cout << "(" << puntos[i][0] << coma << puntos[i][1] <<")" << endl;
    }

    return 0;
}