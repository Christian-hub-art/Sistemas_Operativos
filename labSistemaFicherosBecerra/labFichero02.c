/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 13/11/2025
*
*       El programa busca recorrer un directorio ingresado por el usuario y 
*	mostrar información básica de los archivos que contiene. 
*	
***********************************************************/

#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
//Puntero al directorio 
DIR *d;
//Varibales al nombre del directorio y del archivo 
char nomdir[256], nomfich[512];
// estructura para almacenar informacion del archivo 
struct stat datos;
// estructura para leer entradas del directorio
struct dirent *direc;
// pedir al usuario nombre del directorio
printf ("Introduzca el Nombre de un Directorio: ");

fgets (nomdir,sizeof(nomdir),stdin);

/*Eliminamos el \n del Nombre del Fichero*/

nomdir[strlen(nomdir)-1] = '\0';

// Intentar abrir el directorio 
if ((d=opendir(nomdir))==NULL){
	printf ("El directorio no existe\n");
	return -1;
}
//Leer todas las entradas del directorio 
while ((direc=readdir(d)) !=NULL) {
	printf("Archivo encontrado: %s\n", direc->d_name);
	// Construir la ruta completa del archivo 
	strcpy(nomfich, nomdir);
	strcat(nomfich, "/");
	strcat(nomfich, direc->d_name );
	//Obtener informacion del archivo 
	if(stat(nomfich, &datos) == -1){
		continue;
	}
	//Mostrar la informacion del nombre y tamaño 
	if (S_ISREG(datos.st_mode)){
		printf ("Nombre: %s\t| Tamaño: %ld\n",direc->d_name,datos.st_size);
	}/*Fin del While*/
}

closedir(d);
return 0;

}

/* Al ejecutarlo, el programa lista cada archivo del directorio con su tamaño en bytes, 
   permitiendo verificar fácilmente qué archivos existen y sus características. */
