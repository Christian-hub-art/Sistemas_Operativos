/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 11/11/2025
*
*       El objetivo del programa es calcular en paralelo la sumatoria 
*	de la función f(i) para valores de i entre 0 y 30000, utilizando 
*	OpenMP para dividir el trabajo entre varios hilos y combinar los 
*	resultados mediante una reducción.
***********************************************************/


#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Parametro para obteenr el minimo entre dos valores 
#define  MIN(x, y) (((x) < (y)) ? (x) : (y))
//Funcion para la suma de senos 
double f(int i) {

	int j, start  = i  * (i + 1) / 2, finish = start + i;
	double valor_retornar = 0;
	for(j = start; j < finish; j++){
		valor_retornar += sin(j);
	}
	return valor_retornar; // Acumulacion del valor de senos 
}



int main(int argc, char*argv[]){
	double sum = 0;
	int n = 30000;

	//Hilos cooperan en el calculo 
	#pragma omp parallel
	{	//Numero de hilos activos 
		int threads = omp_get_num_threads();
		//Hilo maestro imprime cantidad de hilos 
		#pragma omp master
		printf("Numero de hilos: %d \n", threads);
		// Distribuye los hilos en el bucle y acumla la variable sum  
		#pragma omp for reduction(+ : sum)
		for( int i = 0; i <= n; i++){
			sum += f(i);//Cada hilo suma el resultado 
		}
	}

	printf("La sumatoria es: %2f \n", sum);

	return 0; 
}
