/************************************************
* Pontificia Universidad Javeriana
* Autor: Christian Becerra
* Fecha: 10/10/2025
* Materia: Sistemas Operativos
* Tema : 
* - Identificacion proceso padre e hijo
* - Comunicacion entre procesos con PIPE
* - Procesos duplicados 
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *arvg[]){
 //creacion de tuberia de comunicacion 
 int pipefd[2]; // [0] = lectura, [1] = escritura
 pid_t pHijo_PID;
 //verificacion del PIPE
 if(pipe(pipefd) == -1){
 	perror("PIPE");	
	exit(EXIT_FAILURE);
 }
 // Creación del proceso hijo
 pHijo_PID = fork(); //Verificacion del proceso 
 if(pHijo_PID == -1) {
 	perror("FORK");
	exit(EXIT_FAILURE);
 }

 //Proceso hijo
 //Se duplica el proceso
 if(pHijo_PID == 0){
	close(pipefd[1]); //Cerra salida
	char mensaje[100];
	int lecturaBYTES;
	lecturaBYTES = read(pipefd[0], mensaje, sizeof(mensaje)); 
	//Verificacion de lectura del mensaje
	if(lecturaBYTES == -1) {
        perror("LECTURA");
        exit(EXIT_FAILURE);
 	}
	printf("HIJO (PID=%d) RECIBE: %s\n", getpid(),mensaje);
	close(pipefd[0]); //Cerrar entrada 
}else{

	//Proceso padre
        close(pipefd[0]); //Cerrar entrada - extremo de la lectura 
        char mensaje[]="Hola desde el PADRE hacia el HIJO";
        int escrituraBYTES;
        escrituraBYTES = write(pipefd[1], mensaje, strlen(mensaje));

        //Verificacion de escritura del mensaje

        if(escrituraBYTES == -1) {
        perror("ESCRITURA");
        exit(EXIT_FAILURE);
        }
		 
	close(pipefd[1]); //Cerrar salida
	printf("PADRE (PID: %d): Mensaje enviado y proceso hijo finalizado.\n", getpid());

 }

 return 0;

}
