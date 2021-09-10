#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto{
    float x, y;
} Ponto; // Estrutura dos pontos cartesianos (x,y)

void shell(Ponto v[], int n); // Algoritmo de ordenação

int main(){
    int n, i, meio = 0;
    float d1 = 0, d2 = 0, d1menor = 0, d2menor = 0;
    Ponto * p;

    scanf("%d",&n); // Lê o número de pontos
    p = (Ponto *) malloc(n * sizeof(Ponto)); // Aloca memória para a estrutura de pontos

    for(i = 0; i < n; i++)
        scanf("%f %f",&p[i].x,&p[i].y); // Lê os pontos

    shell(p,n); // Ordena a estrutura de pontos

    meio = n/2; // Encontra o meio da estrutura de pontos
    i = 0;
    d1menor = sqrt(pow((p[0].x - p[1].x),2) + pow((p[0].y - p[1].y),2)); // calcula a distancia euclidiana entre o primeiro e o segundo ponto
    while(i <= meio){
        d1 = sqrt(pow((p[i].x - p[i+1].x),2) + pow((p[i].y - p[i+1].y),2));// calcula a distancia euclidiana dos demais pontos até chegar no meio
        if(d1menor > d1)
            d1menor = d1; // Pega a menor distancia euclidiana na primeira metade
        i++;
    }

    i = meio;
    d2menor = sqrt(pow((p[i].x - p[i+1].x),2) + pow((p[i].y - p[i+1].y),2)); // calcula a distancia euclidiana entre o primeiro e o segundo ponto da segunda metade
    while(i+1 < n){
        d2 = sqrt(pow((p[i].x - p[i+1].x),2) + pow((p[i].y - p[i+1].y),2));// calcula a distancia euclidiana dos demais pontos até chegar no final
        if(d2menor > d2)
            d2menor = d2;// Pega a menor distancia euclidiana na segunda metade
        i++;
    }

    if(d1menor > d2menor)
        d1menor = d2menor; // Pega a menor distancia euclidiana da estrutura inteira

    i = meio;
    while(i >= 0){
        if(p[i].x >= p[meio].x - d1menor) // Pega a posição do primeiro ponto de meio - distancia menor
            i--;
        else
            break;
    }

    while(p[i].x <= (p[meio].x + d1menor)){
        d1 = sqrt(pow((p[i].x - p[i+1].x),2) + pow((p[i].y - p[i+1].y),2));// calcula a distancia euclidiana dos pontos até chegar no meio + distancia menor
        if(d1menor > d1)
            d1menor = d1;// Pega a menor distancia euclidiana na faixa divisória

        i++;
    }

    printf("%0.6f\n",d1menor); // Exibe a menor distancia euclidiana

    free(p); // Limpa memória da estrutura de pontos

    return 0;
}

void shell(Ponto v[], int n) { // Algoritmo de ordenação
    int gap = 1;

    while(gap <= n)
        gap *= 2;

    gap = gap / 2 - 1;

    while(gap > 0) {
        int j;
        for (int k = 0; k < gap; k++){
            for (int i = k + gap; i < n; i += gap){
                float x = v[i].x;
                float y = v[i].y;
                j = i - gap;
                while(j >= 0 && v[j].x > x) {
                    v[j+gap].x = v[j].x;
                    v[j+gap].y = v[j].y;
                    j-=gap;
                }
                v[j+gap].x = x;
                v[j+gap].y = y;
            }
        }
        gap /= 2;
    }

}

