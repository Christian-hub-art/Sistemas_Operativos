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


//Incializa main
int main() {
//Inicializa apuntador tipo entero
int *ptr;
//Se asigna memoria al apuntador ptr *15
ptr = malloc(15 * sizeof(*ptr)); /* a block of 15 integers */
// Si se le asigno correctamente memoria se le asigna un el dato 480 en la posicion 5 del apuntador (byte)
if (ptr != NULL) {
*(ptr + 5) = 480; /* assign 480 to sixth integer */
}
  
//Termina el programa
return 0;
}
