#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cartas.h"

PilhaCartas * Create(int tam){
    PilhaCartas * pc = (PilhaCartas *) malloc(sizeof(PilhaCartas));

    assert(pc != NULL);

    pc->topo = -1;

    pc->cartas = (int *) calloc(tam, sizeof(int));

    assert(pc->cartas != NULL);

    return pc;
}

void Destroy(PilhaCartas * pc){
    free(pc);

    pc = NULL;
}

void Push(PilhaCartas * pc, int carta){
    assert(pc != NULL);

    pc->topo++;

    pc->cartas[pc->topo] = carta;

}

void Pop(PilhaCartas * pc){
    assert(pc != NULL);

    if(pc->topo >= 0)
        pc->topo -= 1;
}
