#include "servicio.h"

int main (int arg, char **argv){
	char * archivo;
 	int palabrasTotales;
	int memoria;

	//Leemos el archivo y se lo pasamos a una variable
    	archivo = argv[1];

	//Contador de palabras totales
        palabrasTotales = contarPalabras(archivo);

	//Error en el texto ingresado
	if(palabrasTotales == 0){
	printf("Error!");
	return 0;
	}
	
	//Creamos la memoria compartida
	memoria = crearMemoria(archivo);

	return 0;
}
