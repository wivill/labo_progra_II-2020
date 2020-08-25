# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
# IE0724 - Laboratorio 2 - C++: Distancia euclidiana entre puntos.
# OS: Ubuntu 20.04 Focal Fossa
# C++: ISO C++17
#
# Autor: Willy Villalobos Marrero
# Correo: willy.villalobos@ucr.ac.cr
#
# Descripción: Makefile básico para proyectos en ISO C++17.
#
# Git repo: https://github.com/wivill/labo_progra_II-2020.git
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Entradas y otras definiciones útiles.
SRC=laboratorio2.cpp
EXE=laboratorio2

# Compila y ejecuta el programa
all: compile_prod

# Compila el programa con banderas para considerar advertencias como errores.
# Optimizado para producción.
compile_prod:
	g++ ${SRC} -o ${EXE}.exe -Wall -Werror -Wpedantic -Wextra -std=c++1z -O3 

# Optimizado para depuración.
compile_debug:
	g++ ${SRC} -o ${EXE}.exe -Wall -Werror -Wpedantic -Wextra -std=c++1z -O0 -g 

# Sin optimización.
compile:
	g++ ${SRC} -o ${EXE}.exe -Wall -Werror -Wpedantic -Wextra -std=c++1z 

# Compila sin ninguna opción o bandera adicional.
raw_compile:
	g++ ${SRC} -o ${EXE}.exe 

# Ejecuta el programa
run:
	./${EXE}.exe 

# Limpia el espacio de trabajo.
clean:
	rm -rf ${EXE}.exe 