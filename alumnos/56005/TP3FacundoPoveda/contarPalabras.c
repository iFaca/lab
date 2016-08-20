#include "servicio.h"

int contarPalabras (char * archivo){
         int i;
         int cantPalabras = 1;
         int cantEspacios = 0;
	 int cantVueltas = 0;
	 int cantLetras = 0;
         int file;
         char buffer[BUFFER];
         //Abrimos el archivo con permisos de lectura 
         file = open(archivo, O_RDONLY, NULL);
         //Leemos el archivo
         read(file, &buffer, BUFFER);
         for(i = 0; i < strlen(buffer); i++){
                 if(buffer[i] == ' ' && i > 0 && buffer[i - 1] != ' '){
                         cantPalabras++; }
                 if(buffer[i] == ' ' || buffer[i] =='\n'){
                         cantEspacios++;
                 }
		cantVueltas++;
         }
	 //Si no hay espacios, el contador falla y por lo tanto pongo esto
	 if(cantEspacios == 0){
	 printf("El texto ingresado no se puede procesar");
	 return 0;
	 }	
	 //Hago esta resta porque no funciona contar la cantidad de letras directamente
	 cantLetras = cantVueltas - cantEspacios;
         printf("Cantidad de letras totales: %i", cantLetras);
         printf("\n");
         printf("Cantidad de palabras totales: %i", cantPalabras);
         printf("\n");
         //Cerramos el archivo abierto
         close(file);
    return cantPalabras;
}
