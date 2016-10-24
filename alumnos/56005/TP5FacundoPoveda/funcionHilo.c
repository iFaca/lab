#include "servidor.h"

void * funcionHilo(void * sdConn){
	int leer;
	char buffer[BUFFER];
	char *aux;
	int response;
	int scd = *((int *)sdConn);
	int get=0;
	int post=0;
	
	//Liberamos memoria
	free(sdConn);

	//Leemos la petición del cliente para analizarla
	leer = read(scd,buffer,BUFFER);
	write(STDOUT_FILENO,buffer,leer);

	//Analizamos la petición
	strtok(buffer," ");
	//Analizamos si se envía un GET o un POST
	if(strcmp(buffer, "GET") == 0){
	get=1;
	}
        if(strcmp(buffer, "POST") == 0){
        post=1;
        }
	aux = strtok(NULL," ");
	aux = strtok(aux,"/");
	printf("\n");

	//Excepción null
	if (aux == NULL){
		printf("Error NULL: No se envió nada en la petición \n");
		close(scd);	
		return NULL;
	}

	//Enviamos la respuesta al cliente
	response = mostrarRespuesta(scd,aux);
	//Ponemos los flags en 0 nuevamente
	get=0;
	post=0;
	pthread_exit(NULL);
	return NULL;
}
