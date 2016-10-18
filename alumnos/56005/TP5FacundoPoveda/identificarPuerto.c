#include "servidor.h"

int identificarPuerto(char * archivo){
	int file;
	char buffer[BUFFER];
	char * token;
	int puerto = 0;
	int leer;

	//Abrimos el archivo con permisos de lectura 
	file = open(archivo, O_RDONLY, NULL);
	//Leemos el archivo y lo escribimos en un buffer
	leer = read(file, buffer, BUFFER);

	//Sacamos el puerto del buffer
	token = strtok(buffer,"=");
	token = strtok(NULL,"=");
	token = strtok(token,"\n");
	puerto = atoi(token);

	printf("Puerto: %i \n",puerto);

	close(file);
	return puerto;
}
