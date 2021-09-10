all: main

run: main
	./main

main: main.o cartas.o
	gcc -o main main.o cartas.o

main.o: main.c cartas.h
	gcc -c main.c

cartas.o: cartas.c cartas.h
	gcc -c cartas.c

clean:
	rm -f *.o main