/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
*
*	Este programa elimina la condición de carrera del 
*	ejemplo anterior.
* 	Utiliza un `pthread_mutex_t` para proteger el acceso a
*	las variables compartidas
* 	y una `pthread_cond_t` para coordinar el orden de 
*	ejecución entre los hilos.
*
* 	El hilo `reportar` espera a ser notificado mediante 
*	una señal de condición
* 	antes de imprimir el valor actualizado, garantizando 
*	que el resultado sea siempre consistente.
*
***********************************************************/
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


// valor compartido entre hilos 
int valor = 100;
// Bandera que indica si el valor ya fue actualizado
bool notificar = false; 
//Mutex de exclusion mutua 
pthread_mutex_t bloqueoCC = PTHREAD_MUTEX_INITIALIZER;
//Variable de condicion
pthread_cond_t var_cond = PTHREAD_COND_INITIALIZER;
//Hilo que espera a ser notificado para imprimir el valor actualizado.
void *reportar (void *nousado){
	pthread_mutex_lock(&bloqueoCC);
	// Espera activa controlada
	while(!notificar){
		pthread_cond_wait(&var_cond, &bloqueoCC);
	}
	printf("El valor es: %d\n", valor);
	return NULL;
}

//Hilo que cambia el valor y notifica al otro hilo.
void *asignar (void *nousado){
	valor = 20;
	// Bloquea para evitar que otro hilo acceda simultaneamente 
	pthread_mutex_lock( &bloqueoCC );
	//Bandera de qeu ya fue modificado
	notificar = true;
	//Depsierta la hilo para que siga con la ejecucion
	pthread_cond_signal(&var_cond);
	//Libera para que otros hilos puedan acceder a las variables
	pthread_mutex_unlock(&bloqueoCC);
	return NULL; 
}
// Funcion donde crea dos hilos uno para asignar el valor y otro para reportarlo.
int main (int argc, char *argv[]){
	//Se declaran los dos hilos 
	pthread_t reporte, asigne; 
	//Se crean ambos hilos
	pthread_create(&reporte, NULL, reportar, NULL);
	pthread_create(&asigne, NULL, asignar, NULL);
	
	void *nousado;
	//Se espera a que termine cada hilo
	pthread_join(reporte, &nousado);
	pthread_join(asigne, &nousado);
	return 0;
}



