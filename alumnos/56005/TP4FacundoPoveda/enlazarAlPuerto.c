#include "servidor.h"

void enlazarAlPuerto(int socket, int port){
	struct sockaddr_in name;
	name.sin_family=PF_INET;
	name.sin_port=(in_port_t)htons(port);
	name.sin_addr.s_addr= htonl(INADDR_ANY);

	int reuse =1;
	if(setsockopt(socket,SOL_SOCKET,SO_REUSEADDR,(char*)&reuse,sizeof(int)) == -1){
		perror("No es posible reusar el socket\n");
	}

	int  c = bind (socket, (struct sockaddr*) &name, sizeof(name));
	if(c==-1){
		perror("No se puede alcanzar el puerto: dirección ya está en uso \n");
	}


}
