#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    char ent;
    int n, j, tempo = 0;
    Lista * l = criar();
    while(1){
        scanf("%c",&ent);
        if(ent == 'f')
            break;
        scanf("%d %d",&n,&j);

        if(ent == 'i'){
            inserir(l,n,j,tempo);
            tempo++;
        }else if(ent == 'r'){
            remover(l,n);
            tempo++;
        }

    }
    imprimir(l);
    liberar(l);
    return 0;
}
