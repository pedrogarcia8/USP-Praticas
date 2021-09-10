#include <stdio.h>
#include <stdlib.h>
#include "treap.h"

treap * criar(){
    treap * a = (treap *) malloc (sizeof(treap)); // Aloca memória para a treap
    a->raiz = NULL; // Inicializa a treap
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
        printf("%d(", raiz->info); // Caso não for nulo, exibe os nós na forma da treap
        imprimir(raiz->esq); // Percorre o lado esquerdo
        printf(",");
        imprimir(raiz->dir); // Percorre o lado direito
        printf(")");
    } else
        printf("null"); // Caso ele for nulo, exibe "null"
}

void pre_ordem(No * raiz){
    if(raiz != NULL){ // Verifica se o nó não está nulo
        printf("(%d, %d) ", raiz->info, raiz->p); // Caso não for nulo, exibe os nós na forma pré ordem
        pre_ordem(raiz->esq); // Percorre o lado esquerdo
        pre_ordem(raiz->dir); // Percorre o lado direito
    }
}

void em_ordem(No * raiz){
    if(raiz != NULL){ // Verifica se o nó não está nulo
        em_ordem(raiz->esq); // Percorre o lado esquerdo
        printf("(%d, %d) ", raiz->info, raiz->p); // Caso não for nulo, exibe os nós na forma em ordem
        em_ordem(raiz->dir); // Percorre o lado direito
    }
}

void pos_ordem(No * raiz){
    if(raiz != NULL){ // Verifica se o nó não está nulo
        pos_ordem(raiz->esq); // Percorre o lado esquerdo
        pos_ordem(raiz->dir); // Percorre o lado direito
        printf("(%d, %d) ", raiz->info, raiz->p); // Caso não for nulo, exibe os nós na forma em pós ordem
    }
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

int altura(No * raiz){
    if(raiz == NULL) // Se a treap for nula, a altura dela é 0
        return 0;

    int alt_esq = 1 + altura(raiz->esq); // Contará a altura do lado esquerdo
    int alt_dir = 1 + altura(raiz->dir); // Contará a altura do lado direito

    if(alt_esq > alt_dir) // Se a altura do lado esquerdo for maior que a do direito
        return alt_esq; // Então a altura da treap é igual a do lado esquerdo dela
    else
        return alt_dir; // Senão a altura da treap é igual a do lado direito dela
}

void largura(No * raiz, int nivel){
    if(raiz != NULL){ // Verifica se o nó não é nulo
        if(nivel == 0) // Se o nível for 0, quer dizer que chegou no nível que será impresso
            printf("(%d, %d) ", raiz->info, raiz->p);  // Imprime o nível 
        else{
            largura(raiz->esq, nivel - 1); // Percorre o lado esquerdo, até chegar no nível que será impresso
            largura(raiz->dir, nivel - 1); // Percorre o lado direito, até chegar no nível que será impresso
        }
    }
}

No * rotacao_EE(No * desb){ // Função para rotacionar o nó para o lado esquerdo 
    No * aux = desb->dir; // Pega o filho direito do nó que será rotacionado
    desb->dir = aux->esq; // Coloca o filho esquerdo de seu filho direito no filho direito de seu filho direito
    aux->esq = desb; // Rotaciona o pai para ser filho esquerdo de seu filho direito
    return aux; // retorna o novo pai
}

No * rotacao_DD(No * desb){ // Função para rotacionar o nó para o lado direito 
    No * aux = desb->esq; // Pega o filho esquerdo do nó que será rotacionado
    desb->esq = aux->dir; // Coloca o filho direito de seu filho esquerdo no filho esquerdo de seu filho esquerdo
    aux->dir = desb; // Rotaciona o pai para ser filho direito de seu filho esquerdo
    return aux; // retorna o novo pai
}

No * inserir_treap(treap * a, No * raiz, int x, int p){ // Função recursiva de inserção
    if(raiz == NULL){ // Se o nó for nulo, quer dizer que encontrou o lugar da inserção
        raiz = (No *) malloc(sizeof(No)); // Aloca memória para o novo nó

        raiz->info = x; // Atribui o valor da chave
        raiz->p = p;// Atribui o valor da prioridade

        raiz->esq = NULL; // Inicializa o seu filho esquerdo como nulo
        raiz->dir = NULL; // Inicializa o seu filho direito como nulo

    }else{ // Se o nó ainda não for nulo, quer dizer que não encontrou o lugar da inserção
        if(x < raiz->info) // Se a chave que será inserida for menor que a chave do nó atual
            raiz->esq = inserir_treap(a, raiz->esq, x, p); // Procura no lado esquerdo
        else if(x > raiz->info) // Se a chave que será inserida for maior que a chave do nó atual
            raiz->dir = inserir_treap(a, raiz->dir, x, p); // Procura no lado direito
        else // Se for igual, retorna que ela já existe
            printf("Elemento ja existente\n"); 
        
    }
    
    No * pai = busca_pai(a->raiz, x); // Busca o pai da chave que foi inserida
    if(pai != NULL){ // Se o pai não for nulo
        No * novo = busca(a->raiz, x); // busca o nó que a chave foi inserida
        if(novo->p > pai->p){ // Se a prioridade do pai for menor que a do seu filho, terá que rotacionar esse pedaço da treap para arrumar o balanceamento
            if(novo->info > pai->info) // Se a chave do novo nó for menor que a do seu pai
                pai = rotacao_EE(pai); // Rotaciona para a esquerda
            else
                pai = rotacao_DD(pai); // Caso contrário, rotaciona para a direita
            
            raiz = pai; // Atribui o novo pai para o nó atual
        }
    }
    
    return raiz; 
}

void inserir(treap * a, int x, int p){
    a->raiz = inserir_treap(a, a->raiz, x, p); // Chama a função recursiva de inserção e coloca seu retorno na raiz da treap
}

No * remover_treap(No * raiz, int x){ // Função recursiva de remoção
    if(raiz != NULL){ // Se o nó não for nulo, que dizer que ele ainda existe
        if(x < raiz->info) // Se a chave que será removida for menor que a chave do nó atual
            raiz->esq = remover_treap(raiz->esq, x); // Procura no lado esquerdo
        else if(x > raiz->info) // Se a chave que será removida for maior que a chave do nó atual
            raiz->dir = remover_treap(raiz->dir, x); // Procura no lado direito
        else{ // Se for igual, removerá ela
            if(raiz->esq == NULL && raiz->dir == NULL){ // Se os dois filhos forem nulo, quer dizer que é uma folha, então libera a memória dela
                No * rem = raiz; 
                raiz = NULL; // Limpa a folha
                free(rem); // Libera a memória da folha

            }else if(raiz->esq != NULL && raiz->dir == NULL){ // Se somente o filho direito for nulo, quer dizer que é uma semi folha
                No * rem = raiz; // Pega o valor da semi folha
                raiz = raiz->esq; // Atribui o valor da folha esquerda na semi folha
                free(rem); // Limpa a semi folha

            }else if(raiz->esq == NULL && raiz->dir != NULL){ // Se somente o filho esquerdo for nulo, quer dizer que é uma semi folha
                No * rem = raiz; // Pega o valor da semi folha
                raiz = raiz->dir; // Atribui o valor da folha direita na semi folha
                free(rem); // Limpa a semi folha

            }else{ // Se os dois filhos forem diferentes de nulo, rotacionará o pai para a esquerda até ele ser uma semi folha ou uma folha
                raiz = rotacao_EE(raiz); // Rotaciona o pai para a esquerda
                raiz->esq = remover_treap(raiz->esq, x); // Chama a função recursiva de remoção novamente passando o nó em seu novo lugar
            }  
        }
        
    }else{ // Se percorrer a treap e o último nó for nulo, quer dizer que ele não existe
        printf("Chave nao localizada\n");
    }

    return raiz;
}

void remover(treap * a, int x){
    a->raiz = remover_treap(a->raiz, x); // Chama a função recursiva de remoção e coloca seu retorno na raiz da treap
}
