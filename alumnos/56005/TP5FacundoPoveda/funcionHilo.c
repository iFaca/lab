#include "servidor.h"

void * funcionHilo(void * sdConn){
	int leer;
	char buffer[BUFFER];
	char *aux;
	int response;
	int scd = *((int *)sdConn);
	//Liberamos memoria
	free(sdConn);

	//Leemos la petición del cliente para analizarla
	leer = read(scd,buffer,BUFFER);
	write(STDOUT_FILENO,buffer,leer);

	//Analizamos la petición
	strtok(buffer," ");
	aux = strtok(NULL," ");
	aux = strtok(aux,"/");
	printf("Petición: %s \n",aux);
	printf("\n");

	//Excepción null
	if (aux == NULL){
		printf("Error NULL: No se envió nada en la petición \n");
		close(scd);	
		return NULL;
	}

	//Enviamos la respuesta al cliente
	response = mostrarRespuesta(scd,aux);
	//close(scd);
	pthread_exit(NULL);
	return NULL;
}
