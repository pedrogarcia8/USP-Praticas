#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

Fila * Create(){
    Fila * f;
    f = (Fila *) malloc(sizeof(Fila));
    assert(f != NULL);
    f->total = 0;
    f->fim = 0;
    f->inicio = 0;
    return f;
}

int IsEmpty(Fila * f){
    assert(f != NULL);
    if(f->total == 0)
        return 1;
    return 0;
}

int Insert(Fila * f, char * x){
    assert(f != NULL);

    f->total++;
    if(f->total == 1)
        f->pessoas = (char **) malloc(1 * sizeof(char *));
    else
        f->pessoas = (char **) realloc(f->total, sizeof(char *));

    strcpy(f->pessoas[f->fim],x);
    f->fim = f->fim + 1;

    return 1;
}

int Remove(Fila * f, char * x){
    if(IsEmpty(f) == 1)
        return 0;

    *x = f->pessoas[f->inicio];

    free(f->pessoas[f->inicio]);
    f->inicio = f->inicio + 1;
    f->total--;

    return 0;
}

void Destroy(Fila * f){
    int i;
    if(f != NULL){
        for(i = f->inicio; i < f->total; i++)
            free(f->pessoas[i]);
        free(f);
    }
}



