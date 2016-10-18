#include "servidor.h"

int mostrarRespuesta(int scd,char *aux){
	int archivo;
	int mostrar = 0;
	int leido;
        char buff[BUFFER];
	
	//Errores
	static char* internal_server_error =
                "HTTP/1.1 500 Internal Server Error\n"
                "Content-type: text/html\n"
                "\n"
                "<html>\n"
                " <body>\n"
                "  <h1>Internal Server Error</h1>\n"
                "  <p>The server encountered an internal error and was unable to complete your request.</p>\n"
                " </body>\n"
                "</html>\n";

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
	static char* forbidden =
                "HTTP/1.1 403 Forbidden\n"
                "Content-type: text/html\n"
                "\n"
                "<html>\n"
                " <body>\n"
                "  <h1>Forbidden</h1>\n"
                "  <p>You don't have permission to access to this resource on this server.</p>\n"
                " </body>\n"
                "</html>\n";
	static char* bad_request =
                "HTTP/1.1 400 Bad Request\n"
                "Content-type: text/html\n"
                "\n"
                "<html>\n"
                " <body>\n"
                "  <h1>Bad Request</h1>\n"
                "  <p>Your Browser sent a request that this server could not understand.</p>\n"
                " </body>\n"
                "</html>\n";

	//Respuestas correctas 
	static char* ok_response_html =
		"HTTP/1.1 200 OK"
		"Content-type: text/html\n"
		"\n";
	static char* ok_response_txt =
		"HTTP/1.1 200 OK\n"
		"Content-type: text/plain\n"
		"\n";
	static char* ok_response_pdf =
		"HTTP/1.1 200 OK\n"
		"Content-type: application/pdf\n"
		"\n";
	static char* ok_response_jpg =
		"HTTP/1.1 200 OK\n"
		"Content-type: image/jpeg\n"
		"\n";
        static char* ok_response_mp3 =
                "HTTP/1.1 200 OK\r\n"
                "Content-type: audio/mpeg\r\n"
                "\r\n";
	static char* ok_response_gif =
                "HTTP/1.1 200 OK\n"
                "Content-type: image/gif\n"
                "\n";
	static char* ok_response_mp4 =
                "HTTP/1.1 200 OK\n"
                "Content-type: video/mp4\n"
		"\n";
	static char* ok_response_json =
                "HTTP/1.1 200 OK\n"
                "Content-type: application/json\n"
                "\n";

	//Enviamos datos
	if (!strcmp(aux,"faca.pdf")){
		send(scd , ok_response_pdf , strlen(ok_response_pdf) , 0);
		mostrar = 1;
	}else if (!strcmp(aux,"faca.mp3")){
                send(scd , ok_response_mp3 , strlen(ok_response_mp3) , 0);
                mostrar = 1;
	}else if (!strcmp(aux,"faca.mp4")){
                send(scd , ok_response_mp4 , strlen(ok_response_mp4) , 0);
                mostrar = 1;
	}else if (!strcmp(aux,"faca.json")){
                send(scd , ok_response_json , strlen(ok_response_json) , 0);
                mostrar = 1;
	}else if (!strcmp(aux,"faca.gif")){
                send(scd , ok_response_gif , strlen(ok_response_gif) , 0);
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
        }else if (!strcmp(aux,"error500")){
                send(scd , internal_server_error , strlen(internal_server_error) , 0);
        }else if (!strcmp(aux,"error403")){
                send(scd , forbidden , strlen(forbidden) , 0);
	}else if (!strcmp(aux,"error400")){
                send(scd , bad_request , strlen(bad_request) , 0);
        }else{
		send(scd , not_found , strlen(not_found) , 0);
	}
	
	//Le mostramos el archivo al cliente
	if (mostrar == 1){
		archivo = open(aux, O_RDONLY, NULL);
		while((leido = read(archivo,buff,sizeof buff))>0){
			write(scd,buff,leido);
		}
		close(archivo);
		mostrar = 0;
	}
	close(scd);
	puts("Datos enviados\n");
	return 0;
}
