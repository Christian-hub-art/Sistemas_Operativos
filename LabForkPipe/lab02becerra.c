/************************************************
* Pontificia Universidad Javeriana
* Autor: Christian Becerra
* Fecha: 10/10/2025
* Materia: Sistemas Operativos
* Tema : 
* - Identificacion proceso padre e hijo
* - Procesos duplicados 
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *arvg[]){
 // Se invoca la creacion del proceso en un INT para identificarse 
 int processID = fork();
 
 //Se duplica el proceso 
 if(processID > 0){
	// Valor positivo → Proceso padre
	printf("\nEste es el 'proceso padre' con ID: %d \n\n", getpid());
	 // Bucle del proceso padre: cuenta regresiva
	for (int i= 5; i>0; i--){
		printf("Valor padre: %d \n", i);
	}  
 }else if(processID == 0){
	 // Valor 0 → Proceso hijo
	printf("\nProceso hijo con ID : %d \n\n", getpid());
	// Bucle del proceso hijo: cuenta ascendente
	for (int i=0; i<5; i++){
                printf("Valor Hijo: %d \n", i);
        }
 }else {
 	printf("Error en la llamada \n");
 }

 return 0;

}
