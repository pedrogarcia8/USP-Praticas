#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.h"

int main(){
    int tamanho = 0;
    char * itemSeparado, linhaRegistro[112];

    Aluno * alunosEntrada = Criar(); // Cria a estrutura de alunos e aloca memória para ela
    Aluno * alunosSaida = Criar(); // Cria a estrutura de alunos e aloca memória para ela

    while(scanf(" %[^\n]s", linhaRegistro) != EOF){ // Lê linha por linha até o final do arquivo CSV
        itemSeparado = strtok(linhaRegistro, ","); // Separa a linha lida em substrings a partir do delimitador ","
        alunosEntrada[tamanho].nUSP = atoi(itemSeparado); // Pega a primeira substring que é o nUSP

        itemSeparado = strtok(NULL, ","); //Pega a segunda substring a partir da posição da primeira vírgula
        strcpy(alunosEntrada[tamanho].nomeCompleto, itemSeparado); // Pega a segunda substring que é o nomeCompleto

        itemSeparado = strtok(NULL, ","); //Pega a terceira substring a partir da posição da segunda vírgula
        strcpy(alunosEntrada[tamanho].curso, itemSeparado); // Pega a terceira substring que é o curso

        itemSeparado = strtok(NULL, ","); //Pega a quarta substring a partir da posição da terceira vírgula
        alunosEntrada[tamanho].nota = atof(itemSeparado); // Pega a quarta substring que é a nota
        itemSeparado = NULL; // Limpa a memória

        tamanho++; // acrescenta + 1 no tamanho da estrutura
        alunosEntrada = (Aluno *) realloc(alunosEntrada, (tamanho+1) * sizeof(Aluno)); //Realoca memória para a estrutura de aluno
    }    

    EscreverRegistrosArquivo(alunosEntrada, tamanho); // Chama a função para escrever os registros lidos no arquivo binário

    LerUltimosDezRegistros(alunosSaida, "reg.dat"); // Chama a função para ler os últimos 10 registros do arquivo binário e exibir
    
    alunosEntrada = NULL; // Limpa a memória
    alunosSaida = NULL; // Limpa a memória

    return 0;
}
