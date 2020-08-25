# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
# IE0724 - Laboratorio 2 - C++: Distancia euclidiana entre puntos.
# OS: Ubuntu 20.04 Focal Fossa
# C++: ISO C++17
#
# Autor: Willy Villalobos Marrero
# Correo: willy.villalobos@ucr.ac.cr
#
# Descripción: Instrucciones para laboratorio 2.
#
# Git repo: https://github.com/wivill/labo_progra_II-2020.git
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

Este programa calcula la distancia entre los puntos en una lista cuyo tamaño
y valores son provistos por el usuario. Se incluye un pequeño makefile para
poder compilar y ejecutar el programa fácilmente.

Instrucciones de compilación:
- Simplemente diríjase al directorio donde se encuentra el código fuente y
  escriba en la terminal:

  $ make

  Esto generará de una vez el ejecutable laboratorio2.exe. Las opciones de
  compilación usadas son:
    
    -Wall -Werror -Wpedantic -Wextra -std=c++1z -O3

  El resultado es el mismo si se compila para producción:

  $ make compile_prod

- Si desea compilar con banderas de depuración, escriba en la terminal:

  $ make compile_debug

- Si desea compilar sin banderas adicionales:

  $ make raw_compile

- Para compilar sin optimización:

  $ make compile

Instrucciones de ejecución:
- Para ejecutar el programa puede hacerlo ejecutando directamente el binario:

  $ ./laboratorio2.exe

  También puede hacerlo desde el makefile:

  $ make run

- El programa le solicitará indicar el número de puntos a los cuales desea calcularle
  la distancia. El valor mínimo de puntos es 2. Un valor menor a 2 o distinto a un 
  número generará un error.

  > Este es un programa que le ayudará a calcular la distancia máxima y mínima entre cualquier par de puntos, entre una lista de puntos.
  > ¿Cuántos puntos va a introducir?: __

- Luego deberá ingresar los pares ordenados con el formato X.x,Y.y. Le pedirá uno
  hasta asignar el total de puntos indicado previamente.

  > Digite un punto bidimensional de la forma X.x,Y.y: ___

- El programa calculará cada distancia y le devolverá los puntos cuya distancia es
  mínima y máxima. 

  > Distancia entre los puntos (1,1) y (1,1): 0
  > Distancia entre los puntos (1,1) y (1,2): 1
  > Distancia entre los puntos (1,1) y (2,1): 1
  > La distancia mínima se da entre los puntos: (1,1) y (1,1) 
  > La distancia máxima se da entre los puntos: (1,1) y (1,2) (1,1) y (2,1)