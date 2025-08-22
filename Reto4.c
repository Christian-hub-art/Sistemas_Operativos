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
// Inicializa main 
int main() {
//Inicializa dos variables tipo entero, apuntador tipo entero 
int n, i, *ptr, sum = 0;
//Imprime en pantalla cadena de caracteres
printf("Enter number of elements: ");
//Recibe una entrada y se almacena en  direccion de la variable n
scanf("%d", &n);
// Se asigna al apuntador ptr memoria de un entero y el digito de n   
ptr = (int*) calloc(n, sizeof(int));
//Si asigna mal la memoria saldra un error en pantalla y saldra del prgrama 
if(ptr == NULL) {
printf("Error! memory not allocated.");
exit(0);
}
//Imprime en pantalla 
printf("Enter elements: ");
//Va recorrer ptr dependiendo del tamaño de n
for(i = 0; i < n; ++i) {
//Cada posicion de prt recibira una entrada e ira almcenando en el apuntador 
scanf("%d", ptr + i);
//Los datos de entrada de ptr se iran sumando en la variable sum 
sum += *(ptr + i);
}
//Se imprime la suma total de los datos de entrada al apuntador ptr
printf("Sum = %d", sum);
//Libera memoria del apuntador ptr 
free(ptr);
return 0;

}


