#include "servicio.h"

int main (int arg, char **argv){
	char * archivo;
        int palabrasTotales;
	int hijos;

	//Leemos el archivo y se lo pasamos a una variable
    	archivo = argv[1];

	//Contador de palabras totales
        palabrasTotales = contarPalabras(archivo);

	//Error en el texto ingresado
	if(palabrasTotales == 0){
	printf("Error!");
	return 0;
	}
	
	//Creamos el padre y el hijo
        hijos = crearHijo();

	//Creación de procesos padre-hijo, memoria compartida y semaforos
	//crearHijos(numHijos,menorMayor,archivo,palabrasTotales);
	return 0;
}
