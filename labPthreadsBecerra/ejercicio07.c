/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
*
*       En este programa, dos hilos acceden a una variable
*	compartida (`valor`) sin utilizar
* 	ningún tipo de sincronización (ni mutex ni variable
*	de condición).
*
* 	Un hilo (reportar) imprime el valor actual y otro
*	(asignar) lo modifica.
* 	Como no hay control de acceso concurrente, el hilo
*	reportador podría ejecutar antes
* 	de que el valor haya sido actualizado, provocando
*	resultados inconsistentes.
* 	Este código sirve para observar el efecto de una
*	condición de carrera (CC).
*
***********************************************************/
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


// Valor compartido entre hilos
int valor = 100;
// Bandera que si indica si se cambio el valor
bool notificar = false;

//funcion impirmir valor actual
void *reportar (void *nousado){

	if(!notificar){
		printf(" El valor es: %d \n", valor);
	}else{
		printf("El valor actualizado es: %d\n", valor);
	}
	return NULL;
}
//funcion para modificar valor
// Actualiza la variable `valor` sin proteger 
//el acceso con un mutex.
//Esto puede interferir con el hilo `reportar` si se 
//ejecutan simultáneamente.
void *asignar (void *nousado){
	valor = 20;
	
	notificar = true; 
	
	return NULL; 
}
// funcion donde se ejecutan dos hilps con condicion CC sin mutex 
int main (int argc, char *argv[]){
	//Se declara dos hilos 
	pthread_t reporte, asigne; 
	
	pthread_create(&reporte, NULL, reportar, NULL);
	pthread_create(&asigne, NULL, asignar, NULL);
	
	void *nousado;
	//Se espera a que ambos hilos terminen
	pthread_join(reporte, &nousado);
	pthread_join(asigne, &nousado);
	return 0;
}



