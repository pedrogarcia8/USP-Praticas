all: atividade1

run: atividade1
	./atividade1

atividade1: atividade1.o string.o
	gcc -o atividade1 atividade1.o string.o

atividade1.o: atividade1.c string.h
	gcc -c atividade1.c

string.o: string.c string.h
	gcc -c string.c

clean:
	rm -f *.o atividade1