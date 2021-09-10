all: main

run: main
	./main

main: main.o rubronegra.o
	gcc -o main main.o rubronegra.o

main.o: main.c rubronegra.h
	gcc -c main.c

rubronegra.o: rubronegra.c rubronegra.h
	gcc -c rubronegra.c

clean:
	rm -f *.o main