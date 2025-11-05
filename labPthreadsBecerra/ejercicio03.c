/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
*
*       Dos threads incrementan un contador compartido 
*	hasta COUNT_DONE (15). Count01 se detiene 
*	temporalmente si el contador está entre 
*	COUNT_HALT1 (4) y COUNT_HALT2 (11), 
*	esperando que count02 lo desbloquee.Count02 
*	desbloquea count01 usando una 
*	condición (pthread_cond_signal) cuando el contador 
*	sale de esa zona.
*
***********************************************************/



#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
#include <stdlib.h>


pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

int count = 0;

#define COUNT_DONE 15
#define COUNT_HALT1 4
#define COUNT_HALT2 11

// Thread que incrementa el contador 01
void *count01(){
	for(;;) {
		// Espera si count está entre COUNT_HALT1 y COUNT_HALT2
		pthread_mutex_lock ( &condition_mutex );
		while( count >= COUNT_HALT1 && count <= COUNT_HALT2 ){
			pthread_cond_wait( &condition_cond, &condition_mutex );
		}
		pthread_mutex_unlock( &condition_mutex );
		// Incrementa contador de forma segura
		pthread_mutex_lock( &count_mutex );
		count++;
		printf("Contador valor functionCount ==> 01 <==: %d\n", count);
		pthread_mutex_unlock( &count_mutex );	
		if(count >= COUNT_DONE){
			return NULL;
		}
	}
}
// Thread que incrementa el contador 02
void *count02(){
        for(;;) {
		// Señala a count01 si count no está en la zona de parada
                pthread_mutex_lock ( &condition_mutex );
                if ( count < COUNT_HALT1 || count > COUNT_HALT2 ){
			pthread_cond_signal( &condition_cond );
                }
                pthread_mutex_unlock( &count_mutex );
	        // Incrementa contador de forma segura
                pthread_mutex_lock( &count_mutex );
                count++;
                printf("Contador valor functionCount ==> 02 <==: %d\n", count);
                pthread_mutex_unlock( &count_mutex );
                if(count >= COUNT_DONE){
                        return NULL;
                }
        }
}


int main() {
	pthread_t thread1, thread2;
	// Crea threads
	pthread_create( &thread1, NULL, &count01, NULL);
	pthread_create( &thread2, NULL, &count02, NULL);
	// Esperar a que ambos hilos terminen
	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);

	return 0;

}
