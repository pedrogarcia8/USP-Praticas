#include <stdio.h>
#include <stdlib.h>

void insercaoHash(int * v, int num, int M);
void remocaoHash(int * v, int num, int M);
int buscaHash(int * v, int num, int M);

int main(){
    int M, N, * v, i, num;

    scanf("%d", &M);
    v = (int *) malloc(M * sizeof(int));
    scanf("%d", &N);

    for(i = 0; i < M; i++){
        v[i] = -1;
    }

    for(i = 0; i < N; i++){
        scanf("%d", &num);
        insercaoHash(v,num,M);
    }

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &num);
        remocaoHash(v,num,M);
    }

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &num);
        printf("%d ",buscaHash(v,num,M));
    }
    printf("\n");

    free(v);

    return 0;
}

void insercaoHash(int * v, int num, int M){
    int j, pos = 0;
    if(num >= 0){
        pos = num % M;

        if(v[pos] == -1)
            v[pos] = num;
        else{
            for(j = pos + 1; j < M; j++){
                if(v[j] == num)
                    break;

                if(v[j] == -1){
                    v[j] = num;
                    break;
                }
            }
        }
    }
}

void remocaoHash(int * v, int num, int M){
    int j, pos = 0;

    if(num >= 0){

        pos = num % M;

        if(v[pos] == num)
            v[pos] = -1;
        else{
            for(j = pos + 1; j < M; j++){
                if(v[j] == num){
                    v[j] = -1;
                    break;
                }
            }
        }
    }
}

int buscaHash(int * v, int num, int M){
    int j, pos = 0;

    if(num >= 0){

        pos = num % M;
        if(v[pos] == num)
            return pos;
        else{
            for(j = pos + 1; j < M; j++){
                if(v[j] == num){
                    return j;
                }
            }

            return -1;
        }
    }

    return -1;
}
