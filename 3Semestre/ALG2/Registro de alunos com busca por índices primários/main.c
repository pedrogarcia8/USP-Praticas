#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroaluno.h"

int main(){
    int tamanho = 0, nUSP = 0;
    char * itemSeparado, linhaRegistro[162], opcao[7];

    criarArquivos(); //Chama a função para criar os arquivos

    Aluno * aluno = Criar(); // Cria a estrutura de alunos e aloca memória para ela

    while(1){
        scanf(" %s", opcao); 

        if(strcmp(opcao, "insert") == 0){
            scanf(" %[^\n]s", linhaRegistro);
            itemSeparado = strtok(linhaRegistro, ","); // Separa a linha lida em substrings a partir do delimitador ","
            aluno[0].nUSP = atoi(itemSeparado); // Pega a primeira substring que é o nUSP

            itemSeparado = strtok(NULL, ","); //Pega a segunda substring a partir da posição da primeira vírgula
            strcpy(aluno[0].nome, itemSeparado); // Pega a segunda substring que é o nome

            itemSeparado = strtok(NULL, ","); //Pega a terceira substring a partir da posição da segunda vírgula
            strcpy(aluno[0].sobrenome, itemSeparado); // Pega a terceira substring que é o sobrenome

            itemSeparado = strtok(NULL, ","); //Pega a quarta substring a partir da posição da terceira vírgula
            strcpy(aluno[0].curso, itemSeparado); // Pega a quarta substring que é o curso

            itemSeparado = strtok(NULL, ","); //Pega a quinta substring a partir da posição da quarta vírgula
            aluno[0].nota = atof(itemSeparado); // Pega a quinta substring que é a nota
            itemSeparado = NULL; // Limpa a memória

            EscreverRegistrosArquivo(aluno); // Chama a função para escrever o registro lido no arquivo binário
            
        }else if(strcmp(opcao, "search") == 0){

            scanf("%d", &nUSP);
            BuscarRegistro(nUSP); // Busca o registro através do nUSP informado

        }else if(strcmp(opcao, "delete") == 0){

            scanf("%d", &nUSP); // Remove o registro através do nUSP informado
            remover(nUSP);

        }else if(strcmp(opcao, "exit") == 0){

            aluno = NULL; // Limpa a memória
            exit(0); // Encerra o programa
        }    
    }

    return 0;
}
