#include <stdio.h>
#include <stdlib.h>
#include "rubronegra.h"

rubronegra * criar(){
    rubronegra * a = (rubronegra *) malloc (sizeof(rubronegra)); // Aloca memória para a rubronegra
    a->raiz = NULL; // Inicializa a rubronegra
    return a; // Retorna ela
}

void finalizar(No * raiz){
    if(raiz != NULL){ // Verifica se ela já foi liberada
        finalizar(raiz->esq); // Se ela não foi liberada, percorrerá os nós da esquerda até ela ser liberada
        finalizar(raiz->dir); // Se ela não foi liberada, percorrerá os nós da direita até ela ser liberada
        free(raiz); // Libera a memória dos nós
    }
}

void imprimir(No * raiz){
    if(raiz != NULL){ // Verifica se o nó não está nulo
        printf("%d(", raiz->info); // Caso não for nulo, exibe os nós na forma da rubronegra
        imprimir(raiz->esq); // Percorre o lado esquerdo
        printf(",");
        imprimir(raiz->dir); // Percorre o lado direito
        printf(")");
    } else
        printf("null"); // Caso ele for nulo, exibe "null"
}

void pre_ordem(No * raiz){
    if(raiz != NULL){ // Verifica se o nó não está nulo
        printf("%d ", raiz->info); // Caso não for nulo, exibe os nós na forma pré ordem
        pre_ordem(raiz->esq); // Percorre o lado esquerdo
        pre_ordem(raiz->dir); // Percorre o lado direito
    }
}

void em_ordem(No * raiz){
    if(raiz != NULL){ // Verifica se o nó não está nulo
        em_ordem(raiz->esq); // Percorre o lado esquerdo
        printf("%d ", raiz->info); // Caso não for nulo, exibe os nós na forma em ordem
        em_ordem(raiz->dir); // Percorre o lado direito
    }
}

void pos_ordem(No * raiz){
    if(raiz != NULL){ // Verifica se o nó não está nulo
        pos_ordem(raiz->esq); // Percorre o lado esquerdo
        pos_ordem(raiz->dir); // Percorre o lado direito
        printf("%d ", raiz->info); // Caso não for nulo, exibe os nós na forma em pós ordem
    }
}

No * rotacao_EE(No * desb){ // Função para rotacionar o nó para o lado esquerdo 
    No * aux = desb->dir; // Pega o filho direito do nó que será rotacionado
    desb->dir = aux->esq; // Coloca o filho esquerdo de seu filho direito no filho direito de seu filho direito
    aux->esq = desb; // Rotaciona o pai para ser filho esquerdo de seu filho direito

    aux->cor = desb->cor; // Troca de cores
    desb->cor = VERMELHO; // Troca de cores

    return aux; // retorna o novo pai
}

No * rotacao_DD(No * desb){ // Função para rotacionar o nó para o lado direito 
    No * aux = desb->esq; // Pega o filho esquerdo do nó que será rotacionado
    desb->esq = aux->dir; // Coloca o filho direito de seu filho esquerdo no filho esquerdo de seu filho esquerdo
    aux->dir = desb; // Rotaciona o pai para ser filho direito de seu filho esquerdo

    aux->cor = desb->cor; // Troca de cores
    desb->cor = VERMELHO; // Troca de cores

    return aux; // retorna o novo pai
}

void inverteCores(No * desb){ // Função para inverter as cores das arestas um nó
    desb->cor = !desb->cor; // Inverte a cor
    desb->esq->cor = !desb->esq->cor; // Inverte a cor
    desb->dir->cor = !desb->dir->cor; // Inverte a cor
}


No * inserir_rubronegra(rubronegra * a, No * raiz, int x){ // Função recursiva de inserção
    if(raiz == NULL){ // Se o nó for nulo, quer dizer que encontrou o lugar da inserção
        raiz = (No *) malloc(sizeof(No)); // Aloca memória para o novo nó

        raiz->info = x; // Atribui o valor da chave
        raiz->cor = VERMELHO; // Atribui a cor vermelha para a aresta do novo nó

        raiz->esq = NULL; // Inicializa o seu filho esquerdo como nulo
        raiz->dir = NULL; // Inicializa o seu filho direito como nulo
    }else{ // Se o nó ainda não for nulo, quer dizer que não encontrou o lugar da inserção

        if(x < raiz->info) // Se a chave que será inserida for menor que a chave do nó atual
            raiz->esq = inserir_rubronegra(a, raiz->esq, x); // Procura no lado esquerdo
        else if(x > raiz->info) // Se a chave que será inserida for maior que a chave do nó atual
            raiz->dir = inserir_rubronegra(a, raiz->dir, x); // Procura no lado direito
        else // Se for igual, retorna que ela já existe
            printf("Elemento ja existente\n"); 
        
        if(raiz->dir != NULL && raiz->dir->cor == VERMELHO){ // Verifica se a aresta direita é vermelha
            raiz = rotacao_EE(raiz); // Caso sim, rotaciona para a esquerda para cumprir a regra 1
        }

        if(raiz->esq->esq != NULL && raiz->esq->cor == VERMELHO && raiz->esq->esq->cor == VERMELHO){ // Verifica se o nó tem duas arestas vermelhas opostas
            raiz = rotacao_DD(raiz); // Caso sim, rotaciona para a direita para cumprir a regra 2
        }

        if(raiz->esq != NULL && raiz->esq->cor == VERMELHO && raiz->dir != NULL && raiz->dir->cor == VERMELHO){ // Verifica se as duas arestas vermelhas na mesma direção
            inverteCores(raiz); // Caso sim, inverte as cores
        }

        // As três verificações acima vão automaticamene ajustar a rubronegra para cumprir a regra 3

    }
    
    return raiz; 
}

void inserir(rubronegra * a, int x){
    a->raiz = inserir_rubronegra(a, a->raiz, x); // Chama a função recursiva de inserção e coloca seu retorno na raiz da rubronegra
}

int min(No * raiz){
    if(raiz->esq != NULL){ // Enquanto o filho esquerdo não for nulo, quer dizer que ainda existe um nó com chave menor que a do atual
        min(raiz->esq);
    }else // Se o filho esquerdo for nulo, quer dizer que chegou no nó com a menor chave
        return raiz->info; 
}

int max(No * raiz){
    if(raiz->dir != NULL){ // Enquanto o filho direito não for nulo, quer dizer que ainda existe um nó com chave maior que a do atual
        max(raiz->dir);
    }else // Se o filho direito for nulo, quer dizer que chegou no nó com a maior chave
        return raiz->info;
}

No * busca_pai(No * raiz, int x) { // Função para buscar o pai de um nó
    
    if(raiz == NULL) // Se o nó for nulo, quer dizer que não encontrou o pai, então retorna nulo
        return NULL;
    
    if(raiz->esq != NULL && raiz->esq->info == x){ // Se a chave do filho esquerdo for igual a chave, que se quer encontrar o pai 
        return raiz; // Retorna o pai
    }
    if(raiz->dir != NULL && raiz->dir->info == x){ // Se a chave do filho direito for igual a chave, que se quer encontrar o pai 
        return raiz; // Retorna o pai
    }

    No * p = busca_pai(raiz->esq, x); // Busca o pai pelo lado esquerdo

    if(p == NULL) // Quando acabar o lado esquerdo, busca pelo lado direito
        p = busca_pai(raiz->dir, x);
    
    return p;
}

No * busca(No * raiz, int x){
    if(raiz == NULL) // Se o nó for nulo, quer dizer que não encontrou, então retorna nulo
        return NULL;
    else if(raiz->info == x) // Se encontrou, retorna ele
        return raiz;
    else if(x < raiz->info) // Se a chave a ser encontrada, for menor que a chave da raiz
        return busca(raiz->esq,x); // Buscará no lado esquerdo
    else
       return busca(raiz->dir,x);// Caso não, buscará no lado direito
}

void predecessor(No * raiz, int x){
    if(min(raiz) == x) // Verifica se a chave é a menor chave da rubronegra
        printf("erro\n"); // Caso sim, retorna erro porque ela não possui predecessor
    else{ // Caso não
        int maior;
        No * n = busca(raiz, x); // Busca o nó em que está a chave que se quer saber o predecessor

        if(n->esq != NULL) // Verifica se ela tem filho esquerdo
            maior = max(n->esq); // Caso sim, o predecessor será a maior chave a partir de seu filho esquerdo
        else{ // Caso não
            No * pai = busca_pai(raiz, x); // Busca o pai da chave que se quer saber o predecessor

            if(pai->info > n->info) // Se o a chave do pai for maior que a chave do nó que se quer saber o predecessor
                pai = busca_pai(raiz, pai->info); // Buscará o pai do pai da chave que se quer saber o predecessor

            if(pai->esq != NULL){ // Verifica se o pai possui filho esquerdo
                maior = max(pai->esq); // Caso sim, busca a maior chave a partir do filho esquerdo do pai

                if(maior < pai->info) // Se a maior chave a partir do filho esquerdo do pai, for maior que a chave do pai
                    maior = pai->info; // A chave do pai sera o predecessor

            }else // Caso não, o predecessor será o pai
                maior =  pai->info;
        }

        printf("%d\n", maior); // Exibe o sucessor
    }
}

void sucessor(No * raiz, int x){
    if(max(raiz) == x) // Verifica se a chave é a maior chave da rubronegra
        printf("erro\n"); // Caso sim, retorna erro porque ela não possui sucessor
    else{ // Caso não
        int menor;
        No * n = busca(raiz, x); // Busca o nó em que está a chave que se quer saber o sucessor

        if(n->dir != NULL) // Verifica se ela tem filho direito
            menor = min(n->dir); // Caso sim, o sucessor será a menor chave a partir de seu filho direito
        else{ // Caso não
            No * pai = busca_pai(raiz, x); // Busca o pai da chave que se quer saber o sucessor

            if(pai->info < n->info) // Se o a chave do pai for menor que a chave do nó que se quer saber o sucessor
                pai = busca_pai(raiz, pai->info); // Buscará o pai do pai da chave que se quer saber o sucessor

            if(pai->dir != NULL){ // Verifica se o pai possui filho direito
                menor = min(pai->dir); // Caso sim, busca a menor chave a partir do filho direito do pai

                if(menor > pai->info) // Se a menor chave a partir do filho direito do pai, for maior que a chave do pai
                    menor = pai->info; // A chave do pai sera o sucessor

            }else // Caso não, o sucessor será o pai
                menor =  pai->info;
        }

        printf("%d\n", menor); // Exibe o sucessor
    }
       
}