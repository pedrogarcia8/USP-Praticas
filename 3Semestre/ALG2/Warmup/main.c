#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

int main(){
    int operacao = 0, inicioFaixa = 0, fimFaixa = 0, posicaoRegistro = 0, contador = 0;
    char nomeArquivoBinario[100];

    Aluno * alunos = Criar();

    scanf(" %[^\n]s", nomeArquivoBinario);
    scanf("%d", &operacao);

    switch (operacao){
        case 1:{
            PegarTodosRegistros(alunos, nomeArquivoBinario); // Chama a função para ler todos os registros e exibi-los
        }break;
            
        case 2:{
            PegarRegistrosDoInicioAoMeio(alunos, nomeArquivoBinario); // Chama a função para ler os registros do início até o meio do arquivo e exibi-los
        }break;

        case 3:{
            PegarRegistrosDoMeioAoFim(alunos, nomeArquivoBinario); // Chama a função para ler os registros do meio até o fim do arquivo e exibi-los
        }break;

        case 4:{
            scanf("%d", &inicioFaixa);
            scanf("%d", &fimFaixa);
            PegarRegistrosEmFaixa(alunos, nomeArquivoBinario, inicioFaixa, fimFaixa); // Chama a função para ler os registros de uma faixa do arquivo e exibi-los
        }break;

        case 5:{
            scanf("%d", &posicaoRegistro);
            PegarRegistroPosicao(alunos, nomeArquivoBinario, posicaoRegistro);// Chama a função para ler um registro específico do arquivo e exibi-lo
        }break;
    }

    alunos = NULL;// Limpa a memória alocada para a estrutura de alunos

    return 0;
}
