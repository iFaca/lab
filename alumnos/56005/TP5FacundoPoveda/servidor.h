#ifndef _servidor_h
#define _servidor_h

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h> //(for sigset_t and others)
#include <fcntl.h> //(for O_*)
#include <unistd.h> //(for a bunch of stuff)
#include <netdb.h> //(for various network functions and constants)
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <arpa/inet.h>
#define BUFFER 1024

int servidor (int, char **);
int abrirSocket ();
void enlazarAlPuerto(int,int);
int mostrarRespuesta(int, char *);
int identificarPuerto(char *);
char* identificarRuta(char *);

#endif
