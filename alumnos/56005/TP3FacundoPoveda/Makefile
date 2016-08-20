GETS= servicio
FLAGS= -Wall -g
CC= gcc
TARGETS= servicio

servicio: servicio main.c contarPalabras.c crearHijo.c
	$(CC) $(FLAGS) -o $@ $^
clean:
	rm -fv $(TARGETS) *.o *~
