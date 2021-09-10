#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.h"

Aluno * Criar(){
    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno)); // Aloca memória para a estrutura aluno

    if(aluno != NULL) //Verifica se realmente alocou memória para a estrutura aluno
        return aluno;
}

void LerUltimosDezRegistros(Aluno * alunos, char * nomeArquivo){
    int contador = 0, verificador = 0, quantidadeAlunos = 0;

    if(alunos == NULL || nomeArquivo == NULL)
        return;

    FILE * arquivo = AbrirArquivo(nomeArquivo, "rb"); // Abrir arquivo em modo leitura

    fseek(arquivo, 0, SEEK_END); //Posicionando o ponteiro no final do arquivo
    quantidadeAlunos = ftell(arquivo)/108; //Pegando o número total de registros do arquivo 
    //108 = 4(bytes int) + 50*1(char bytes) + 50*1(char bytes) + 4(bytes float)
    fseek(arquivo, (quantidadeAlunos-10) * 108, SEEK_SET); //Posicionando o ponteiro no começo dos últimos 10 registros do arquivo

    while(1){
        verificador = fread(&alunos[contador], sizeof(Aluno), 1, arquivo); // Lê um registro do arquivo e insere ele na estrutura de alunos

        if(verificador < 1) 
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum registro, portanto, o arquivo acabou

        contador++;
        alunos = (Aluno *) realloc(alunos, (contador+1) * sizeof(Aluno)); //Realoca memória para a estrutuda de alunos
    }

    fclose(arquivo); // fecha o arquivo

    ExibirRegistros(alunos, 10); // Limite 10, porque pega somente os últimos 10 registros
}

FILE * AbrirArquivo(char * nomeArquivo, char * tipoAbertura){
    FILE * arquivo = fopen(nomeArquivo, tipoAbertura);

    if(arquivo != NULL) // Verifica se abriu o arquivo
        return arquivo;  
}

void ExibirRegistros(Aluno * alunos, int limite){
    int contador = 0;
    
    if(alunos != NULL){ //Lista os registros da estrutura alunos
        for(contador = 0; contador < limite; contador++){
            printf("nUSP: %d\nNome: %s\nCurso: %s\nNota: %.2f", alunos[contador].nUSP, alunos[contador].nomeCompleto, alunos[contador].curso, alunos[contador].nota);
            if(contador != limite - 1)
                printf("\n\n");
        }
    }
}

void EscreverRegistrosArquivo(Aluno * alunos, int tamanho){
    FILE * arquivo = AbrirArquivo("reg.dat","wb"); // Abre o arquivo binário em modo escrita
    int contador = 0;

    for(contador = 0; contador < tamanho; contador++){
        fwrite(&alunos[contador], sizeof(Aluno), 1, arquivo); // Escreve os registros no arquivo binário
    }

    fclose(arquivo); // fecha o arquivo
}

