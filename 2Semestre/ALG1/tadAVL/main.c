#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
    avl * a = criar();
    inserir(a,5);
    inserir(a,3);
    inserir(a,8);
    inserir(a,2);
    inserir(a,7);
    inserir(a,10);
    inserir(a,15);
    imprimir(a->raiz);
    printf("\n");
    remover(a, 2);
    imprimir(a->raiz);
    printf("\n");
    finalizar(a->raiz);
    return 0;
}
