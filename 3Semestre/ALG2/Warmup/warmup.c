#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.h"

Aluno * Criar(){
    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno)); // Aloca memória para a estrutura aluno

    if(aluno != NULL) //Verifica se realmente alocou memória para a estrutura aluno
        return aluno;
}

void PegarTodosRegistros(Aluno * alunos, char * nomeArquivo){
    int quantidadeAlunos = 0, contador = 0, verificador = 0;

    if(alunos == NULL || nomeArquivo == NULL)
        return;

    FILE * arquivo = AbrirArquivo(nomeArquivo); // Abre o arquivo

    while(1){

        verificador = fread(&alunos[quantidadeAlunos], sizeof(Aluno), 1, arquivo); // Lê um registro do arquivo e insere ele na estrutura de alunos

        if(verificador < 1)
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum registro, portanto, o arquivo acabou

        quantidadeAlunos++;
        alunos = (Aluno *) realloc(alunos, (quantidadeAlunos+1) * sizeof(Aluno)); //Aloca memória para a estrutuda de alunos
    }

    fclose(arquivo);

    ExibirRegistros(alunos, quantidadeAlunos);// Limite é quantidade de registros
}

void PegarRegistrosDoInicioAoMeio(Aluno * alunos, char * nomeArquivo){
    int quantidadeAlunos = 0, contador = 0, verificador = 0;

    if(alunos == NULL || nomeArquivo == NULL)
        return;

    FILE * arquivo = AbrirArquivo(nomeArquivo); // Abrir arquivo

    fseek(arquivo, 0, SEEK_END); //Posicionando o ponteiro no final do arquivo
    quantidadeAlunos = ftell(arquivo)/108; //Pegando o número de registros do arquivo -> 108 = 4(bytes int) + 50*1(char bytes) + 50*1(char bytes) + 4(bytes float)
    
    fseek(arquivo, 0, SEEK_SET); //Posicionando o ponteiro no início do arquivo novamente
    
    while(1){
        verificador = fread(&alunos[contador], sizeof(Aluno), 1, arquivo); // Lê um registro do arquivo e insere ele na estrutura de alunos

        // se o contador for igual a metade da quantidade de alunos, quer dizer que chegou no meio do arquivo
        if(verificador < 1 || contador == quantidadeAlunos / 2) 
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum registro, portanto, o arquivo acabou

        contador++;
        alunos = (Aluno *) realloc(alunos, (contador+1) * sizeof(Aluno)); //Aloca memória para a estrutuda de alunos
    }

    fclose(arquivo);

    ExibirRegistros(alunos, quantidadeAlunos/2);// Limite é a metade da quantidade de registros
}

void PegarRegistrosDoMeioAoFim(Aluno * alunos, char * nomeArquivo){
    int quantidadeAlunos = 0, contador = 0, verificador = 0;

    if(alunos == NULL || nomeArquivo == NULL)
        return;

    FILE * arquivo = AbrirArquivo(nomeArquivo);// Abrir arquivo

    fseek(arquivo, 0, SEEK_END); //Posicionando o ponteiro no final do arquivo
    quantidadeAlunos = ftell(arquivo)/108; //Pegando o número de registros do arquivo -> 108 = 4(bytes int) + 50*1(char bytes) + 50*1(char bytes) + 4(bytes float)
    fseek(arquivo, quantidadeAlunos*108/2, SEEK_SET); //Posicionando o ponteiro no meio do arquivo 
    
    while(1){
        verificador = fread(&alunos[contador], sizeof(Aluno), 1, arquivo); // Lê um registro do arquivo e insere ele na estrutura de alunos

        // se o contador for igual a metade da quantidade de alunos, quer dizer que chegou no fim do arquivo
        if(verificador < 1 || contador == quantidadeAlunos/2) 
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum registro, portanto, o arquivo acabou

        contador++;
        alunos = (Aluno *) realloc(alunos, (contador+1) * sizeof(Aluno)); //Aloca memória para a estrutuda de alunos
    }

    fclose(arquivo);

    ExibirRegistros(alunos, quantidadeAlunos/2); // Limite é a metade da quantidade de registros
}

void PegarRegistrosEmFaixa(Aluno * alunos, char * nomeArquivo, int inicioFaixa, int fimFaixa){
    int quantidadeAlunos = 0, contador = 0, verificador = 0;
    Aluno auxiliar; // Auxiliar para ajudar na leitura do arquivo

    if(alunos == NULL || nomeArquivo == NULL)
        return;

    FILE * arquivo = AbrirArquivo(nomeArquivo); // Abrir arquivo

    //108 = 4(bytes int) + 50*1(char bytes) + 50*1(char bytes) + 4(bytes float)
    fseek(arquivo, (inicioFaixa-1)*108, SEEK_SET); //Posicionando o ponteiro no início da faixa 
    
    contador = inicioFaixa;
    while(1){
        verificador = fread(&alunos[quantidadeAlunos], sizeof(Aluno), 1, arquivo); // Lê um registro do arquivo e insere ele na estrutura de alunos

        // se o contador for igual ao final da faixa, encerra a leitura
        if(verificador < 1 || contador == fimFaixa + 1) 
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum registro, portanto, o arquivo acabou

        contador++;
        quantidadeAlunos++;
        alunos = (Aluno *) realloc(alunos, (quantidadeAlunos+1) * sizeof(Aluno)); //Aloca memória para a estrutuda de alunos
    }

    fclose(arquivo);

    ExibirRegistros(alunos, quantidadeAlunos); //Limite é a quantidade de registros na faixa
}

void PegarRegistroPosicao(Aluno * alunos, char * nomeArquivo, int posicaoRegistro){
    int contador = 0, verificador = 0;

    if(alunos == NULL || nomeArquivo == NULL)
        return;

    FILE * arquivo = AbrirArquivo(nomeArquivo); // Abrir arquivo

    //108 = 4(bytes int) + 50*1(char bytes) + 50*1(char bytes) + 4(bytes float)
    fseek(arquivo, (posicaoRegistro-1)*108, SEEK_SET); //Posicionando o ponteiro no início da faixa 
    
    verificador = fread(&alunos[0], sizeof(Aluno), 1, arquivo); // Lê um registro do arquivo e insere ele na estrutura de alunos

    if(verificador < 0)
        return;

    fclose(arquivo);

    ExibirRegistros(alunos, 1); // Limite 1, porque pega um registro específico
}

FILE * AbrirArquivo(char * nomeArquivo){
    FILE * arquivo = fopen(nomeArquivo, "rb");

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