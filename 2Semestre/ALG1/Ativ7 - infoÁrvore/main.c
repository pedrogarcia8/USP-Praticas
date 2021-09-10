#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main(){
    int n, id, e, d, i = 0, g, d2;
    No * pai, * aux;
    Arvore * a = criar();
    char t[8];

    inserir_esq(a,0,-1);

    scanf("%d",&n);

    while(i < n){
        scanf("%d %d %d",&id,&e,&d);
        inserir_esq(a,e,id);
        inserir_dir(a,d,id);
        i++;
    }

    /*for(i = 0; i < n; i++){
        pai = busca(a->raiz,i);
        e = pai->esq->info;
        d = pai->dir->info;

        if(pai != NULL){
            g = grau(pai);
            strcpy(t,tipo(pai,busca_pai(a->raiz,i)));
        }
        
        pai = busca_pai(a->raiz,i);
        
        if(pai == NULL)
            printf("no %d: pai = -1, altura = %d, grau = %d, filhos = (%d,%d), tipo = %s\n", i, altura(busca(a->raiz,i)) - 1, g, e, d, t);
        else
            printf("no %d: pai = %d, altura = %d, grau = %d, filhos = (%d,%d), tipo = %s\n", i, pai->info, altura(busca(a->raiz,i)) - 1, g, e, d, t);
    }*/
    imprimirInfos(a->raiz,a->raiz);
        
    return 0;
}
