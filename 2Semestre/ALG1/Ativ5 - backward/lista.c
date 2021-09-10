#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lista.h"

Lista * criar(){
    Lista * l;
    l = (Lista *) malloc(sizeof(Lista));
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

void liberar(Lista * l){
    if(l != NULL){
        No * aux = l->ini;
        while(aux != NULL){
            l->ini = l->ini->prox;
            free(aux);
            aux = l->ini;
        }
        free(l);
    }
}

void imprimir(Lista * l){
    assert(l != NULL);

    No * n = l->ini;
    No * p = l->ini;
    int cont = 0;
    if(l->ini == NULL){
        printf("-1\n");
    }else{
        while(n != NULL){
            cont = 0;
            p = l->ini;
            if(n->ant == NULL)
                printf("[%d,%d] ", n->info, n->tempo);
            else{
              while(p != n->ant){
                    p = p->prox;
                    cont++;
                }
                printf("[%d,%d,%d] ", n->info, n->tempo, cont);
            }
            n = n->prox;
        }
        printf("\n");
    }
}

void inserir(Lista * l, int x, int j, int tempo){
    assert(l != NULL);
    int i;
    No * n = (No *) malloc(sizeof(No));
    n->info = x;
    n->tempo = tempo;
    n->prox = NULL;
    No * ant;
    No * aux = l->ini;
    l->tam++;
    if(j == 0)
        n->ant = NULL;
    else{
        j = l->tam - j;
        for(i = 0; i < j-1; i++){
            aux = aux->prox;
        }
        n->ant = aux;
        //printf("%d\n",j);
    }
    if(l->ini == NULL){
        l->ini = n;
        l->fim = n;
    }else{
        ant = l->fim;
        ant->prox = n;
        l->fim = n;
    }

}

void remover(Lista * l, int x){
    assert(l != NULL);

    No * n = l->ini;
    No * p = l->ini;
    No * ant;
    while(n->info != x){
        ant = n;
        n = n->prox;
    }
    while(p != NULL){
        if(p->ant != NULL)
        if(p->ant == n){
            p->ant = NULL;
        }
        p = p->prox;
    }
    if(n == l->ini){
        l->ini = l->ini->prox;
        free(n);
    }else if(n == l->fim){
        l->fim = ant;
        free(n);
    }else{
        ant->prox = n->prox;
        free(n);
    }
    l->tam--;
}
