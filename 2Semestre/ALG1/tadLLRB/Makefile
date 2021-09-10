all: main

run: main
	./main

main: main.o llrb.o
	gcc -o main main.o llrb.o

main.o: main.c llrb.h
	gcc -c main.c

llrb.o: llrb.c llrb.h
	gcc -c llrb.c

clean:
	rm -f *.o main