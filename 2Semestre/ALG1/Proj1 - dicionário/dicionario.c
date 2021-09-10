#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dicionario.h"

Lista * criar(){
    Lista * l; // Cria um ponteiro para a estrutura da Skip List
    l = (Lista *) malloc(sizeof(Lista));// Aloca memória para o ponteiro criado

    l->nivel = 0; // Inicializa o maior nível atual da Skip List
    l->maiorNivel = 21;// Inicializa o nível máximo da Skip List

    No * n = (No *) malloc(sizeof(No)); // Cria um ponteiro para a estrutura de nó da Skip List e aloca memória para ele

    n = criarNo("-1","-1",0,NULL,NULL); // Chama a função criar nó para criar o primeiro nó de cabeçalho da Skip List

    l->anteriorAcima = n; // Armazena o nó criado no primeiro cabeçalho da Skip List

    return l;// Retorna a Skip List
}

No * criarNo(char * verbete, char * definicao, int nivel, No * prox, No * abaixo){
    No * n;// Cria um ponteiro para a estrutura de nó da Skip List
    n = (No *) malloc(sizeof(No));// Aloca memória para o ponteiro criado

    Palavra * p = (Palavra *) malloc(sizeof(Palavra));// Cria um ponteiro para a estrutura de palavra (verbete + definição) da Skip List

    strcpy(p->verbete,verbete);// Copia o verbete que o usuário inseriu para a estrutura de palavra
    strcpy(p->definicao,definicao);// Copia a definição que o usuário inseriu para a estrutura de palavra

    n->valor = p; // Copia a palavra criada para o valor (palavra) do nó da Skip List
    n->nivel = nivel;// Copia o nível aleatório gerado para o nível do nó da Skip List
    n->prox = prox;// Aponta o novo nó para o próximo nó da Skip list
    n->abaixo = abaixo;// Aponta o novo nó para o nó abaixo do nó atual na Skip list

    return n;// Retorna o novo nó criado
}

int gerarNiveis(){
    int nivel = rand() % 20, cont = 0;// Inicializa a variável nível com um número aleatório entre 0 e 20 e inicializa o contador

    while(nivel % 2 == 0){// Repetirá a geração de números aleatórios até que seja um número par
        nivel = rand() % 20; // Atribui números aleatórios para a variável nível
        cont++;// Incrementa o contador
    }

    // Quando o nível for um número ímpar, sai do while e retorna o contador
    return cont; 
}

int inserir(Lista * l, char * verbete, char * definicao){

    int nivel = gerarNiveis(); // Gera um nível aleatório para o novo verbete
    int nivelAtual, i = 0; 
   
    No * sentinela = l->anteriorAcima; // Cria um ponteiro auxiliar e posiciona ele no primeiro cabeçalho da Skip List
    No * atualizacoes[l->maiorNivel]; // Cria um ponteiro de um vetor auxiliar para ajudar na inserção dos níveis
    
    while(sentinela->nivel != 0){ // Percorrerá a Skip List até o nível inicial
        // Percorrerá o nível atual até o fim ou até encontrar um verbete maior alfabeticamente
        while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
            sentinela = sentinela->prox;// Aponta o atual para o próximo
        
        atualizacoes[sentinela->nivel] = sentinela; // Atribui no vetor auxiliar o ponteiro para o nó que sera atualizado
        sentinela = sentinela->abaixo;// Aponta o atual para o abaixo
    }
    // Percorrerá o nível inicial até o fim ou até encontrar um verbete maior alfabeticamente
    while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
        sentinela = sentinela->prox;// Aponta o atual para o próximo

    if(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) == 0) // verifica se o verbete já existe
        return 0;

    atualizacoes[sentinela->nivel] = sentinela;// Atribui no vetor auxiliar o ponteiro para o nó que sera atualizado
    
    nivelAtual = 0;
    // Percorrerá até o nivel atual ser maior que o nível aleatório gerado ou maior que o nível que possui elementos da Skip List
    while(nivelAtual <= nivel && nivelAtual <= l->nivel){
        No * n1 = criarNo(verbete,definicao,nivelAtual,NULL,NULL); // Cria e inicializa o novo nó que conterá os valores para a inserção

        n1->prox = atualizacoes[nivelAtual]->prox; // Liga o novo nó criado com o nó da frente 

        if(nivelAtual == 0) // Verifica se o nível atual for o inicial
            n1->abaixo = NULL; // Caso sim, o nível abaixo dele é NULL porque não existe nível abaixo do inicial
        else
            n1->abaixo = atualizacoes[nivelAtual - 1]->prox;//Caso contrário, liga o novo nó com o nó abaixo da frente
        
        atualizacoes[nivelAtual]->prox = n1; // Atribui no vetor auxiliar o novo nó para que ele seja considerado na lógica acima
        
        nivelAtual++;// Incrementa o nível atual
    }
    
    for(i = l->nivel+1; i <= nivel; i++){  // Percorrerá até o nível aleatório gerado

        // Cria e inicializa o novo nó que conterá os valores para a inserção
        No * n2 = criarNo(verbete,definicao,i,NULL,atualizacoes[i-1]->prox); 

        // Cria um novo cabeçalho de referência para ligá-lo no novo nó
        No * n3 = criarNo("-1","-1",i,n2,l->anteriorAcima);

        l->anteriorAcima = n3;// Aponta o cabeçalho do nível da Skip List para o novo criado
        atualizacoes[i] = n3;// Atribui no vetor auxiliar o novo cabeçalho para que ele seja considerado na lógica acima
        // A lógica acima serve para quando o novo nível gerado é maior que o maior nível atual da Skip List, por isso que cria um
        // novo cabeçalho de referência para apontar para o novo nó criado
    }
    
    if(l->nivel < nivel)// Se o maior nível atual da Skip List for menor que o nível aleatório gerado
        l->nivel = nivel; // Atribui o nível aleatório gerado para o nível da Skip List

    return 1;
}

char * buscar(Lista * l, char * verbete){
    No * sentinela = l->anteriorAcima; // Cria um nó auxiliar e inicializa ele no primeiro cabeçalho da Skip List

    while(sentinela->nivel != 0){// Percorrerá os níveis da Skip List até o inicial
        // Percorrerá o nível atual da Skip List até encontrar o verbete ou até não existir mais verbetes
        while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
            sentinela = sentinela->prox;// Aponta o atual para o próximo
        
        sentinela = sentinela->abaixo;// Aponta o atual para o abaixo
    }

    // Percorrerá o nível inicial da Skip List  até encontrar o verbete ou até não existir mais verbetes
    while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
        sentinela = sentinela->prox;// Aponta o atual para o próximo
    
    // Verifica se encontrou o verbete e se ainda existiam verbetes para percorrer
    if(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) == 0)
        return sentinela->prox->valor->definicao; // Caso encontrou o verbete, retorna a sua definição
    else
        return "0";// Caso contrário, retorna "0"
}

int remover(Lista * l, char * verbete){

    No * sentinela = l->anteriorAcima;// Cria um ponteiro auxiliar e posiciona ele no primeiro cabeçalho da Skip List 
    No * atualizacoes[l->maiorNivel];// Cria um ponteiro de um vetor auxiliar para ajudar na remoção dos níveis

    while(sentinela->nivel != 0){// Percorrerá os níveis da Skip List até o inicial
        // Percorrerá o nível atual da Skip List até encontrar o verbete ou até não existir mais verbetes
        while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
            sentinela = sentinela->prox;// Aponta o atual para o próximo
        
        atualizacoes[sentinela->nivel] = sentinela;// Atribui no vetor auxiliar o ponteiro para o nó que sera atualizado
        sentinela = sentinela->abaixo;// Aponta o atual para o abaixo
    }
    // Percorrerá o nível inicial da Skip List  até encontrar o verbete ou até não existir mais verbetes
    while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
        sentinela = sentinela->prox;// Aponta o atual para o próximo
        
    if(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) != 0) // verifica se o verbete não existe
        return 0;

    atualizacoes[sentinela->nivel] = sentinela;// Atribui no vetor auxiliar o ponteiro para o nó que sera atualizado

    int nivelAtual = 0;

    while(nivelAtual <= l->nivel){// Percorrerá até o maior nível da Skip List

        // Verifica se ainda não chegou no fim do vetor auxiliar de atualizações e se o valor no vetor é igual ao verbete a ser removido
        if(atualizacoes[nivelAtual]->prox != NULL && strcmp(atualizacoes[nivelAtual]->prox->valor->verbete,verbete) == 0){
          // Caso sim, cria um nó para auxiliar na remoção e aponta o próximo nó do nó atual no vetor
          No * rem = atualizacoes[nivelAtual]->prox;
          atualizacoes[nivelAtual]->prox = rem->prox;// Aponta o nó atual no vetor para o próximo nó do que será removido
          free(rem);  // Libera memória do nó que será removido
        }

        nivelAtual++;
    }

    while(l->anteriorAcima->prox == NULL){ // Enquanto os cabeçalhos de referência apontarem para NULL 
        No * rem = l->anteriorAcima; // Cria um nó para auxiliar na remoção e aponta para o cabeçalho que será removido

        l->anteriorAcima = l->anteriorAcima->abaixo;// Aponta o nó do cabeçalho que será removido para o abaixo
        l->nivel--; // Diminui o valor do maior nível da Skip List

        free(rem); // Libera a memória do cabeçalho removido
    }

    return 1;// Se tudo deu certo, retorna "true"
}

void imprimir(Lista * l){// Impressão O(n) feita apenas para debugar
    No * sentinela = l->anteriorAcima; // Cria um ponteiro e aponta para o primeiro cabeçalho da Skip List
    No * aux = l->anteriorAcima;// Cria um ponteiro auxiliar e aponta para o primeiro cabeçalho da Skip List

    while(sentinela->nivel > 0){ // Percorrerá até o nível inicial
        while(sentinela != NULL){ // Percorrerá até o fim dos nós do nível
            printf("%s %s\n",sentinela->valor->verbete,sentinela->valor->definicao);// Exibe os verbetes e suas definições
            sentinela = sentinela->prox;// Aponta o atual para o próximo
        }

        sentinela = aux->abaixo; // Aponta o atual para o primeiro cabeçalho do nível abaixo
        aux = aux->abaixo;// Aponta o atual para o abaixo   
    }

    while(sentinela != NULL){// Percorrerá o nível inicial
        printf("%s %s\n",sentinela->valor->verbete,sentinela->valor->definicao);// Exibe os verbetes e suas definições
        sentinela = sentinela->prox;// Aponta o atual para o próximo
    }
}

int alterar(Lista * l, char * verbete, char * definicao){
    No * sentinela = l->anteriorAcima;// Cria um ponteiro e aponta para o primeiro cabeçalho da Skip List

    while(sentinela->nivel != 0){// Percorrerá até o nível inicial
        // Percorrerá até o fim do nível ou até encontrar o verbete
        while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
            sentinela = sentinela->prox; // Aponta o atual para o próximo

        // Verifica se não chegou ao fim do nível e se o verbete foi encontrado
        if(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) == 0)
             strcpy(sentinela->prox->valor->definicao,definicao);// Caso sim, altera sua definição

        sentinela = sentinela->abaixo;// Aponta o atual para o abaixo
    }
    // Percorrerá até o fim do nível inicial ou até encontrar o verbete
    while(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) < 0)
        sentinela = sentinela->prox;// Aponta o atual para o próximo

    // Verifica se não chegou ao fim do nível e se o verbete foi encontrado
    if(sentinela->prox != NULL && strcmp(sentinela->prox->valor->verbete,verbete) == 0){
        strcpy(sentinela->prox->valor->definicao,definicao);// Caso sim, altera sua definição
        return 1; // retorna "true"
    }else
        return 0; // Caso não, retorna "false"
}

int imprimirPorLetra(Lista * l, char letra){// Impressão O(log(n))
    No * sentinela = l->anteriorAcima;// Cria um ponteiro e aponta para o primeiro cabeçalho da Skip List
    
    int verifica = 0;// Variável criada para verificar se existe verbetes com a letra indicada

    while(sentinela->nivel != 0){// Percorrerá até o nível inicial
        // Percorrerá até o fim do nível ou até encontrar um verbete com a letra indicada no início
        while(sentinela->prox != NULL && sentinela->prox->valor->verbete[0] < letra){
            sentinela = sentinela->prox;// Aponta o atual para o próximo
        }
        sentinela = sentinela->abaixo;// Aponta o atual para o abaixo
    }

    // Percorrerá até o fim do nível inicial ou até encontrar um verbete com a letra indicada no início
    while(sentinela->prox != NULL && sentinela->prox->valor->verbete[0] < letra)
        sentinela = sentinela->prox;// Aponta o atual para o próximo

    // Percorrerá até o fim do nível inicial e enquanto o verbete encontrado começar com a letra indicada
    while(sentinela->prox != NULL && sentinela->prox->valor->verbete[0] == letra){
        printf("%s %s\n",sentinela->prox->valor->verbete,sentinela->prox->valor->definicao);// Exibe os verbetes e as definições
        sentinela = sentinela->prox;// Aponta o atual para o próximo
        verifica++;// Incrementa o verifica
    }

    if(verifica == 0) // Se o verifica for 0, quer dizer que não achou nenhum verbete que começa com a letra indicada
        return 0;// retorna "false"
    else
        return 1;// retorna "true"
}

void liberar(Lista * l){
    No * sentinela = l->anteriorAcima;// Cria um ponteiro e aponta para o primeiro cabeçalho da Skip List
    while(sentinela->nivel != 0){// Percorrerá até o nível inicial
        while(sentinela->prox != NULL){ // Percorrerá até o fim do nível
            No * rem = sentinela->prox;// Cria um ponteiro auxiliar e aponta ele para o próximo nó
            sentinela->prox = rem->prox;// Aponta anterior para o próximo
            free(rem->valor);// Limpa a palavra
            free(rem);// Limpa o nó
        }
        sentinela = sentinela->abaixo; // Aponta o atual para o abaixo
    }

    free(l);// limpa a Skip List
}