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


//Incializo main
int main() {
//Declaro un apuntador tipo char nulo
char *q = NULL;
//Impirmo en pantalla la cadena escrita
  printf("Requesting space for \"Goodbye\"\n");
//Asigno al apuntador tipo char la memoria de los bytes de la cadena Goodbye +1 byte mas 
q = (char *)malloc(strlen("Goodbye")+1);
//Si no se asigna correctamente la memoria a la cual apunatadara q dara un mensaje de error y saldra del programa
if (!q) {
perror("Failed to allocate space because");
exit(1);
}
//Si asgina correctamente la memeoria imprime el mensaje en pantalla ademas de la direccion del apuntador q 
printf("About to copy \"Goodbye\" to q at address %p\n", (void*)q);
//El apuntador apunta a la cadena Goodbye 
strcpy(q, "Goodbye");
//Imprime mensaje de copia asignacion exitosa
printf("String copied\n");
//Imprime la cadena a la cual apunta q
printf("%s \n", q);

return 0;
}

