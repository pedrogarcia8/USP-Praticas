#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dicionario.h"

int main(){
    char tipo[11]; // Armazena o tipo de operação
    Lista * l = criar(); // Cria a Skip List
    time_t t; // Armazena o tempo atual
    srand((unsigned) time(&t));// Obtém o tempo atual e alimenta a função rand() para sempre gerar número aleatórios
    
    while(scanf(" %s",tipo) != EOF){// Obtém o tipo de operação e faz isso até o final do arquivo de entrada

        if(strcmp(tipo,"insercao") == 0){// Verifica se o tipo de operação é "inserção"

            Palavra * p = (Palavra *) malloc(sizeof(Palavra)); // Caso sim, cria um ponteiro para a estrutura da palavra e aloca memória

            scanf(" %s",p->verbete);// Obtém o verbete 
            scanf(" %[^\n]s",p->definicao); // Obtém a definição

            if(inserir(l,p->verbete,p->definicao) == 0) // Insere o verbete e sua definição na Skip List e verifica se deu certo
                printf("OPERACAO INVALIDA\n"); // Caso não, exibe a mensagem de erro

            free(p); // Limpa a memória alocada para o ponteiro da estrutura da palavra

        }else if(strcmp(tipo,"alteracao") == 0){// Verifica se o tipo de operação é "alteração"
        
            Palavra * p = (Palavra *) malloc(sizeof(Palavra));// Caso sim, cria um ponteiro para a estrutura da palavra e aloca memória

            scanf(" %s",p->verbete);// Obtém o verbete que terá a definição alterada
            scanf(" %[^\n]s",p->definicao);// Obtém a nova definição

            if(alterar(l,p->verbete,p->definicao) == 0)// Altera a definição do verbete e verifica se deu certo
                printf("OPERACAO INVALIDA\n");// Caso não, exibe a mensagem de erro

            free(p);// Limpa a memória alocada para o ponteiro da estrutura da palavra

        }else if(strcmp(tipo,"remocao") == 0){// Verifica se o tipo de operação é "remoção"

            Palavra * p = (Palavra *) malloc(sizeof(Palavra));// Caso sim, cria um ponteiro para a estrutura da palavra e aloca memória

            scanf(" %s",p->verbete); // Obtém o verbete que será removido

            if(remover(l,p->verbete) == 0)// Remove o verbete e sua definição e verifica se deu certo
                printf("OPERACAO INVALIDA\n");// Caso não, exibe a mensagem de erro

            free(p);// Limpa a memória alocada para o ponteiro da estrutura da palavra

        }else if(strcmp(tipo,"busca") == 0){// Verifica se o tipo de operação é "busca"

            Palavra * p = (Palavra *) malloc(sizeof(Palavra));// Caso sim, cria um ponteiro para a estrutura da palavra e aloca memória

            scanf(" %s",p->verbete);// Obtém o verbete que será buscado

            strcpy(p->definicao,buscar(l,p->verbete));// Busca o verbete, se tiver encontrado retornará a definição, caso contrário retornará "0"

            if(strcmp(p->definicao,"0") == 0)// Verifica se encontrou o verbete
                printf("OPERACAO INVALIDA\n");// Caso não, exibe a mensagem de erro
            else
                printf("%s %s\n",p->verbete, p->definicao);// Caso sim, exibe a definição do verbete

            free(p);// Limpa a memória alocada para o ponteiro da estrutura da palavra

        }else if(strcmp(tipo,"impressao") == 0){
            char letra;// Armazena a letra

            scanf(" %c",&letra); // Obtém a letra

            //Imprime todos os verbetes que comecem com a letra digitada e suas respectivas definições e verifica se deu certo
            if(imprimirPorLetra(l,letra) == 0)
                printf("NAO HA PALAVRAS INICIADAS POR %c\n",letra);// Caso não, exibe a mensagem de erro
            
        }
       
    }

    liberar(l); // Libera a memória alocada da lista

    return 0;
}
