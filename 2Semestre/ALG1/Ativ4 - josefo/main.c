#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    int T = 0, n = 0, k = 0, i = 0, j = 0, h = 0;
    Lista * l;

    scanf("%d",&T);
    for(i = 0; i < T; i++){
        scanf("%d",&n);
        scanf("%d",&k);
        l = criar();
        for(j = 1; j <= n; j++){
           inserir(l,j);
        }
        j = josefo(l,k);
        printf("Caso %d: %d\n",i+1,j);
    }
    return 0;
}
