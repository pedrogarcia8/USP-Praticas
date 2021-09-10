#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "llrb.h"

allrb * criar(){
    allrb * a = (allrb *) malloc (sizeof(allrb));
    a->raiz = NULL;
    return a;
}

void finalizar(No * raiz){
    if(raiz != NULL){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}

void imprimir(No * raiz){
    if(raiz != NULL){
        printf("%d(", raiz->info);
        imprimir(raiz->esq);
        printf(",");
        imprimir(raiz->dir);
        printf(")");
    } else
        printf("null");
}

void pre_ordem(No * raiz){
    if(raiz != NULL){
        printf("%d ",raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void em_ordem(No * raiz){
    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf("%d ",raiz->info);
        em_ordem(raiz->dir);
    }
}

void pos_ordem(No * raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ",raiz->info);
    }
}

No * busca(No * raiz, int x){
    if(raiz == NULL)
        return NULL;
    else if(raiz->info == x)
        return raiz;
    else if(x < raiz->info)
        return busca(raiz->esq,x);
    else
       return busca(raiz->dir,x);
}


