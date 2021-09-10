#include <stdio.h>
#include "fila.h"

int main(){
    fila_t * f;
    int i;
    elem *x;

    f = criar();

    for(i = 1; i <= 10; i++)
        inserir(f,i);

    remover(f,&x);

    inserir(f,231);

    for(i = f->inicio; i < f->total; i++)
        printf("%d ",f->itens[i]);
    for(i = 0; i < f->fim; i++)
        printf("%d ",f->itens[i]);

    destroy(f);

    return 0;
}
