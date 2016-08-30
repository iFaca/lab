#ifndef _servicio_h
#define _servicio_h

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
#define BUFFER 1000
#define MEMORY 1024
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main (int, char **);
int contarPalabras (char*);
int crearMemoria(char *);
int *conteo(int, char*,int*);

#endif
