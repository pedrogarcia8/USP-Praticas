#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

Pessoa * criar(char * nome, char * end){
	if((nome == NULL) || (end == NULL))
		return NULL;
		
	Pessoa * p = (Pessoa *) malloc(sizeof(Pessoa));
	
	if(p == NULL)
		return NULL;
	
	p->nome = nome;
	p->end = end;
	
	return p;
}

int * excluir(Pessoa * p){
	if(p == NULL)
		return 0;
	
	free(p);
	p == NULL;
	
	return 1;
}

char * buscar(Pessoa * p){
	if(p == NULL)
		return NULL;
	
	return p->end;

}

