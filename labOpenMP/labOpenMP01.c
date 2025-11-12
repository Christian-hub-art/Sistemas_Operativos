/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 11/11/2025
*
*	El objetivo del programa es mostrar el uso básico de OpenMP
*	para ejecutar código en paralelo, creando varios hilos que imprimen
*	su identificador, demostrando así cómo se distribuye el trabajo entre ellos.
*
***********************************************************/


#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	// Muestra el numero maximo de hilos que puede usar openMP en el sistema
	printf("OpenMP ejecutando con %d hilos, numero maximo de hilos del SO %d\n", omp_get_max_threads(), omp_get_max_threads());
	// Inicia una region paralela con openMP
	#pragma omp parallel
	{
		// Cada hilo dentro de la region paralela ejecutara este bloque 
		printf("Hola desde el hilo: %d\n", omp_get_thread_num());
	}

	return 0;

}
