#include "servicio.h"

int crearMemoria (char * archivo){
        int fd = 0;
	int fileSize;
	int file;
	char buffer[BUFFER];
	pid_t pid;
	char *puntero;
	//int *aux;
	int i;
	
	//Abrimos el arhivo que le pasamos como parámetro
	file = open(archivo, O_RDWR);
	
	//Leemos el archivo para ver su tamaño
	fileSize = read (file,buffer,sizeof(buffer));
	printf("Tamaño del archivo %d \n",fileSize);

	//Escribimos el contenido del archivo en un buffer
	 write (file,buffer,fileSize);

	//Creamos la memoria compartida	
	puntero = mmap(NULL, fileSize , PROT_READ | PROT_WRITE , MAP_SHARED|MAP_ANONYMOUS , -1 , 0);
	//aux = mmap(NULL , 30 , PROT_READ | PROT_WRITE , MAP_SHARED|MAP_ANONYMOUS , -1 , 0);
	
    	//Cerramos el descriptor
    	if (close (file) == -1) {
      	printf("Error al cerrar el archivo\n");
      	return 1;   
    	}
	
	//Escribimos en la memoria compartida
	for (i=0;i<fileSize;i++){
	*(puntero+i)=buffer[i];	
	}	
	
	//Creamos el hijo
        pid = fork();

        switch(pid){
		case -1:
			//Error
			perror("No se ha podido crear el proceso hijo \n");
			break;
        	case 0:
			//hijo
        		printf("Soy el hijo: %d - Mi Padre es: %d \n", getpid(), getppid());
	
			//Leemos el archivo de la memoria compartida
			printf("El valor de cnt es: %s \n", puntero);
			//Hacemos el conteo de las palabras y letras del archivo

			//Escribimos el resultado del conteo en la memoria compartida


			break;
		default:
        		//padre
			sleep(1);
        		printf("Soy el padre: %d \n", getpid());
			//Leemos el conteo de la memoria compartida y lo imprimimos por pantalla

       			break;
	}
        close(fd);
	return 0;
}
