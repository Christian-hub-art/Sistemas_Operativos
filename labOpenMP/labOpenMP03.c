/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 11/11/2025
*
*       El objetivo del programa es mostrar el uso de las cláusulas private, 
*	firstprivate y lastprivate en OpenMP, demostrando cómo afectan el valor 
*	de las variables compartidas en un bucle paralelo.
*
***********************************************************/


#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	int i;
	const int N = 1000; // Numero iteraciones del bucle 
	int a = 50; // Varibale inicializada en 50
	int b = 0;	//Variable auxiliar 
	// Cadad hilo tiene una varible i y recibe una copia inciial de a
	// El valor final de a sera el ultimo hilo en la interacion 
	#pragma omp parallel for private(i) firstprivate(a) lastprivate(a)
	for( i = 0; i < N; i++){
		a++; // Cada hilo incremneta su copia de a
	}
	// Calculo secuencial 
	b = 50 + (N-1); 
	printf("a = %d b = %d ( Se espera a = 50 b = 1049 )\n", a , b);
	
	return 0;
}
