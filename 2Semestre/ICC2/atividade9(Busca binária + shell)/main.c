#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no {
    No * esq, * dir;
    int val;
};

int busca(int * num, int x, int sup, int inf);
void shell(int v[], int n);

int main(){
    int n, k, i, * num, num2;

    scanf("%d",&n);
    num = (int *) calloc(n, sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }

    shell(num,n);

    scanf("%d",&k);

    for(i = 0; i < k; i++){
        scanf("%d",&num2);
        if(busca(num, num2, n, 0) == 0)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}

int busca(int * num, int x, int sup, int inf){
    if(num == NULL)
        return 0;

    if(inf > sup)
        return 0;

    int meio = (sup + inf)/2;

    if(num[meio] > x)
        return busca(num, x, meio - 1, inf);
    else if(num[meio] < x)
        return busca(num, x, sup, meio + 1);
    else
        return 1;

    return 0;
}

void shell(int v[], int n) {
    int gap = 1;

    while(gap <= n)
        gap *= 2;

    gap = gap / 2 - 1;

    while(gap > 0) {
        int j;
        for (int k = 0; k < gap; k++){
            for (int i = k + gap; i < n; i += gap){
                int x = v[i];
                j = i - gap;
                while(j >= 0 && v[j] > x) {
                    v[j+gap] = v[j];
                    j-=gap;
                }
                v[j+gap] = x;
            }
        }
        gap /= 2;
    }

}


