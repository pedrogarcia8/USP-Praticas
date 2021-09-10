#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

typedef struct livro{
    char nome[100];
    int disponibilidade;
    Fila * espera;
} Livro;

int main(){
    Livro * l;
    int quant = 0, i, resp;
    char nome[100];

    while(1){
        printf("\tMenu\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Alugar livro\n");
        printf("3 - Devolver livro\n");
        printf("0 - Sair\n");
        scanf("%d",&resp);
        system("cls");

        switch(resp){
            case 0: exit(0); break;
            case 1:
                printf("Digite o nome do livro: ");
                scanf(" %[^\n]s",nome);

                if(quant == 0)
                    l = (Livro *) malloc(sizeof(Livro));
                else
                    l = (Livro *) realloc(quant + 1, sizeof(Livro));

                l[quant].disponibilidade = 1;
                strcpy(l[quant].nome,nome);
                l[quant].espera = Create();
                quant++;
                printf("Livro %s cadastrado com sucesso!",nome);
                Sleep(1500);
                system("cls");
            break;
            case 2:
                printf("Digite o nome do livro: ");
                scanf(" %[^\n]s",nome);

                for(i = 0; i < quant; i++){
                    if(stricmp(l[i].nome,nome) == 0){
                        if(l[i].disponibilidade == 0){
                            printf("Livro indisponivel! Voce sera adicionado na fila de espera.\n");
                            printf("Digite o seu nome: ");
                            scanf(" %[^\n]s",nome);
                            Insert(l[i].espera,nome);
                            printf("Voce foi adicionado na fila de espera!\n");
                            break;
                        }else{
                            l[i].disponibilidade = 1;
                            printf("Livro %s alugado com sucesso!\n",nome);
                        }
                    }
                }
            break;
            case 3:
                printf("Digite o nome do livro: ");
                scanf(" %[^\n]s",nome);

                for(i = 0; i < quant; i++){
                    if(stricmp(l[i].nome,nome) == 0){
                        if(IsEmpty(l[i].espera) == 1)
                            l[i].disponibilidade = 1;
                        else{
                            printf("O livro sera alugado por %s",l[i].espera->pessoas[l[i].espera->inicio]);
                            Remove(l[i].espera,nome);
                        }
                    }
                }
            break;
        }


    }

    return 0;
}
