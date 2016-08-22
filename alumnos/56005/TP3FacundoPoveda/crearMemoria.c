#include "servicio.h"

int crearMemoria (char * archivo){
        /*
        int fd;

        //Creamos la memoria compartida
        fd = shm_open("/share", O_CREAT | O_RDWR,0777);
        //Error de creación o si ya existe
        if (fd==-1){
                perror("Error: \n");
        }
        else{
                printf("Memoria compartida creada exitosamente \n"); 
        }
        close(fd);
        return 0;
	*/
	int numero = 1;
	int idMemoria;
	void * punteroMemoria;
	key_t llave;
	
	llave = ftok(archivo, numero); //Creamos la llave para la memoria compartida
        if (llave == -1){
        printf("Error al crear la llave \n");
        }else{
	printf("Llave creada exitosamente . . . \n");
	}
	
	idMemoria =  shmget(llave, BUFFER, IPC_CREAT);// Obtenemos el id de la memoria compartida
	if (idMemoria == -1){
	printf("Error al intentar obtener el id de la memoria compartida \n");
	}else{
        printf("Id obtenido exitosamente . . . \n");
        }
	
	punteroMemoria = shmat(idMemoria, 0, 0);// Obtenemos el puntero que apunta a la zona de memoria
        if (punteroMemoria == -1){
        printf("Error al intentar obtener el puntero de la memoria compartida \n");
        }else{
        printf("Puntero obtenido exitosamente . . . \n");
        }
	
	return 0;
}
