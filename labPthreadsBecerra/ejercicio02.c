/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
*
*       Crear 10 threads que ejecutan una función que 
*	imprime su número y suma 1 a un contador compartido.
*
***********************************************************/
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>

#define NTHREADS 10
// Mutex para proteger la variable compartida 'counter'
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

// Función que ejecutará cada thread
void *thread_function(void *arg) {
	// Convertimos el puntero a int
	int i = *(int *)(arg);
	printf("Numero hilo: %d | Hilo ID %ld\n" , i , pthread_self());
	// Incrementa el contador de forma segura
	pthread_mutex_lock( &mutex1 );
	counter++;
	pthread_mutex_unlock( &mutex1 );
	return NULL;
}

int main(){
	pthread_t thread_id[NTHREADS];
	int i; 
	// Crear NTHREADS threads
	for(i = 0; i < NTHREADS; i ++){
		pthread_create( &thread_id[i], NULL, thread_function, &i);
	}
	// Esperar que todos los threads terminen
    	for(i = 0; i < NTHREADS; i++) {
        	pthread_join(thread_id[i], NULL);
    	}
	//Imprimir contador final
	printf("Contador final: %d\n", counter);
	return 0;
}
