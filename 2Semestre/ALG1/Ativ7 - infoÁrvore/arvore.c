#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arvore.h"

Arvore * criar() {
    Arvore * a = (Arvore *) malloc(sizeof(Arvore));
    a->raiz = NULL;

    return a;
}

int esta_vazia(Arvore * a) {
    assert(a != NULL);

    if(a->raiz == NULL)
        return 1;

    return 0;
}

void finalizar(No * raiz) {
    if(raiz != NULL) {
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}

void imprimir(No * raiz) {
    if(raiz != NULL) {
        printf("%d(", raiz->info);
        imprimir(raiz->esq);
        printf(",");
        imprimir(raiz->dir);
        printf(")");
    }else 
        printf("null");
    
}

int altura(No * raiz) {
    if(raiz == NULL)
        return 0;

    int alt_esq = 1 + altura(raiz->esq);
    int alt_dir = 1 + altura(raiz->dir);

    if(alt_esq > alt_dir)
        return alt_esq;
    else
        return alt_dir;
}

No * busca(No * raiz, int x) {
    if(raiz == NULL)
        return NULL;

    if(raiz->info == x)
        return raiz;

    No * p = busca(raiz->esq, x);
    if(p == NULL)
        p = busca(raiz->dir, x);

    return p;
}

No * busca_pai(No * raiz, int x) {

    if(raiz == NULL)
        return NULL;
    
    if(raiz->esq != NULL && raiz->esq->info == x)
        return raiz;

    if(raiz->dir != NULL && raiz->dir->info == x)
        return raiz;

    No *p = busca_pai(raiz->esq, x);
    if(p == NULL)
        p = busca_pai(raiz->dir, x);

    return p;
}

int inserir_esq(Arvore * a, int x, int pai) {
    No * p = (No *) malloc(sizeof(No));
    p->esq = NULL;
    p->dir = NULL;
    p->info = x;

    if(pai == -1) {
        if(a->raiz == NULL) {
            a->raiz = p;
        }else{
            free(p);
            return 0;
        }
    }else{
        No * aux = busca(a->raiz, pai);
        if(aux != NULL && aux->esq == NULL) 
            aux->esq = p;
        else{
            free(p);
            return 0;
        }
    }

    return 1;
}

int inserir_dir(Arvore * a, int x, int pai) {
    No * p = (No *) malloc(sizeof(No));
    p->esq = NULL;
    p->dir = NULL;
    p->info = x;

    if(pai == -1) {
        if(a->raiz == NULL)
            a->raiz = p;
        else{
            free(p);
            return 0;
        }
    }else{
        No * aux = busca(a->raiz, pai);
        if(aux != NULL && aux->dir == NULL)
            aux->dir = p;
        else {
            free(p);
            return 0;
        }
    }

    return 1;
}

int grau(No * n){
    if(n->esq->info == -1 && n->dir->info == -1)
        return 0;
    else if(n->esq->info == -1 || n->dir->info == -1)
        return 1;
    else
        return 2;
}

char * tipo(No * n, No * pai){
    if(pai == NULL)
        return "raiz";
    else if(n->esq->info == -1 && n->dir->info == -1)
        return "folha";
    else
        return "interno";
}

void imprimirInfos(No * raiz, No * raizInicial){
    if(raiz->info != -1){
        No * pai = busca(raiz,raiz->info);
        int e = pai->esq->info;
        int d = pai->dir->info;
        int g; char t[8];
        if(pai != NULL){
            g = grau(pai);
            strcpy(t,tipo(pai,busca_pai(raizInicial,raiz->info)));
        }
        
        pai = busca_pai(raizInicial,raiz->info);
       
        int p;
        if(pai == NULL)
            p = -1;
        else
            p = pai->info;

        printf("no %d: pai = %d, altura = %d, grau = %d, filhos = (%d,%d), tipo = %s\n", raiz->info, p, altura(busca(raiz,raiz->info)) - 1, g, e, d, t);
    
        imprimirInfos(raiz->esq,raizInicial);
        imprimirInfos(raiz->dir,raizInicial);
    }
}