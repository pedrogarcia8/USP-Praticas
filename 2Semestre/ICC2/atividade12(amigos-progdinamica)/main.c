#include <stdio.h>
#include <stdlib.h>

int main(){
    int  i, j, n, l, c, a, b, maior, lMaior, cMaior, **amigos;
    scanf("%d %d", &l, &c); // Lê a quantidade de linhas e colunas

    n = ((l-1) * c) + ((c - 1) * l); // Encontra o número total de ruas

    amigos = (int **) calloc(n, sizeof(int *)); // Aloca memória para a linha da matriz de amigos
    for(i = 0; i < n; i++)
       amigos[i] = (int *) calloc(l*c, sizeof(int)); // Aloca memória para a coluna da matriz de amigos

    for(i = 0; i < n; i++){
        scanf("%d %d %d", &a, &b, &maior); // Lê a quantidade de amigos nas ruas
        amigos[a][b] = maior; // Armazena na matriz de amigos
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < l*c; j++){
            if(maior < amigos[i][j])
                maior = amigos[i][j]; // Encontra a maior quantidade de amigos presentes em uma rua
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < l*c; j++){
            if(maior == amigos[i][j]){ // Encontra a rua que está a maior quantidade de amigos
                lMaior = i;
                cMaior = j;
                i = n;
                break;
            }
        }
    }

    a = maior; // "a" será a soma total de amigos no caminho
    i = lMaior;
    j = cMaior;

    while(i > 0 && j > 0){ // Percorrerá as ruas anteriores à rua com mais amigos
        while(i != j && j > 0)
            j--;

        while(amigos[i][j] == 0 && i > 0)
            i--;

        a += amigos[i][j];
    }

    i = lMaior;
    j = cMaior;

    while(i < n - 1 && j < (l*c) - 1){ // Percorrerá as ruas posteriores à rua com mais amigos
        while(i != j && i < n)
            i++;

        while(amigos[i][j] == 0 && j < (l*c))
            j++;

        a += amigos[i][j];
    }


    printf("%d\n",a); // Exibe a soma total de amigos


    return 0;
}
