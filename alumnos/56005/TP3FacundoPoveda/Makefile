GETS= servicio
FLAGS= -Wall -g
CC= gcc
TARGETS= servicio

servicio: servicio main.c contarPalabras.c crearMemoria.c
	$(CC) $(FLAGS) -o $@ $^
clean:
	rm -fv $(TARGETS) *.o *~
