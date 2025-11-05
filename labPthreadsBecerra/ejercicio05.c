/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
*
*       Este programa tiene como objetivo demostrar el efecto 
*	de la concurrencia en el acceso a variables compartidas
*	y la importancia de usar mecanismos de sincronización 
*	(como mutex) en programación con hilos.
*
***********************************************************/
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>


// Variable global para acumular los cuadrados
int acumulado = 0; 
// Función que calcula el cuadrado del número recibido y lo suma al acumulado
void *cuadrados (void *x){
	//Convertir el argumento void* a int
	int x1 = (intptr_t)x;
	//Sumar el cuadrado del numero amulado
	acumulado += x1*x1;
	return NULL;
}

int main (int argc, char *argv[]){
	//Arreglo de 20 hilos 
	pthread_t hilos[20];
	// Crear 20 hilos que calculan el cuadrado de los números del 1 al 20
	for(int i = 0; i < 20 ; i++){
		pthread_create(&hilos[i], NULL, cuadrados, (void *)(intptr_t)(i+1));
	}
	// Esperar a que todos los hilos terminen
	for(int i = 0; i < 20; i++){
		void *resultado; 
		pthread_join(hilos[i], &resultado);
	}
	//Mostrar el resultado acumulado 
	printf("Acumulado = %d\n", acumulado);
	return 0;
}

/* Sin mutex, los hilos se intercalan de manera no 
determinista, provocando resultados inconsistentes debido 
a condiciones de carrera.  */
