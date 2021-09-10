#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h";
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    Conjunto * c;
    Conjunto * a;
    Conjunto * u;
    Conjunto * i;
    Conjunto * d;

    c = Criar_conjunto();
    a = Criar_conjunto();
    u = Criar_conjunto();
    i = Criar_conjunto();
    d = Criar_conjunto();

    Inserir(c,5);
    Inserir(c,15);
    Inserir(c,26);
    Inserir(c,50);
    Inserir(c,76);
    Inserir(c,44);

    Inserir(a,5);
    Inserir(a,15);
    Inserir(a,20);
    Inserir(a,54);
    Inserir(a,76);
    Inserir(a,44);

    if(Membro(c,7)){
        printf("Pertence ao conjunto!\n");
    }else{
        printf("Nao pertence ao conjunto!\n");
    }

    if(Membro(c,76)){
        printf("Pertence ao conjunto!\n");
    }else{
        printf("Nao pertence ao conjunto!\n");
    }

    Remover(c, 76);

    if(Membro(c,76)){
        printf("Pertence ao conjunto!\n");
    }else{
        printf("Nao pertence ao conjunto!\n");
    }

    printf("Min: %d\n",Min(c));
    printf("Max: %d\n",Max(c));
    Imprimir(c);
    printf("\n");
    Imprimir(a);
    printf("\n");
    if(Igual(c,a))
        printf("Igual\n");
    else
        printf("Diferente\n");

    u = Uniao(c,a,u);
    printf("a U c = ");
    Imprimir(u);

    i = Interseccao(c,a,i);
    printf("\na (^) c = ");
    Imprimir(i);

    d = Diferenca(c,a,d);
    printf("\na - c = ");
    Imprimir(d);

    printf("\n");
    c = Atribuir(c,a);
    Imprimir(c);

    printf("\nTamanho d = %d", Tamanho(d));

    Liberar(a);
    Liberar(c);
    Liberar(u);
    Liberar(i);
    Liberar(d);

    return 0;
}
