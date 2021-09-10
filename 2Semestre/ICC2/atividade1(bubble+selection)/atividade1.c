#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * bubble(int * v, int N);
int * selection(int * v, int N);

int main(){
    int N,* v, i = 0;
    char opcao[8];

    scanf("%s",opcao);
    scanf("%d",&N);

    if(N < 2)
        exit(0);

    v = (int *) calloc(N, sizeof(int));

    for(i = 0; i < N; i++){
        scanf("%d",&v[i]);
    }

    if(!strcasecmp(opcao,"bolha"))
        v = bubble(v,N);
    else if(!strcasecmp(opcao,"selecao"))
        v = selection(v,N);

    for(i = 0; i < N; i++){
        printf("%d ",v[i]);
    }

    free(v);

    return 0;
}

int * bubble(int * v, int N){
    int sentinela = 0, aux = 0,i = 0, j = 0, lim = N * N * N;

    for(i = 0; i < lim; i++){
        sentinela = 0;
        for(j = 0; j < N; j++){
            if(j+1 < N){
                printf("C %d %d\n",j,j+1);

                if(v[j] > v[j+1]){
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                    sentinela = 1;

                    printf("T %d %d\n",j,j+1);
                }
            }
        }
        if(!sentinela) break;

        lim--;
    }

    return v;
}

int * selection(int * v, int N){
    int i, j, k = 0, aux = 0, aux_pos = 0;

    for(i = 0 ;i < N; i++){
        k = i;
        aux = v[i];

        for(j = i+1; j < N; j++){
            printf("C %d %d\n", k, j);

            if(v[j]<aux){
                aux = v[j];
                aux_pos = j;
                k = j;
            }
        }
        if(aux != v[i]){
            printf("T %d %d\n", i, aux_pos);
            v[aux_pos] = v[i];
            v[i] = aux;
        }
    }

    return v;
}


