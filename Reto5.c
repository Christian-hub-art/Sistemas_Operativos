/**************************************************************************************
 * Fecha:21/08/2025
 * Autor: Christian David Becerra Enciso
 * Materia: Sistemas Operativos
 * Tema: Memoria dinamica
************************************************************/
//Incluye librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Inicializa main
int main() {
//Inicializa apuntador tipo entero y tres variables tipo entero
int *ptr, i , n1, n2;
//Imprime en pantalla mensaje 
printf("Enter size: ");
//Recibe de entrada un tipo entero y se alamcena en la variable n1
scanf("%d", &n1);
//Se asgina memoria del tamaño de un entero * el digito que se puso en n1
ptr = (int*) malloc(n1 * sizeof(int));
//Imprime mensaje en pantalla
printf("Addresses of previously allocated memory: ");
//Inicia ciclo for dependiendo del valor n1
for(i = 0; i < n1; ++i)
//Imprime direccion de ptr asignada 
printf("\n\np = %p\n", ptr+i);
//Imprime mensaje en pantalla
printf("\n Enter the new size: ");
//Recibe parametro a la variable n2
scanf("%d", &n2);
// Reconfigura el tamaño del apuntador ptr con el digito de la variable n2
ptr = realloc(ptr, n2 * sizeof(int));
//Imprime en pantalla mensaje 
printf("Addresses of newly allocated memory: ");
//Incia ciclo for dependiendo de la variable n2
for(i = 0; i < n2; ++i)
//Imprime nueva direccion del apuntador ptr
printf("\n\np = %p\n", ptr+i);
//Libera memoria del apuntador ptr
free(ptr);
//Termina programa
return 0;
}

