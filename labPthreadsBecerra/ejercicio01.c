/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: Jhon Corredor
*Fecha: 4/11/2025
* 
*	El programa crea dos threads que ejecutan la misma función,
*	pero cada uno imprime un mensaje diferente. Los mensajes 
*	que cada thread imprime pueden salir en cualquier 
*	orden debido a la naturaleza concurrente de los threads.
*
***********************************************************/
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
// Función que será ejecutada por cada thread
void *print_message_function( void *ptr ) {
	char *message;
	// Convierte el argumento pasado (puntero void) a un puntero de tipo char
	message = (char *) ptr;
	printf("Mensaje desde funcion: %s \n", message);
	return NULL ;
}

int main() {
	 // Declaramos dos threads y sus respectivos mensajes
	pthread_t thread1, thread2;
	char *message1 = "Hola soy Hilo 1";
	char *message2 = "Hola soy Hilo 2";
	int iret1, iret2;

	// Creamos el primer thread que ejecutará la función print_message_function
	iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
	// Creamos el segundo thread que ejecutará la misma función pero con un mensaje diferente
	iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
	// Mostramos los valores de retorno de los threads
	printf("Hilo 1 returna: %d\n",iret1);
	printf("Hilo 2 retorna: %d\n",iret2);
	// Esperamos a que ambos threads terminen de ejecutar antes de finalizar el programa
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
