#include <stdio.h>
#include <stdlib.h>
#include "grandesnumeros.h"

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

void inserir(Lista * l, int x){
    if(l == NULL)
        exit(0);

    No * n = (No *) malloc(sizeof(No));
    n->info = x;
    n->prox = NULL;
    n->ant = NULL;
    l->tam++;
    No * aux, * ant;
    ant = NULL;
    aux = l->ini;

    while(aux != NULL){
        ant = aux;
        aux = aux->prox;
    }

    if(ant == NULL){
        n->prox = l->ini;
        if(l->ini != NULL)
            l->ini->ant = n;
        l->ini = n;
        l->fim = n;
    }else{
        n->prox = ant->prox;
        ant->prox = n;
        if(n->prox != NULL)
            n->prox->ant = n;
        else
            l->fim = n;
        n->ant = ant;
    }
}

void imprimir(Lista * l){
    No * n = l->fim;
    int num = 0;
    while(n != NULL){
        
        while(num == 0){
            if(n->info == 0)
                n = n->ant;
            else
                num = 1;
        }
            
        printf("%d",n->info);
        n = n->ant;
    }
    printf("\n");
}

Lista * somar(Lista * l, Lista * l2){
    No * n1, * n2;
    Lista * sum = criar();
    int x = 0;
    n1 = l->fim;
    n2 = l2->fim;
    while(n1 != NULL || n2 != NULL){
        if(n1 != NULL && n2 != NULL){
            inserir(sum,(n1->info + n2->info + x) % 10);
            if((n1->info + n2->info + x ) >= 10)
               x = 1;
            else
               x = 0;
            n1 = n1->ant;
            n2 = n2->ant;
        }else if(n1 != NULL) {
                inserir(sum,(n1->info + x) % 10);
                if((n1->info + x ) >= 10)
                    x = 1;
                else
                    x = 0;
                n1 = n1->ant;
            }else if(n2 != NULL){
                inserir(sum,(n2->info + x) % 10);
                if((n2->info + x ) >= 10)
                    x = 1;
                else
                    x = 0;
                n2 = n2->ant;
            }
    }

    if((l->ini->info + l2->ini->info) >= 10)
        inserir(sum,1);
        
    return sum;
}

int verificaMaior(Lista * l, Lista * l2){
    if(l->ini->info == 99 && l2->ini->info != 99)
        return 0;
    if(l->ini->info != 99 && l2->ini->info == 99)
        return 1;

    if(l->tam == l2->tam){
        if(l->ini->info > l2->ini->info)
            return 1;
        else
            return 0;
    }else if(l->tam > l2->tam)
        return 1;
    else
        return 0;
}

int verificaMenor(Lista * l, Lista * l2){
    if(l->ini->info == 99 && l2->ini->info != 99)
        return 1;
    if(l->ini->info != 99 && l2->ini->info == 99)
        return 0;
    if(l->tam == l2->tam){
        if(l->ini->info >= l2->ini->info)
            return 0;
        else
            return 1;
    }else if(l->tam > l2->tam)
        return 0;
    else
        return 1;
}

int verificaIgual(Lista * l, Lista * l2){
    No * n1 = l->ini;
    No * n2 = l2->ini;
    if(l->tam != l2->tam)
        return 0;
    else{
        if(l->ini->info == 99 && l2->ini->info != 99)
            return 0;
        if(l->ini->info != 99 && l2->ini->info == 99)
            return 0;
        if(l->ini->info == 99 && l2->ini->info == 99){
            n1 = n1->prox;
            n2 = n2->prox;
        }
        while(n1 != NULL || n2 != NULL){
            if(n1->info == n2->info){
                n1 = n1->prox;
                n2 = n2->prox;
            }else
                return 0;
        }
        return 1;
    }
}