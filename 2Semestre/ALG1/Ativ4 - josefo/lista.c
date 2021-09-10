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

int inserir(Lista * l, int x){
    assert(l != NULL);

    No * p = (No *) malloc(sizeof(No));
    
    p->info = x;

    if(l->ini == NULL){
        l->ini = p;
        l->fim = l->ini;
        l->ini->prox = l->ini;
    }else{
        p->prox = l->ini; 
        l->fim->prox = p;
        l->fim = l->fim->prox;
    }
    l->tam++;
    return 1;

}

int remover(Lista * l, int x){
    assert(l != NULL);
 
    No * ant = l->fim;
    No * rem = l->ini;
   //printf("rif: %d ",rem->info);
    while(rem->info != x){
        ant = rem;
        rem = rem->prox;
        //printf("rid: %d ",rem->info);
    }
    //printf("a: %d r: %d\n",ant->info, rem->info);
    ant->prox = rem->prox;
        
    if(rem == l->ini){
        l->ini = rem->prox;
    }else if(rem == l->fim){
        l->fim = ant;
    }else if(rem == ant){
        l->ini = NULL;
        l->fim = NULL;
    }
    int retorno = rem->info;
    l->tam--;
  //  printf("retorno: %d i: %d f: %d\n", rem->info, l->ini->info, l->fim->info);
    free(rem);  
    
    return retorno;
}

void libera(Lista * l){
    if(l != NULL){
        No * p = l->ini;
        while(p != NULL){
            l->ini = p->prox;
            free(p);
            p = l->ini;
        }
        free(l);
    }
}

void imprimir(Lista * l){
    assert(l != NULL);
  
    printf("%d\n",l->fim->info);
} 
      
int isEmpty(Lista * l){
    assert(l != NULL);

    if(l->tam == 0)
        return 1;
    else
        return 0;
    
}
    
    
int josefo(Lista * l, int k){
    No * aux = l->ini;
    int cont = 0, r;
    while(isEmpty(l) != 1){
        cont = 1;
        while(cont < k){
            aux = aux->prox;
            cont++;
        }
        int rem = aux->info;
        aux = aux->prox;
        r = remover(l,rem);
    }
    return r;
}