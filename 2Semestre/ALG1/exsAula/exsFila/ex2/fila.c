#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "fila.h"

fila_t * criar(){
    fila_t * f;
    f = (fila_t *) malloc(sizeof(fila_t));
    assert(f != NULL);
    f->total = 0;
    f->fim = 0;
    f->inicio = 0;
    return f;
}

int isEmpty(fila_t * f){
    assert(f != NULL);
    if(f->total == 0)
        return 1;
    return 0;
}

int isFull(fila_t * f){
    assert(f != NULL);
    if(f->total == TamFila)
        return 1;
    return 0;
}

int inserir(fila_t * f, elem x){
    if(isFull(f) == 1)
        return 0;
    f->itens[f->fim] = x;
    f->fim = (f->fim + 1) % TamFila;
    f->total++;
    return 1;
}

int remover(fila_t * f, elem *x){
    if(isEmpty(f) == 1)
        return 0;
    *x = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TamFila;
    f->total--;
    return 0;
}

void destroy(fila_t * f){
    if(f != NULL)
        free(f);
}


