/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 11/11/2025
*
*       El objetivo del programa es permitir al usuario definir
*	el número de hilos que OpenMP usará para ejecutar una región
*	paralela, mostrando los identificadores de cada hilo y el número
*	máximo de núcleos disponibles en el sistema.
***********************************************************/


#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	// Verifica los parametros por consola 
	if (argc != 2){
		printf("Error: \n\t$./ejecutable numhilos\n");
		exit(0);
	}

	// Convierte el argumento al numero de hilos, conversion a enteros
	int numHilos = (int) atoi(argv[1]);
	// Obtiene el numero maximo de hilos (cores) que el sistema soporte 
	int maxCores = omp_get_max_threads();

	printf("Numero maximo de cores SO: %d \n", maxCores);
	// Fija el numero de hilos que se usaran 
	omp_set_num_threads(numHilos);
	printf("Numero hilos fijados: %d \n", numHilos);
	// Region paralel, donde cada hilo imprime su ID
	#pragma omp parallel
	{
		printf("Hilo ID en Region Paralela: %d \n", omp_get_thread_num());
	}
}
