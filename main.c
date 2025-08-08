#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(int argc, char* argv[]){

if(argc<4){
	printf("$./ejecutable valor1 valor2 valor3\n");
	exit(0);
}

float altura= (float)atof(argv[1]);
float masacorporal = (float)atof(argv[2]);
int N =(int)atof(argv[3]);

printFuntion();

float valorIMC = imcFuntion(masacorporal, altura);

printf("El indice de masa corporal es %f\n", valorIMC);
printf("***********************************\n\n\n");
printf("           Matrices                    \n");
printf("***************************************\n");
float m1, m2, m3;

llenarMatriz(N, m1, m2);
impMatriz( m1, N);
impMatriz(m2, N);

float mC = matrixMult(N, m1, m2);
impMatriz(mC, N);

return 0;

}
