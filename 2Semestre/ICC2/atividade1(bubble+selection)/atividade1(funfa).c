#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(int * v, int N){
    int i, sent = 0, fim = N, aux;

    while(fim > 1){
        sent = 0;
        for(i = 1; i < fim; i++){
            printf("C %d %d\n", (i-1), i);
            if(v[i] < v[i-1]){
                printf("T %d %d\n", i-1, i);
                aux = v[i-1];
                v[i-1] = v[i];
                v[i] = aux;
                sent = i;
            }
        }
        fim = sent;
    }
}

void selection(int * v, int N){
    int i, k, aux, menorPos, menorVal;
    for(k = 0; k < N; k++){
        menorPos = k;
        menorVal = v[k];
        for(i = k+1; i < N; i++){
            printf("C %d %d\n", menorPos, i);
            if(v[i] < menorVal){
                menorVal = v[i];
                menorPos = i;
            }
        }
        if(menorPos != k){
            printf("T %d %d\n", k, menorPos);
            aux = v[k];
            v[k] = v[menorPos];
            v[menorPos] = aux;
        }
    }
}

int main(){
    int N,* v, i;
    char opcao[10];

    scanf("%10s", opcao);
    scanf("%d", &N);


    v = (int *) calloc(N, sizeof(int));

    for(i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    if(strcmp(opcao, "bolha") == 0) {
        bubble(v, N);
    }
    else if(strcmp(opcao, "selecao") == 0) {
        selection(v, N);
    }

    for(i = 0; i < N; i++){
        printf("%d ",v[i]);
    }

    free(v);
    return 0;
}


