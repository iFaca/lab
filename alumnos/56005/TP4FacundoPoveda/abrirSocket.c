#include "servidor.h"

int abrirSocket(){
        int s = socket(PF_INET,SOCK_STREAM,0);
        if (s == -1){
                printf("Error al abrir el socket \n");
        }
        return s;
}
