#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha.h"

Pilha * Create(){
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));
    assert(p != NULL);

    p->caracteres = (char *) malloc(1 * sizeof(char));
    p->topo = -1;

    return p;
}

void Destroy(Pilha * p){
    assert(p != NULL);
    assert(p->caracteres != NULL);

    while(p->topo >= 0){
        free(p->caracteres[p->topo]);
        p->topo--;
    }

    free(p);
    p = NULL;
}

void Push(Pilha * p, char c){
    assert(p != NULL);

    if(p->topo != -1)
        p->caracteres = (char *) realloc(p->caracteres, (p->topo + 2) * sizeof(char));

    p->topo++;
    p->caracteres[p->topo] = c;
}
