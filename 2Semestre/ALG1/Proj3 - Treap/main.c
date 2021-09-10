#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treap.h"

int main(){
    int n, num, pri, alt = 0, nivel; //n -> número de operações, num -> chave, p -> prioridade, alt -> altura da treap, nivel -> nivel atual da treap
    char operacao[11], impressao[9]; // operacao -> tipo de operação, impressao -> tipo de impressão

    treap * a = criar(); // Cria a treap

    scanf("%d", &n); // Lê o número de operações

    while(n > 0){ // Enquanto tiver operações para ser realizadas
        scanf(" %s", operacao); // Lê a operação

        if(strcmp(operacao,"insercao") == 0){ // Se a operação for inserção

            scanf("%d %d", &num, &pri); //Lê a chave e a sua prioridade
            inserir(a, num, pri); // Insere ela na treap

        }else if(strcmp(operacao,"remocao") == 0){// Se a operação for remoção

            scanf("%d", &num); // Lê a chave
            remover(a, num); // Remove ela da treap

        }else if(strcmp(operacao,"buscar") == 0){ // Se a operação for buscar
            scanf("%d", &num); // Lê a chave

            if(busca(a->raiz, num) == NULL) // Verifica se encontrou a chave
                printf("0\n"); // Caso não, exibe falso "0"
            else
                printf("1\n"); // Caso sim, exibe verdadeiro "1"

        }else if(strcmp(operacao,"impressao") == 0){ // Se a operação for impressão
            scanf(" %s", impressao); // Lê o tipo de impressão

            if(strcmp(impressao,"preordem") == 0) // Se a impressão for pré ordem
                pre_ordem(a->raiz); // Imprime em pré ordem

            else if(strcmp(impressao,"posordem") == 0) // Se a impressão for pós ordem
                pos_ordem(a->raiz); // Imprime em pós ordem

            else if(strcmp(impressao,"ordem") == 0) // Se a impressão for em ordem
                em_ordem(a->raiz); // Imprime em em ordem

            else if(strcmp(impressao,"largura") == 0){ // Se a impressão for largura (por nível)
                alt = altura(a->raiz); // Pega a altura da treap, que será o nível máximo

                for(nivel = 0; nivel < alt; nivel++) // Percorrerá os níveis da treap
                    largura(a->raiz, nivel); // Imprime de acordo com o nível
            }

            printf("\n"); // Pula linha para a formatação da saída ser correta
        }

        n--; // Decrementa o número de operações
    }

    finalizar(a->raiz); // Limpa a memória alocada para a treap

    return 0;
}