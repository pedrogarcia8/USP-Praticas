#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;

struct no {
  char read[1001];
  No *ant, *prox;
};

typedef struct lista{
  No * ini, * fim;
  int tam;
} Lista;

typedef struct overleap{
    char read[1001];
    char aux[1001];
    char aux2[1001];
    int overleap;
} dna;

Lista * criar();
void liberar(Lista * l);
void imprimir(Lista * l);
void inserir(Lista * l, char * x, int flag);
void remover(Lista * l, char * x);

int main(){
    int n, i, j, k, m = 0, overleap = 0;
    char read[1001];
    Lista * l = criar();
    dna * d;
    No * aux, * aux2;

    scanf("%d", &n);

    d = (dna *) malloc((n*(n-1)) * sizeof(dna));

    for(i = 0; i < n; i++){
        scanf(" %s", read);
        inserir(l, read, 0);
    }

    n-=1;
    while(n > 0){
        aux = l->ini;

        while(aux != NULL){
            if(aux == l->ini)
                aux2 = aux->prox;
            else
                aux2 = l->ini;
            while(aux2 != NULL){
                overleap = 0;

                if(strstr(aux->read,aux2->read) != NULL){
                    overleap = strlen(aux2->read);
                    strcpy(d[m].read,aux->read);
                }else{
                    for(i = 0; aux->read[i]; i++){
                        if(aux2->read[0] == aux->read[i]){
                            k = i + 1;
                            overleap = 1;
                            for(j = 1; aux2->read[j]; j++){
                                if(aux2->read[j] == aux->read[k]){
                                    k++;
                                    overleap++;
                                }else if(aux->read[k]){
                                    overleap = 0;
                                    break;
                                }else{
                                    i = k;
                                    break;
                                }
                            }
                        }
                    }

                    if(overleap == 0){
                        strcpy(d[m].read,aux->read);
                        strcat(d[m].read,aux2->read);
                    }else{
                        memset(read, '\0', 1001);
                        for(i = overleap; aux2->read[i]; i++)
                            read[i-overleap] = aux2->read[i];

                        strcpy(d[m].read,aux->read);
                        strcat(d[m].read,read);
                    }
                }

                strcpy(d[m].aux,aux->read);
                strcpy(d[m].aux2,aux2->read);
                d[m].overleap = overleap;
                m++;

                if(aux2->prox != aux)
                    aux2 = aux2->prox;
                else
                    aux2 = aux2->prox->prox;
            }

            aux = aux->prox;
        }

        overleap = 0;
        for(i = 0; i < m; i++){
            if(overleap < d[i].overleap)
                overleap = d[i].overleap;
        }


        for(i = 0; i < m; i++){
            if(overleap == d[i].overleap){
                remover(l, d[i].aux);
                remover(l, d[i].aux2);
                inserir(l, d[i].read, 1);
                break;
            }
        }


        memset(read,'\0',1001);
        overleap = 0;
        for(i = 0; i < m; i++){
            memset(d[i].aux, '\0', 1001);
            memset(d[i].aux2, '\0', 1001);
            memset(d[i].read, '\0', 1001);
            d[i].overleap = 0;
        }
        m = 0;
        n--;
    }

    printf("%s\n",l->ini->read);

    liberar(l);
    free(d);
    return 0;
}

Lista * criar(){
    Lista * l;
    l = (Lista *) malloc(sizeof(Lista));
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

void liberar(Lista * l){
    if(l != NULL){
        No * aux = l->ini;
        while(aux != NULL){
            l->ini = l->ini->prox;
            free(aux);
            aux = l->ini;
        }
        free(l);
    }
}

void inserir(Lista * l, char * x, int flag){
    No * n = (No *) malloc(sizeof(No));
    strcpy(n->read, x);
    l->tam++;
    if(flag == 0){
        No * ant;
        n->prox = NULL;
        if(l->ini == NULL){
            l->ini = n;
            l->fim = n;
        }else{
            ant = l->fim;
            ant->prox = n;
            l->fim = n;
        }
    }else if(flag == 1){
        n->prox = l->ini;
        l->ini = n;
    }


}

void remover(Lista * l, char * x){
    No * n = l->ini;
    No * p = l->ini;
    No * ant;
    while(strcmp(n->read, x) != 0){
        ant = n;
        n = n->prox;
    }
    while(p != NULL){
        if(p->ant != NULL)
        if(p->ant == n){
            p->ant = NULL;
        }
        p = p->prox;
    }
    if(n == l->ini){
        l->ini = l->ini->prox;
        free(n);
    }else if(n == l->fim){
        l->fim = ant;
        free(n);
    }else{
        ant->prox = n->prox;
        free(n);
    }
    l->fim->prox = NULL;
    l->tam--;
}



