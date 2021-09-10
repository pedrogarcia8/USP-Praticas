#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubronegra.h"

int main(){
    int n, x, alt = 0, o; //n -> número de operações, x -> valor, alt -> altura da rubronegra, o -> operação

    rubronegra * a = criar(); // Cria a rubronegra
    
    scanf("%d", &n); // Lê o número de operações

    while(n > 0){ // Enquanto tiver operações para ser realizadas
        scanf("%d", &o); // Lê a operação

        switch (o){ // Verifica o tipo de operação

            case 1: // Se a operação for inserir
                scanf("%d",&x); // Lê a chave que será inserida

                inserir(a, x); // Insere ela na rubronegra
            break;

            case 2: // Se a operação for sucessor
                scanf("%d",&x); // Lê a chave que será buscado o sucessor

                sucessor(a->raiz, x); // Busca o sucessor
            break;

            case 3: // Se a operação for predecessor
                scanf("%d",&x); // Lê a chave que será buscado o predecessor
                 
                predecessor(a->raiz, x); // Busca o predecessor
            break;
            case 4: // Se a operação for máximo
                printf("%d \n",max(a->raiz)); // Busca a maior chave da rubronegra
            break;

            case 5: // Se a operação for mínimo
                printf("%d \n",min(a->raiz)); // Busca a menor chave da rubronegra
            break; 

            case 6: // Se a operação for impressão em pré ordem
                pre_ordem(a->raiz); // Imprime em pré ordem
                printf("\n"); // Pula linha
            break;
            
            case 7: // Se a operação for impressão em em ordem
                em_ordem(a->raiz); // Imprime em ordem
                printf("\n");
            break;

            case 8: // Se a operação for impressão em pós ordem
                pos_ordem(a->raiz); // Imprime em pós ordem
                printf("\n"); // Pula linha
            break;
        
        }

        n--; // Decrementa o número de operações
    }

    finalizar(a->raiz); // Limpa a memória alocada para a rubronegra

    return 0;
}