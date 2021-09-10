#include <stdio.h>
#include <stdlib.h>

int shell(int v[], int n);
void quick(int v[], int c, int f, int soma);
int somaQuick = 0;

int main(){
    int n, * v, i, * subv, j, s = 0, q = 0;

    scanf("%d", &n);

    v = (int *) calloc(n, sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            subv = (int *) calloc(j + 1, sizeof(int));
            subv[j] = v[j];
        }
        s = shell(subv,j);
        quick(subv,0,i);
        q = somaQuick;
        somaQuick = 0;
        if(s == q)
            printf("-");
        else if (s > q)
            printf(" Q");
        else if (s < q)
            printf(" S");
    }
    printf("\n");
    return 0;
}

void quick(int v[], int c, int f, int soma){
    if(c >= f){
        return;
    }

    int m = (c + f)/2;
    int pivo = v[m];
    int i = c;
    int j = f;
    somaQuick += 2;
    while(1){
        while(v[i] < pivo){
            i++;
            somaQuick += 2;
        }
        while(v[j] > pivo){
            j--;
            somaQuick += 2;
        }
        if(j <= i)
            break;
        somaQuick += 3;
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        i++;
        j--;
    }

    quick(v, c, j);
    quick(v, j+1, f);
}


int shell(int v[], int n) {
    int soma = 0;
    int gap = 1;

    while(gap <= n)
        gap *= 2;

    gap = gap / 2 - 1;

    while(gap > 0) {
        int i;
        int j;

        for (int k = 0; k < gap; k++){
            for (int i = k + gap; i < n; i += gap){
                soma++;
                int x = v[i];

                j = i - gap;

                while(j >= 0 && v[j] > x) {
                    soma += 2;
                    v[j+gap] = v[j];
                    j-=gap;

                }
                if(j >= 0 && v[j] <= x)
                    soma++;


                soma++;
                v[j+gap] = x;
            }
        }

        gap /= 2;

    }

    return soma;

}
