#include "servidor.h"

int main(int arg, char **argv){
	socklen_t largo = sizeof(struct sockaddr);
	int abrirSocket();
	struct sockaddr_in cli_dir;
	char * rutaMultimedia;
	char * archivo;
	int opcion;	
	int * sockDesc;
	int listener;
	int scd;
	int val=1;
	int PORT;

	//Atributos hilo
	pthread_t idHilo;
	pthread_attr_t atributo;
	pthread_attr_init(&atributo);
	pthread_attr_setdetachstate(&atributo, PTHREAD_CREATE_DETACHED);

	//Leemos las opciones
	while ((opcion = getopt(arg,argv,"f:p:r:")) != -1){
		switch (opcion){
			case 'f':
				//Leemos el nombre del archivo de configuración
				archivo = optarg;
				//Identificamos el puerto del archivo de configuración
				PORT = identificarPuerto(archivo);
				//Identificamos la ruta del archivo de configuración
				rutaMultimedia = identificarRuta(archivo);
				break;
			case 'p':
				//Si el usuario nos ingresa el puerto por consola
				PORT = atoi(optarg);
				break;
			case 'r':
				//Si el usuario nos ingresa el path por consola
				rutaMultimedia = optarg;
				break;
			case '?':
				if (optopt == 'f')
					fprintf(stderr,"La opción -%c necesita un argumaneto\n",optopt);
				else if (optopt == 'p')
                                        fprintf(stderr,"La opción -%c necesita el puerto \n",optopt);
                                else if (optopt == 'r')
                                        fprintf(stderr,"La opción -%c necesita la ruta \n",optopt);
                                else
					fprintf(stderr,"Opción desconocida -%c. \n",optopt);
				return 0;
		}	
	}

	//Intentamos abrir el socket
	listener = abrirSocket();
	if (listener == -1){
		printf("Error en el listener \n");
		return -1;
	}

	//Seteamos opciones al socket 
	setsockopt(listener,SOL_SOCKET, SO_REUSEADDR,(void *)&val,sizeof(val));

	//Intentamos hacer el enlace (bind)
	enlazarAlPuerto(listener, PORT);

	//Hago una cola para que esperen 10 clientes mientras proceso uno
	if (listen (listener,10) == -1){
		printf("No es posible escuchar en ese puerto \n");
		return -1;
	}else{
		printf("Enlazado al puerto %i \n",PORT);
		printf("Esperando al cliente \n");
	}

	//Aceptamos la primer conexión y la procesamos
	while ((scd = accept(listener, (struct sockaddr *) &cli_dir, &largo)) > 0 ){
		sockDesc=malloc(sizeof (int));
		*sockDesc=scd;
		//Creamos un hilo por cada cliente
		if ((pthread_create(&idHilo,&atributo,&funcionHilo,(void *)sockDesc))!=0){
			perror("Error en la creación del hilo");
			return -1;
		}
	}
	perror("Accept: ");
	return 0;
}
