all: main

run: main
	./main

main: main.o grandesnumeros.o
	gcc -o main main.o grandesnumeros.o

main.o: main.c grandesnumeros.h
	gcc -c main.c

grandesnumeros.o: grandesnumeros.c grandesnumeros.h
	gcc -c grandesnumeros.c

clean:
	rm -f *.o main