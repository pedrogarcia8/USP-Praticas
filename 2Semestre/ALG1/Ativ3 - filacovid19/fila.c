#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila * criar(int N){
    Fila * f;
    f = (Fila *) malloc(sizeof(Fila));
    assert(f != NULL);
    f->total = 0;
    f->fim = 0;
    f->inicio = 0;
    f->pessoas = (Pessoa *) malloc(N * sizeof(Pessoa));
    return f;
}

int isEmpty(Fila * f){
    assert(f != NULL);
    if(f->total == 0)
        return 1;
    return 0;
}

int isFull(Fila * f, int TamFila){
    assert(f != NULL);
    if(f->total == TamFila)
        return 1;
    return 0;
}

void inserir(Fila * f, Pessoa * x, int TamFila){
    assert(f != NULL);
    if(isFull(f,TamFila) == 1)
        exit(0);

    strcpy(f->pessoas[f->fim].nome,x->nome);
    f->pessoas[f->fim].idade = x->idade;
    f->pessoas[f->fim].condicao = x->condicao;
    f->fim = (f->fim + 1) % TamFila;
    f->total++;

}

Pessoa * remover(Fila * f,int TamFila){
    Pessoa * x = (Pessoa *) malloc(sizeof(Pessoa));
    if(isEmpty(f) == 1)
        return 0;
    strcpy(x->nome,f->pessoas[f->inicio].nome);
    x->idade = f->pessoas[f->inicio].idade;
    x->condicao = f->pessoas[f->inicio].condicao;
    f->inicio = (f->inicio + 1) % TamFila;
    f->total--;
    return x;
}

void destroy(Fila * f){
    if(f != NULL)
        free(f);
}


