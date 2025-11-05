/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
*
*       El programa crea tres hilos que incrementan 
*	un contador compartido de forma segura usando un 
*	mutex, simulan trabajo con un bucle y muestran 
*	mensajes al iniciar y terminar; el main espera a que 
*	todos los hilos finalicen.
*
***********************************************************/




#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



//Arreglo de hilos
pthread_t tid[3];
int counter = 0;
//muetx para proteger el contador
pthread_mutex_t bloqueo = PTHREAD_MUTEX_INITIALIZER;

//funcion que ejecuta cada hilo
void *compute(void *arg){
	unsigned long i = 0;
	pthread_mutex_lock( &bloqueo );
	counter += 1;
	printf(" \n Ha iniciado: %d \n", counter);

	//simulacion de trabajo por cada hilo
	for( int i = 0; i <(0xFFFFFFFF); i++){
	//Trabajado simulado en el tiempo 0xFFFFFFFF
	}
	//Termian el trabajo su hilo 
	printf(" \n Ha terminado: %d \n", counter);
        pthread_mutex_unlock( &bloqueo );
	return NULL ; 
}



int main(void ){
	int i = 0;
	int error;
	
	while( i < 3 ){
		//Creacion de hilos en este caso 3
		error = pthread_create(&(tid[i]), NULL, &compute, NULL);
		//Mensaje por si no se crea de forma correcta el hilo
		if(error != 0){
			printf("\n Hilo no puede ser creado : [%d]" , error);
		}
		i++;
	}
	//Esperar a que cada hilo termine 
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	return 0;
}

