/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 13/11/2025
*
*       El programa tiene como objetivo leer y mostrar el contenido 
*	de un archivo de texto llamado readme.txt. Se usa FILE.
***********************************************************/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
//nombre archivo leer
char *filname = "readme.txt";
//Abrir archivo lectura
FILE *fp = fopen(filname, "r");
if(fp == NULL){
	//Si no abre archivo mostrar erro
	printf("Error: no se puede abrir el fichero %s", filname);
	return 1;
}
//Definir tamaño maximo a leer 
const unsigned MAX_LENGTH = 256;
char buffer[MAX_LENGTH];
//Leer linea por linea del archivo.txt
while(fgets(buffer, MAX_LENGTH, fp)){
	//Mostrar en pantalla
	printf("%s", buffer);
}
//Cerrar el archvio
fclose(fp);
printf("\n ================================== \n");
printf("\n Lectura de fichero readme.txt\n ");
printf("\n ================================== \n");

return 0;

}

/*  Al ejecutarlo, el programa imprime línea por línea el contenido del archivo en la consola.*/
