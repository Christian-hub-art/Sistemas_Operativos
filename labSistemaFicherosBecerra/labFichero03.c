/************************************************************
*Autor: Christian David Becerra Enciso
*Asignatura: Sistemas Operativos
*Docente: J.Corredor
*Fecha: 13/11/2025
*
*       El objetivo de este programa es recorrer un directorio dado por el usuario y listar los archivos contenidos en el,
*	mostrando información básica como el nombre y los permisos de lectura del propietario.
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
#include <time.h>

int main(){

int er;
char nomdir[100], nomfich[100], resp[30];
struct stat atr;
DIR *d;
struct dirent *rd1;
time_t fecha;
printf ("Nombre directorio\n");
fgets (nomdir, sizeof (nomdir), stdin);

/* hay que quitar el \n del nombre del directorio*/
nomdir[strlen(nomdir)-1]='\0';
fecha=time(&fecha);
if ((d=opendir(nomdir))==NULL) {
        printf ("No existe ese directorio \n");
        return -1;
}else {
        while (( rd1 =readdir(d)) != NULL) {
        // Saltar
	        if ( (strcmp(rd1->d_name, ".")!=0 )&& (strcmp(rd1->d_name, "..")!=0 )){
              // Construir ruta completa
	          strcpy (nomfich, nomdir);
                        strcat (nomfich, "/");
                        strcat (nomfich, rd1->d_name);
                        printf ("fichero :%s:", nomfich);
			//Obtener informacion del archivo
                        er=stat (nomfich, &atr);
                        printf ("modo :%#o:", atr.st_mode);
			// Verificar permiso propetario
                        if ((atr.st_mode & 0400) != 0){
                                printf (" permiso R para propietario\n");
                        }else{
				printf (" No permiso R para propietario\n");
			}
			// Verificar si es directorio
			if (S_ISDIR(atr.st_mode)) printf (" Es un directorio \n");
			//Si el archvio es regular verificar fecha 
			if (S_ISREG(atr.st_mode)){
			/* ficheros modificados en los últimos 10 dias */
				if ( (fecha - 10*24*60*60) < atr.st_mtime) {
					printf ("FICHERO:%s: fecha acceso %s, en sgdos %ld\n", rd1->d_name,ctime (&atr.st_mtime),atr.st_mtime);
				}
			}

		}
	}

	closedir(d);
}
	return 0;

}

/* El programa demuestra como acceder y examinar archivos en un directorio y como interpretar permisos básicos de 
los archivos. Su correcta ejecución permite identificar facilmente que archivos existen en un directorio y si tienen permisos 
de lectura para el propietario */
