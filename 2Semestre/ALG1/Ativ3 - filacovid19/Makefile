all: main

run: main
	./main

main: main.o fila.o
	gcc -o main main.o fila.o

main.o: main.c fila.h
	gcc -c main.c

cartas.o: fila.c fila.h
	gcc -c fila.c

clean:
	rm -f *.o main