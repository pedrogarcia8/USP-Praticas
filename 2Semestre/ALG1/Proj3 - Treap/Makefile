all: main

run: main
	./main

main: main.o treap.o
	gcc -o main main.o treap.o

main.o: main.c treap.h
	gcc -c main.c

treap.o: treap.c treap.h
	gcc -c treap.c

clean:
	rm -f *.o main