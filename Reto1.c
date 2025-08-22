/**************************************************************************************
 * Fecha:21/08/2025
 * Autor: Christian David Becerra Enciso
 * Materia: Sistemas Operativos
 * Tema: Memoria dinamica
************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Inicializa main
int main(){
	//Inicializa una apuntador tipo char
	char *p = malloc(100*sizeof(char));
	//Inicializa un tipo apuntador tipo char en nulo 
	char *q = malloc(100*sizeof(char));
	//Imprime en pantalla la direccion a la cual apunta p
	printf("Address of p = %p\n",(void*)p);

	// Apuntador tipo char apunta a los caracteres de la cadena
	strcpy(p, "Hello, I´m the best Operating Systems!!");
	// Imprime la cadena de caracteres que paunta p 
	printf("%s\n",p);
	//Imprime en pantalla la cadena  
	printf("About to copy\"Goodbye\" to q\n");
	// Apuntador tipo char apunta a los caracteres de la cadena
	strcpy(q,"Goodbye");
	// Imprime en pantalla la cadena
	printf("String copied\n");
	//Imprime en pantalla la cadena almacena en la direccion que apunta q
	printf("%s\n", q);
	
	return 0;
}

	

