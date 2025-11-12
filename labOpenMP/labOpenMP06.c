/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 11/11/2025
*
*       El programa crea dos threads que ejecutan la misma func>
*       pero cada uno imprime un mensaje diferente. Los mensaje>
*       que cada thread imprime pueden salir en cualquier
*       orden debido a la naturaleza concurrente de los threads.
*
***********************************************************/


#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  MIN(x, y) (((x) < (y)) ? (x) : (y))


#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

//Varibales globales para guardar los timepos 
struct timeval inicio, fin;
//Funcion para registrar el tiempo de inicio 
void InicioMuestra(){
        gettimeofday(&inicio, (void *)0);
}
//Fucnion para registar el tiempo fianl y calcualar la duracion 
void FinMuestra(){
        gettimeofday(&fin, (void *)0);
	//Calcular diferencia microsegundos entre inciio y fin 
        fin.tv_usec -= inicio.tv_usec;
        fin.tv_sec  -= inicio.tv_sec;
	//Convertir el tiempo a microsegudnos e imprimir 
        double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec);
        printf("%9.0f \n", tiempo);
}
//Funcion para calcular suma de senos 
double f(int i) {

	int j, start  = i  * (i + 1) / 2, finish = start + i;
	double valor_retornar = 0;
	for(j = start; j < finish; j++){
		valor_retornar += sin(j); //Sumar seno de cada rango 
	}
	return valor_retornar;
}



int main(int argc, char*argv[]){
	//Definir parametros de entarda como el numero de hilos y repeticiones 
	if(argc !=3 ){
		printf("Error: \n\t$ejecutable NumHilos NumRep\n");
		exit(0);
	}
	//Castear para el numero de hilos y repeticiones 
	int numHilos = (int)atoi(argv[1]);
	int  numRep = (int)atoi(argv[2]);
	double sum = 0;
	// Inicio el tiempo de inicio de ejecucion 
	InicioMuestra();
	// N hilos cooperan en el calculo 
	#pragma omp parallel num_threads(numHilos)
	{
		//Hilo maestro imprime numero de hilos
		#pragma omp master
		printf("Numero de hilos: %d \n", numHilos);
		//Distribuye el ciclo entre hilos y acumula los resultados 
		#pragma omp for reduction(+ : sum)
		for( int i = 0; i < numRep; i++){
			sum += f(i);// Cada hilo suma los resultados 
		}
	}

	printf("La sumatoria es: %2f \n", sum);
	// Termina el tiempo de ejecucion y lo muestra por pantalla
	FinMuestra();
	return 0; 
}
