#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float imcFuntion(float masa, float altura){
	float IMC = masa / (altura*altura);
	return IMC;
} // esta funcion calcula el imc por medio de la altura y la masa 

void impMatriz(float mA, int N){

	for(int i;i<N ; i++){
		for (int j;j<N; j++){
			printf(" %f ",mA);
		}
	printf("\n");
	}
} // Muestra los elementos de la matriz separados por espacios, fila por fila.

float matrixMult(int N, float mA, float mB){
	float mC;
	for(int i;i<N; i++)
		for(int j; j <N; j++){
			for(int k; k<N ; k++)
				mC += mA * mB;
	}
	return mC;
} //   Realiza la multiplicación de dos matrices cuadradas NxN y almacena el resultado en mC.

void llenarMatriz (int N, float mA, float mB){

	for(int i; i<N; i++)
		for(int j; j<N; j++){
		mA = rand()%100*0.121;
		mB = rand()%100;
		}
}  //Asigna a cada posición de mA y mB un valor aleatorio, mA en un rango decimal pequeño y mB como un entero aleatorio.

int printFuntion(){
	printf("***************************************\n");
	printf("*  Calculadora Masa Corporal           \n");
	printf("***************************************\n");
	return 0;
} // Muestra en pantalla un título decorativo para la aplicación.
