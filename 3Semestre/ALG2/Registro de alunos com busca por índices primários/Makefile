all: main

run: main
	./main

main: main.o registroaluno.o
	gcc -o main main.o registroaluno.o

main.o: main.c registroaluno.h
	gcc -c main.c

registroaluno.o: registroaluno.c registroaluno.h
	gcc -c registroaluno.c

clean:
	rm -f *.o main