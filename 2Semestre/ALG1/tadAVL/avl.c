#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "avl.h"

avl * criar(){
    avl * a = (avl *) malloc (sizeof(avl));
    a->raiz = NULL;
    return a;
}

int esta_vazia(avl * a){
    assert(a != NULL);

    if(a->raiz == NULL)
        return 1;

    return 0;
}

void finalizar(No * raiz){
    if(raiz != NULL){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}

void imprimir(No * raiz){
    if(raiz != NULL){
        printf("%d(", raiz->info);
        imprimir(raiz->esq);
        printf(",");
        imprimir(raiz->dir);
        printf(")");
    } else
        printf("null");
}

int altura(No * raiz){
    if(raiz == NULL)
        return 0;

    int alt_esq = 1 + altura(raiz->esq);
    int alt_dir = 1 + altura(raiz->dir);

    if(alt_esq > alt_dir)
        return alt_esq;
    else
        return alt_dir;
}

void pre_ordem(No * raiz){
    if(raiz != NULL){
        printf("%d ",raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void em_ordem(No * raiz){
    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf("%d ",raiz->info);
        em_ordem(raiz->dir);
    }
}

void pos_ordem(No * raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ",raiz->info);
    }
}

No * busca(No * raiz, int x){
    if(raiz == NULL)
        return NULL;
    else if(raiz->info == x)
        return raiz;
    else if(x < raiz->info)
        return busca(raiz->esq,x);
    else
       return busca(raiz->dir,x);
}

No * rotacao_EE(No * desb){
    No * aux = desb->dir;
    desb->dir = aux->esq;
    aux->esq = desb;
    return aux;
}

No * rotacao_DD(No * desb){
    No * aux = desb->esq;
    desb->esq = aux->dir;
    aux->dir = desb;
    return aux;
}

No * rotacao_ED(No * desb){
    desb->esq = rotacao_EE(desb->esq);
    desb = rotacao_DD(desb);
    return desb;
}

No * rotacao_DE(No * desb){
    desb->dir = rotacao_DD(desb->dir);
    desb = rotacao_EE(desb);
    return desb;
}

No * insere_avl(No * raiz, int x, int * flag){
    if(raiz != NULL){
        if(x < raiz->info){
            raiz->esq = insere_avl(raiz->esq, x, flag);
            if(*flag == 1){
                switch(raiz->fb){
                    case -1:
                        raiz->fb = 0;
                        *flag = 0;
                        break;
                    case 0:
                        raiz->fb = 1;
                        *flag = 1;
                        break;
                    case 1:
                        if(raiz->esq->fb == 1){
                            raiz = rotacao_DD(raiz);
                            raiz->dir->fb = 0;
                            raiz->fb = 0;
                        }else{
                            raiz = rotacao_ED(raiz);
                            if(raiz->fb == -1){
                                raiz->esq->fb = 1;
                                raiz->dir->fb = 0;
                                raiz->fb = 0;
                            }else if(raiz->fb == 1){
                                raiz->esq->fb = 0;
                                raiz->dir->fb = -1;
                                raiz->fb = 0;
                            }else{
                                raiz->esq->fb = 0;
                                raiz->dir->fb = 0;
                                raiz->fb = 0;
                            }
                        }
                        *flag = 0;
                        break;
                }
            }
        }else if(x > raiz->info){
            raiz->dir = insere_avl(raiz->dir, x, flag);
            if(*flag == 1){
                switch(raiz->fb){
                    case 1:
                        raiz->fb = 0;
                        *flag = 0;
                        break;
                    case 0:
                        raiz->fb = -1;
                        *flag = 1;
                        break;
                    case -1:
                        if(raiz->dir->fb == -1){
                            raiz = rotacao_EE(raiz);
                            raiz->esq->fb = 0;
                            raiz->fb = 0;
                        }else{
                            raiz = rotacao_DE(raiz);
                            if(raiz->fb == -1){
                                raiz->esq->fb = 1;
                                raiz->dir->fb = 0;
                                raiz->fb = 0;
                            }else if(raiz->fb == 1){
                                raiz->esq->fb = 0;
                                raiz->dir->fb = -1;
                                raiz->fb = 0;
                            }else{
                                raiz->esq->fb = 0;
                                raiz->dir->fb = 0;
                                raiz->fb = 0;
                            }
                        }
                        *flag = 0;
                        break;
                }
            }
        }else{
            printf("Elemento ja existente\n");
        }
    }else{
        raiz = (No *) malloc(sizeof(No));
        raiz->info = x;
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->fb = 0;
        *flag = 1;
    }

    return raiz;
}

void inserir(avl * a, int x){
    int flag = 0;
    a->raiz = insere_avl(a->raiz, x, &flag);
}

No * balanceamento_esquerda(No * p, int * h){

    switch(p->fb){
        case 1: // altura alterada
            p->fb = 0;
            break;
        case 0: // altura não alterada
            p->fb = -1;
            *h = 0;
            break;
        case -1: // altura alterada e desbalanceou
            if(p->dir->fb <= 0){
                p = rotacao_EE(p);
                if(p->fb == 0){
                    p->esq->fb = -1;
                    p->fb = 1;
                    *h = 0; // altura nao muda apos a rotacao
                }else{
                    p->esq->fb = 0;
                    p->fb = 0;
                }
            }else{
                p = rotacao_DE(p);
                if(p->fb == 1){
                    p->esq->fb = 0;
                    p->dir->fb = -1;
                }else if(p->fb == -1){
                    p->esq->fb = 1;
                    p->dir->fb = 0;
                }else{
                    p->esq->fb = 0;
                    p->dir->fb = 0;
                }
                p->fb = 0;
            }
    }
    return p;
}

No * balanceamento_direita(No * p, int * h){
        switch(p->fb){
        case -1: // altura alterada
            p->fb = 0;
            break;
        case 0: // altura não alterada
            p->fb = 1;
            *h = 0;
            break;
        case 1: // altura alterada e desbalanceou
            if(p->esq->fb >= 0){
                p = rotacao_DD(p);
                if(p->fb == 0){
                    p->dir->fb = 1;
                    p->fb = -1;
                    *h = 0; // altura nao muda apos a rotacao
                }else{
                    p->dir->fb = 0;
                    p->fb = 0;
                }
            }else{
                p = rotacao_ED(p);
                if(p->fb == 1){
                    p->esq->fb = 0;
                    p->dir->fb = -1;
                }else if(p->fb == -1){
                    p->esq->fb = 1;
                    p->dir->fb = 0;
                }else{
                    p->esq->fb = 0;
                    p->dir->fb = 0;
                }
                p->fb = 0;
            }
    }
    return p;
}

No * busca_remove(No * p, No * chave, int * h){
    No * aux;
    if(p->dir != NULL){
        p->dir = busca_remove(p->dir, chave, h);
        if(*h == 1){
            p = balanceamento_direita(p, h);
        }
    }else{
        chave->info = p->info;
        aux = p;
        p = p->esq;
        free(aux);
        *h = 1;
    }

    return p;
}

No * remove_avl(No * raiz, int x, int * h){
    No * aux;
    if(raiz == NULL){
        printf("Chave nao encontrada\n");
        *h = 0;
    }else if(x < raiz->info){
        raiz->esq = remove_avl(raiz->esq, x, h);
        if(*h == 1){
            raiz = balanceamento_esquerda(raiz, h);
        }
    }else if(x > raiz->info){
        raiz->dir = remove_avl(raiz->dir, x, h);
        if(*h == 1){
            raiz = balanceamento_direita(raiz, h);
        }
    }else{
        if(raiz->dir == NULL){
            aux = raiz;
            raiz = raiz->esq;
            free(aux);
            *h = 1;
        }else if(raiz->esq == NULL){
            aux = raiz;
            raiz = raiz->dir;
            free(aux);
            *h = 1;
        }else{
            raiz->esq = busca_remove(raiz->esq, raiz, h);
            if(*h == 1){
                raiz = balanceamento_esquerda(raiz, h);
            }
        }
    }

    return raiz;
}

void remover(avl * a, int x){
    int flag = 0;
    a->raiz = remove_avl(a->raiz, x, &flag);
}
