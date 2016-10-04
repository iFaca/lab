FLAGS= -Wall -g
CC= gcc
TARGETS= servidor

servidor: servidor.c abrirSocket.c enlazarAlPuerto.c mostrarRespuesta.c
	$(CC) $(FLAGS) -o $@ $^
clean:
	rm -fv $(TARGETS) *.o *~
