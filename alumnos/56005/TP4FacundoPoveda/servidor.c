#include "servidor.h"

int main(int arg, char **argv){
	socklen_t largo;
	largo = sizeof(struct sockaddr);
	int scd;
	int leer;
        char buffer[1024];
	char *aux;
	int abrirSocket();
	int response;
	pid_t pid;
	struct sockaddr_in cli_dir;

	//Definimos el puerto que os pasa el usuario como una constante
	const int PORT = atoi(argv[1]);

	//Intentamos abrir el socket
	int listener = abrirSocket();
	if (listener == -1){
		printf("Error en el listener \n");
		return -1;
	}

	//Intentamos hacer el enlace (bind)
	enlazarAlPuerto(listener, PORT);

	//Hago una cola para que esperen 10 clientes mientras proceso 1
	if (listen (listener,10) == -1){
		printf("No es posible escuchar en ese puerto \n");
		return -1;
	}else{
		printf("Enlazado al puerto %i \n",PORT);
	}
	
	//Elimina el problema con los zombies
	signal(SIGCHLD ,SIG_IGN);
	
	printf("Esperando al cliente \n");	

	//Aceptamos la primer conexión y la procesamos
	while ((scd = accept(listener, (struct sockaddr *) &cli_dir, &largo)) > 0 ){
		//Creamos un hijo por cada usuario que se conecte para atenderlos a todos a la vez
		pid = fork(); 
		//Lo unico que hace el padre es pasar las conexiones a los hijos; no trabaja
		if(pid == 0){
			//Leemos la petición del cliente para analizarla
			leer = read(scd,buffer,1024);
			write(STDOUT_FILENO,buffer,leer);

			//Analizamos la petición
			strtok(buffer," ");
			aux = strtok(NULL," ");
			aux = strtok(aux,"/");
			
			write(STDOUT_FILENO,aux,sizeof(aux));
			printf("\n\n");
			//Imprimimos la ip y el puerto del cliente - Network TO HoSt
			printf("Cliente: %s : %d \n", inet_ntoa (cli_dir.sin_addr),ntohs(cli_dir.sin_port));
			close(listener);
			response = mostrarRespuesta(scd,aux);
			return 0;
		}
		close(scd);
	}
	return 0;
}
