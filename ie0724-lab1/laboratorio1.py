#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
# IE0724 - Laboratorio 1 - Python 3: Números primos
# OS: Ubuntu 20.04 Focal Fossa
# Python: 3.8.2
#
# Autor: Willy Villalobos Marrero
# Correo: willy.villalobos@ucr.ac.cr
#
# Descripción: Este programa realiza la búsqueda de los números primos
#   menores a un número provisto por el usuario desde la terminal. El
#   algoritmo empleado es una versión de la Criba de Eratóstenes.
#
# Git repo: https://github.com/wivill/labo_progra_II-2020.git
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Imports
from math import sqrt  # Función sqrt para optimizar el algoritmo.
import sys  # Para recibir argumentos de la línea de comandos.


# Función Criba de Eratóstenes para determinar los números primos requeridos.
def criba(num_limite):
    # Primero creamos una lista vacía que contiene los números hasta el top y
    # la llenamos. Esta misma lista contendrá los primos resultantes.
    lista_primos = [i for i in range(2, num_limite + 1)]

    # Iteramos sobre el rango desde 2 (primer número primo) hasta el tope
    # provisto + 1. Se descartan los números ya incluidos en la lista y
    # solo conserva los que cumplan con el criterio del algoritmo.
    # Optimización falla para un límite bajo.
    if num_limite < 8:  
        for i in range(2, int(num_limite + 1)):
            if i in lista_primos:
                for j in range(i*2, num_limite + 1, i):
                    if j in lista_primos:
                        lista_primos.remove(j)
    else:
        for i in range(2, int(sqrt(num_limite + 1))):
            if i in lista_primos:
                for j in range(i*2, num_limite + 1, i):
                    if j in lista_primos:
                        lista_primos.remove(j)

    # Retornamos la lista de números primos.
    return lista_primos


# Main para recibir el número tope desde la terminal.
if __name__ == '__main__':
    print("Bienvenido!")

    try:
        num_ingresado = int(sys.argv[1])
        print(f"Ha ingresado el número {num_ingresado}. Calculando...")
        resultado = criba(num_ingresado)
        print("Listo! Estos son los números primos encontrados: ")
        print(resultado)
        print("Fin del programa.")

    except ValueError:
        print("Ha ingresado un valor que no es un número. Saliendo.")
