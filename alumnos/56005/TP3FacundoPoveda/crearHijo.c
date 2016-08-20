#include "servicio.h"

int crearHijo (){
	pid_t pid;
	pid = fork();

	if(pid == 0 ){
	//hijo
	printf("Soy el hijo: %d - Mi Padre es: %d \n", getpid(), getppid());
	return 0;
	}
	//padre
	printf("Soy el padre: %d - Mi Padre es: %d \n", getpid(), getppid());

	return 0;
}
