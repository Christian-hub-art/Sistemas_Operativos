/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
*
*       El objetivo del programa es demostrar el uso correcto
*	de sincronización mediante pthread_mutex en entornos
*	concurrentes, evitando condiciones de carrera al
*	modificar variables compartidas entre múltiples hilos.
*
***********************************************************/
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>


//Variable global que almacena la suma de los cuadrados.
int acumulado = 0;
//Mutex para controlar acceso concurrente a `acumulado`.
pthread_mutex_t bloqueoCC = PTHREAD_MUTEX_INITIALIZER;

void *cuadrados (void *x){
	int x1 = (intptr_t)x;
	//seccion para el control de cada hilo
	pthread_mutex_lock ( &bloqueoCC );
	acumulado += x1*x1;
	// seccion para finalizar con la accion de ese hilo
	pthread_mutex_unlock ( &bloqueoCC ); 
	return NULL;
}

int main (int argc, char *argv[]){
	//Arreglo de 20 hilos para ejecutar la funcion cuadrados 
	pthread_t hilos[20];
	//Creacion de los hilos 
	for(int i = 0; i < 20 ; i++){
		pthread_create(&hilos[i], NULL, cuadrados, (void *)(intptr_t)(i+1));
	}
	//Esperar a que todos los hilos terminen 
	for(int i = 0; i < 20; i++){
		void *resultado; 
		pthread_join(hilos[i], &resultado);
	}
	//Imprimir el resultado final
	printf("Amulado = %d\n", acumulado);

}

/* Se crean 20 hilos que calculan el cuadrado de los números 
del 1 al 20 y los suman a una variable global protegida 
con un mutex, garantizando que el resultado final sea 
siempre consistente e igual a 2870, sin importar el orden 
de ejecución de los hilos.*/
