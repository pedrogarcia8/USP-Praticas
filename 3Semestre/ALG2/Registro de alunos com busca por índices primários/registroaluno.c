#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroaluno.h"

Aluno * Criar(){
    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno)); // Aloca memória para a estrutura aluno

    if(aluno != NULL) //Verifica se realmente alocou memória para a estrutura aluno
        return aluno;
}

Indice * CriarIndice(){
    Indice * indice = (Indice *) malloc(sizeof(Indice)); // Aloca memória para a estrutura indice

    if(indice != NULL) //Verifica se realmente alocou memória para a estrutura indice
        return indice;
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
            printf("-------------------------------\n");
            printf("USP number: %d\nName: %s\nSurname: %s\nCourse: %s\nTest grade: %.2f\n", 
            alunos[contador].nUSP, alunos[contador].nome, alunos[contador].sobrenome, alunos[contador].curso, alunos[contador].nota);
            printf("-------------------------------\n");
            if(contador != limite - 1)
                printf("\n");
        }
    }
}

void EscreverRegistrosArquivo(Aluno * aluno){
    FILE * arquivo = AbrirArquivo("reg.dat","ab"); // Abre o arquivo binário em modo acrescentar

    int deslocamento = Buscar(aluno[0].nUSP); // Busca esse nUSP 

    if(deslocamento != 2){ // Verifica se esse nUSP já existe
        printf("O Registro ja existe!\n");
        return;
    }

    // Pega o tamanho em bytes do arquivo e coloca o ponteiro no ínicio dele novamente
    fseek(arquivo, 0, SEEK_END); 
    deslocamento = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    inserirIndiceOrdenado(aluno[0].nUSP, deslocamento); // Insere o índice com seu deslocamento no arquivo de índices

    fwrite(&aluno[0], sizeof(Aluno), 1, arquivo); // Escreve o registro no arquivo binário
    
    fclose(arquivo); // fecha o arquivo
}

int BuscaBinaria(Indice * indice, int inicio, int fim, int valor) {//Função da busca binária
    int meio = (inicio + fim) / 2;
    
    while( inicio <= fim ){
        meio = (inicio + fim) / 2;

        if(indice[meio].nUSP == valor)
            return meio;
        else if(valor < indice[meio].nUSP)
            fim = meio - 1;
        else if (valor > indice[meio].nUSP)
            inicio = meio + 1;
    }

    return -1;
}

int Buscar(int nUSP){
    FILE * arquivoIndice = AbrirArquivo("indice.dat","rb"); // Abre o arquivo de índice em modo leitura binária
    Indice * indice = CriarIndice();
    int verificador = 0, contador = 0, tamanho = 0;

    while(1){//Lê todos os índices e armazena na estrutura de índices
        verificador = fread(&indice[tamanho], sizeof(indice), 1, arquivoIndice); 

        if(verificador < 1) 
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum índice, portanto, o arquivo acabou

        tamanho++;
        indice = (Indice *) realloc(indice, (tamanho+1) * sizeof(Indice)); //Realoca memória para a estrutuda de índices
    }

    verificador = BuscaBinaria(indice, 0, tamanho, nUSP); // Busca o índice do nUSP informado
    
    if(verificador != -1) // Se encontrou, retorna o valor do deslocamento
        return indice[verificador].deslocamento;
    
    return 2;
}

void quicksort(Indice indice[], int inicio, int fim){ //Função de ordenação quicksort recursivo
    if(inicio >= fim){
        return;
    }

    int m = (inicio + fim)/2;
    int pivo = indice[m].nUSP;
    int i = inicio;
    int j = fim;

    while(1){
        while(indice[i].nUSP < pivo){
            i++;
    
        }
        while(indice[j].nUSP > pivo){
            j--;
    
        }
        if(j <= i)
            break;

        Indice tmp = indice[i];
        indice[i] = indice[j];
        indice[j] = tmp;
        i++;
        j--;
    }

    quicksort(indice, inicio, j);
    quicksort(indice, j+1, fim);
}

void inserirIndiceOrdenado(int nUSP, int deslocamento){
    FILE * arquivoIndice = AbrirArquivo("indice.dat","rb"); // Abre o arquivo de índices em modo leitura binária
    Indice * indice = CriarIndice();
    int verificador = 0, contador = 0, tamanho = 0;

    while(1){
        verificador = fread(&indice[tamanho], sizeof(indice), 1, arquivoIndice); // Lê um índice do arquivo e insere ele na estrutura de índices

        if(verificador < 1) 
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum índice, portanto, o arquivo acabou

        tamanho++;
        indice = (Indice *) realloc(indice, (tamanho+1) * sizeof(Indice)); //Realoca memória para a estrutura de índices
    }
    fclose(arquivoIndice);

    indice = (Indice *) realloc(indice, (tamanho+1) * sizeof(Indice)); //Realoca memória para a estrutura de índices

    // Adiciona o novo índice
    indice[tamanho].nUSP = nUSP; 
    indice[tamanho].deslocamento = deslocamento;

    quicksort(indice, 0, tamanho); // Ordena a estrutura de índices

    arquivoIndice = AbrirArquivo("indice.dat","wb"); //Abre o arquivo em modo escrita binária

    for(contador = 0; contador < tamanho+1; contador++) //Reescreve todos os índices no arquivo 
        fwrite(&indice[contador], sizeof(Indice), 1, arquivoIndice); 
    
    fclose(arquivoIndice);
}

void BuscarRegistro(int nUSP){
    int deslocamento = Buscar(nUSP);// Busca esse nUSP no arquivo de índice
    
    if(deslocamento == 2){
        printf("Registro nao encontrado!\n");// Se o deslocamento for igual a 2, quer dizer que não encontrou esse nUSP
        return;
    }
    
    Aluno * aluno = Criar();

    FILE * arquivo = AbrirArquivo("reg.dat", "rb"); //Abre o arquivo de registros em modo leitura

    fseek(arquivo, deslocamento, SEEK_SET); //Posiciona o ponteiro do arquivo nesse nUSP

    fread(&aluno[0], sizeof(Aluno), 1, arquivo); //Lê o registro
    fclose(arquivo);

    ExibirRegistros(aluno, 1); //Exibi esse registro
}

void remover(int nUSP){
    int verificador = 0, contador = 0, tamanho = 0;

    int deslocamento = Buscar(nUSP); // Busca esse nUSP no arquivo de índice
    
    if(deslocamento == 2) // Se o deslocamento for igual a 2, quer dizer que não encontrou esse nUSP
        return;
    
    FILE * arquivo = AbrirArquivo("reg.dat", "rb+"); // Abre o arquivo de registros em modo leitura e escrita binária
    Aluno * aluno = Criar();

    fseek(arquivo, deslocamento, SEEK_SET); // Posiciona o ponteiro do arquivo no registro desse nUSP

    fread(&aluno[0], sizeof(Aluno), 1, arquivo); // Lê o registro inteiro

    aluno[0].nUSP = 0; // Muda o nUSP para 0 para fazer a remoção lógica

    // Posiciona o ponteiro do arquivo novamente na posição do registro desse nUSP
    fseek(arquivo, 0, SEEK_SET); 
    fseek(arquivo, deslocamento, SEEK_SET);
 
    fwrite(&aluno[0], sizeof(Aluno), 1, arquivo); //Sobrescreve o registro editado
    fclose(arquivo); // fecha o arquivo de registros

    FILE * arquivoIndice = AbrirArquivo("indice.dat", "rb"); // Abre o arquivo de índices em modo leitura binária
    Indice * indice = CriarIndice();

    while(1){ //Lê todos os índices do arquivo e armazena na estrutura auxiliar
        verificador = fread(&indice[tamanho], sizeof(indice), 1, arquivoIndice); // Lê um registro do arquivo e insere ele na estrutura de alunos

        if(verificador < 1) 
            break; // Se o verificador for menor que 1, quer dizer que não leu nenhum registro, portanto, o arquivo acabou

        tamanho++;
        indice = (Indice *) realloc(indice, (tamanho+1) * sizeof(Indice)); //Realoca memória para a estrutuda de indices
    }
    fclose(arquivoIndice); // Fecha o arquivo de índices
    
    verificador = BuscaBinaria(indice, 0, tamanho, nUSP); //Busca o índice do registro que foi removido

    arquivoIndice = AbrirArquivo("indice.dat", "wb"); //Abre o arquivo em modo escrita binária, para sobrescrevê-lo

    if(verificador != -1){//Escreve todos os índices novamente sem o que foi removido
        for(contador = 0; contador < tamanho; contador++){
            if(indice[contador].nUSP != indice[verificador].nUSP)
                fwrite(&indice[contador], sizeof(Indice), 1, arquivoIndice); // Escreve os registros no arquivo binário
        }
    }
    fclose(arquivoIndice); // Fecha o arquivo de índices
}

void criarArquivos(){
    FILE * arquivo = AbrirArquivo("indice.dat", "wb"); // Cria e limpa o arquivo de índices
    fclose(arquivo);
    arquivo = AbrirArquivo("reg.dat", "wb"); // Cria e limpa o arquivo de registros
    fclose(arquivo);
}