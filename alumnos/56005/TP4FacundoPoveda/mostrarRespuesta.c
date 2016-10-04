#include "servidor.h"

int mostrarRespuesta(int scd,char *aux){
	//char server_reply[2000];
	char *buffer=NULL;
	int archivo;
	int mostrar = 0;

	static char* not_found =
		"HTTP/1.1 404 Not Found\n"
		"Content-type: text/html\n"
		"\n"
		"<html>\n"
		" <body>\n"
		"  <h1>Not Found</h1>\n"
		"  <p>The requested URL was not found on this server.</p>\n"
		" </body>\n"
		"</html>\n";
	static char* ok_response_html =
		"HTTP/1.0 200 OK"
		"Content-type: text/html\n"
		"\n";
	static char* ok_response_txt =
		"HTTP/1.0 200 OK\n"
		"Content-type: text/plain\n"
		"\n";
	static char* ok_response_pdf =
		"HTTP/1.0 200 OK\n"
		"Content-type: application/pdf\n"
		"\n";
	static char* ok_response_jpg =
		"HTTP/1.0 200 OK\n"
		"Content-type: image/jpeg\n"
		"\n";
	static char* internal_server_error =
		"HTTP/1.0 500 Internal Server Error\n"
		"Content-type: text/html\n"
		"\n"
		"<html>\n"
		" <body>\n"
		"  <h1>Internal Server Error</h1>\n"
		"  <p>The server encountered an internal error and was unable to complete your request.</p>\n"
		" </body>\n"
		"</html>\n";

	//Enviamos datos
	if (!strcmp(aux,"faca.pdf")){
		send(scd , ok_response_pdf , strlen(ok_response_pdf) , 0);
		mostrar = 1;
	}else if (!strcmp(aux,"faca.jpg")){
		send(scd , ok_response_jpg , strlen(ok_response_jpg) , 0);
		mostrar = 1;
	}else if (!strcmp(aux,"faca.html")){
		send(scd , ok_response_html , strlen(ok_response_html) , 0);
		mostrar = 1;
	}else if (!strcmp(aux,"faca.txt")){
		send(scd , ok_response_txt , strlen(ok_response_txt) , 0);
		mostrar = 1;
        }else if (!strcmp(aux,"error")){
                send(scd , internal_server_error , strlen(internal_server_error) , 0);
        }else{
		send(scd , not_found , strlen(not_found) , 0);
	}

	//Le mostramos el archivo al cliente
	if (mostrar == 1){
		archivo = open(aux, O_RDONLY, NULL);
		while(read(archivo,&buffer,1)>0){
			write(scd,&buffer,1);
		}
		mostrar = 0;
	}
	puts("Datos enviados\n");

	/*
	//Recibimos la respuesta del servidor
	if( recv(scd, server_reply , 2000 , 0) < 0)
	{
	puts("Error en la recepción");
	return 1;
	}
	puts("Respuesta recibida\n");
	puts(server_reply);
	 */

	return 0;
}
