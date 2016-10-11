#include "servidor.h"

char* identificarRuta(char * archivo){
	int file;
	char buffer[BUFFER];
	char *ruta;
	int leer;

	//Abrimos el archivo con permisos de lectura 
	file = open(archivo, O_RDONLY, NULL);
	//Leemos el archivo y lo escribimos en un buffer
	leer = read(file, buffer, BUFFER);

	//Sacamos la ruta del buffer
	strtok(buffer,"=");
	strtok(NULL,"=");
	ruta = strtok(NULL,"=");
	
	printf("La ruta del archivo de configuración es: %s \n",ruta);	
	
	close(file);
	return ruta;
}
