#include "servicio.h"

/* Función que crea el padre, el hijo y la memoria compartida */
int crearMemoria (char * archivo){
	int fileSize;
	int file;
	char buffer[BUFFER];
	char *charMmap;
	int *intMmap;
	int i;
	pid_t pid;
	sem_t *semaforo;
	//sem_t *semaforo2;

	//Abrimos el arhivo que le pasamos como parámetro
	file = open(archivo, O_RDWR);

	//Creamos el primer semáforo
	//semaforo2 = sem_open("SemaforoB", O_CREAT , 0666 , 0);
	
	//Leemos el tamaño del archivo
	fileSize = read (file,buffer,sizeof(buffer));
	printf("Tamaño del archivo %d \n",fileSize);

	//Creamos un espacio de memoria compartida para guardar el texto del buffer	
	charMmap = mmap(NULL, fileSize , PROT_READ | PROT_WRITE , MAP_SHARED|MAP_ANONYMOUS , -1 , 0);
	//Creamos otro espacio de memoria compartida para guardar el arreglo con la cantidad de letras por palabra
	intMmap = mmap(NULL, sizeof(int)*15, PROT_READ | PROT_WRITE , MAP_SHARED|MAP_ANONYMOUS , -1 , 0);	

	//Cerramos el descriptor
	if (close (file) == -1) {
		printf("Error al cerrar el archivo\n");
		return 1;   
	}

	//Escribimos en la memoria compartida
	for (i=0 ; i < fileSize ; i++){
		*(charMmap+i) = buffer[i];	
	}	

	//Creamos el semaforo
	semaforo = sem_open("SemaforoA", O_CREAT , 0666 , 0);

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

			//Hacemos el conteo de las palabras y letras del archivo
			conteo( fileSize , charMmap , intMmap);

			//Le sumamos 1 al semáforo
			sem_post(semaforo);
			break;
		default:
			//Le restamos 1 al semáforo
			sem_wait(semaforo);

			//padre
			printf("Soy el padre: %d \n", getpid());

			//Leemos el conteo de la memoria compartida y lo imprimimos por pantalla
			for (i = 0; i < 15 ; i++){
				printf("Palabras de longitud %d = %d \n", i+1, *(intMmap+i));
			}
			break;
	}
	return 0;
}
