all: main

run: main
	./main

main: main.o warmup.o
	gcc -o main main.o warmup.o

main.o: main.c warmup.h
	gcc -c main.c

warmup.o: warmup.c warmup.h
	gcc -c warmup.c

clean:
	rm -f *.o main