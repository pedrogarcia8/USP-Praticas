#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
    int N, i = 0;
    char modo[6];
    Pessoa * p = (Pessoa *) malloc(sizeof(Pessoa));
    Fila * grupo1, * grupo2, * grupo3, * grupo4;

    scanf("%d",&N);

    if((N > 100) && (N < 1))
        exit(0);

    grupo1 = criar(N);
    grupo2 = criar(N);
    grupo3 = criar(N);
    grupo4 = criar(N);

    while(i < N){
        i++;
        scanf(" %s",modo);
        if(strcmp(modo,"ENTRA") == 0){
            scanf("%s",p->nome);
            scanf("%d",&p->idade);
            scanf("%d",&p->condicao);
            if((p->idade >= 60) && (p->condicao == 1))
                inserir(grupo1,p,N);
            else if((p->idade < 60) && (p->condicao == 1))
                inserir(grupo2,p,N);
            else if((p->idade >= 60) && (p->condicao == 0))
                inserir(grupo3,p,N);
            else if((p->idade < 60) && (p->condicao == 0))
                inserir(grupo4,p,N);
        }else if(strcmp(modo,"SAI") == 0){
            if(isEmpty(grupo1) != 1)
                p = remover(grupo1,N);
            else if(isEmpty(grupo2) != 1)
                p = remover(grupo2,N);
            else if(isEmpty(grupo3) != 1)
                p = remover(grupo3,N);
            else if(isEmpty(grupo4) != 1)
                p = remover(grupo4,N);
            else{
                printf("FILA VAZIA\n");
                continue;
            }
            printf("%s %d %d\n",p->nome,p->idade,p->condicao);
        }
    }

    free(p);
    destroy(grupo1);
    destroy(grupo2);
    destroy(grupo3);
    destroy(grupo4);
    return 0;
}
