#include <stdio.h>
#include "fila.h"

int main(){
    fila_t * f;
    int i;
    elem *x;

    f = criar();

    for(i = 10; 1 <= i; i--)
        inserir(f,i);

    for(i = f->inicio; i < f->total; i++)
        if((f->itens[i] > f->itens[i + 1]) && (i < f->total)){
            printf("Nao esta ordenado de forma crescente");
            exit(0);
        }

    printf("Esta ordenada de forma crescente");

    destroy(f);

    return 0;
}

