/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 11/11/2025
*
*       El objetivo del programa es ejemplificar el uso de las cláusulas 
*       private, firstprivate y lastprivate enC OpenMP, mostrando como la 
*       variable b toma el valor de la últDima iteración ejecutada en un bucle paralelo.
*
***********************************************************/


#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	int i;
	const int N = 1000;
	int a = 50;
	int b = 0;
	// Cada hilo tiene su propia variable i y recibe una copia de la varibale a = 50
	// el valor final de b sera el ultimo hilo en completar la iteracion 
	#pragma omp parallel for private(i) firstprivate(a) lastprivate(b)
	for(i = 0; i < N; i++){
	b = a + i ; // Cada hilo calcula b en fucnion de a e i 
	}	

	printf(" a = %d b = %d ( Se espera a = 50 b = 1049\n", a , b);
	
	return 0;
}
