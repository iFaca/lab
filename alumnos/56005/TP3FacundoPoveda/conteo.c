#include "servicio.h"

/* Función que hace el histograma de palabras y letras */
int *conteo(int fileSize, char *buffer, int *intMmap){
int i;
int letra = 0;
int palabras[15];

//Iniciamos el vector con todos 0
for(i = 0 ; i < 15 ; i++){
	palabras[i]=0;
}
//Contamos la cantidad de letras de cada palabra y la metemos en un vector
for(i = 0 ; i < fileSize ; i++){
	if (*(buffer+i) != ' '){
		letra++;
	}
	else{
		switch (letra){
		case 1:
		palabras[0]++;
		letra = 0;
		break;
		
		case 2:
		palabras[1] ++;
		letra = 0;
		break;
		
		case 3:
		palabras[2] ++;
		letra = 0;
		break;
		
		case 4:
		palabras[3] ++;
		letra = 0;
		break;
		
		case 5:
		palabras[4] ++;
		letra = 0;
		break;
		
		case 6:
		palabras[5] ++;
		letra = 0;
		break;
		
		case 7:
		palabras[6] ++;
		letra = 0;
		break;
		
		case 8:
		palabras[7] ++;
		letra = 0;
		break;

		case 9:
		palabras[8] ++;
		letra = 0;
		break;

		case 10:
		palabras[9] ++;
		letra = 0;
		break;

		case 11:
		palabras[10] ++;
		letra = 0;
		break;
		
		case 12:
		palabras[11] ++;
		letra = 0;
		break;

		case 13:
		palabras[12] ++;
		letra = 0;
		break;

		case 14:
		palabras[13] ++;
		letra = 0;
		break;

		case 15:
		palabras[14] ++;
		letra = 0;
		break;
		
		case EOF:
		letra = 0;
		break;

		default:
		letra = 0;
		break;
		}
	}
}
//Pasamos el vector a la memoria compartida
for(i = 0; i < 15; i++){
	*(intMmap+i) = palabras [i];
	}
return 0;
}
