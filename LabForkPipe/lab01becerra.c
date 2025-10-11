/************************************************
* Pontificia Universidad Javeriana
* Autor: Christian Becerra
* Fecha: 10/10/2025
* Materia: Sistemas Operativos
* Tema :
* - Identificacion proceso padre e hijo
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *arvg[]){
 
	 // Se  un duplica el nuevo proceso mediante fork().
	// Se invoca la creacion del proceso en un INT para identificarse 
 
 int processID = fork();
 
// Comprobar el resultado de fork()
 if(processID > 0){
	//Valor positivo,  se ejecuta en el proceso padre
	printf("Este es el 'proceso padre' con ID: %d \n", getpid());  
 }else if(processID == 0){
	// Valor 0, se ejecuta en el proceso hijo
	printf("Proceso hijo con ID : %d \n", getpid());
 }else{
	printf("El llamado al sistema fork fallo\n");
 }

 return 0;

}
