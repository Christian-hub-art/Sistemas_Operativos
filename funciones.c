#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float imcFuntion(float masa, float altura){
	float IMC = masa / (altura*altura);
	return IMC;
}

void impMatriz(float mA, int N){

	for(int i;i<N ; i++){
		for (int j;j<N; j++){
			printf(" %f ",mA);
		}
	printf("\n");
	}
}

float matrixMult(int N, float mA, float mB){
	float mC;
	for(int i;i<N; i++)
		for(int j; j <N; j++){
			for(int k; k<N ; k++)
				mC += mA * mB;
	}
	return mC;
}

void llenarMatriz (int N, float mA, float mB){

	for(int i; i<N; i++)
		for(int j; j<N; j++){
		mA = rand()%100*0.121;
		mB = rand()%100;
		}
}

int printFuntion(){
	printf("***************************************\n");
	printf("*  Calculadora Masa Corporal           \n");
	printf("***************************************\n");
	return 0;
}
