all: main

run: main
	./main

main: main.o dicionario.o
	gcc -o main main.o dicionario.o

main.o: main.c dicionario.h
	gcc -c main.c

dicionario.o: dicionario.c dicionario.h
	gcc -c dicionario.c

clean:
	rm -f *.o main