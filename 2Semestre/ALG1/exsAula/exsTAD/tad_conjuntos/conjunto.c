#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h";

Conjunto * Criar_conjunto(){
    Conjunto  * c = (Conjunto *) calloc(1,sizeof(Conjunto));
    if( c != NULL)
        return c;
}

void Inserir(Conjunto * c, int num){
    c->con[num] = 1;
    c->tam++;
}

Conjunto * Membro(Conjunto * c, int num){
    return c->con[num];
}

void Remover(Conjunto * c, int num){
    c->con[num] = 0;
    c->tam--;
}

void Imprimir(Conjunto * c){
    int i;
    for(i = 0; i < N; i++)
        if(c->con[i])
            printf("%d ",i);
}

Conjunto * Min(Conjunto * c){
    int i;
    for(i = 0; i < N; i++)
        if(c->con[i])
            return i;
}

Conjunto * Max(Conjunto * c){
    int i;
    for(i = N-1; i >= 0; i--)
        if(c->con[i])
            return i;
}

void Liberar(Conjunto * c){
    free(c);
}

Conjunto * Igual(Conjunto * c, Conjunto * a){
    int i;
    for(i = 0; i < N; i++){
        if(c->con[i] != a->con[i])
            return 0;
    }
    return 1;
}

Conjunto * Uniao(Conjunto * c, Conjunto * a,Conjunto * u){
    int i;
    for(i = 0; i < N; i++){
        if((c->con[i] != a->con[i]) || (c->con[i] == 1)  || (a->con[i] == 1)){
            u->con[i] = 1;
            u->tam++;
        }
    }
    return u;
}

Conjunto * Interseccao(Conjunto * c, Conjunto * a,Conjunto * i){
    int j;
    for(j = 0; j < N; j++){
        if((c->con[j] == 1)  && (a->con[j] == 1)){
            i->con[j] = 1;
            i->tam++;
        }
    }
    return i;
}

Conjunto * Diferenca(Conjunto * c, Conjunto * a,Conjunto * d){
    int i;
    for(i = 0; i < N; i++){
        if((c->con[i] != a->con[i]) && (a->con[i] == 0)){
            d->con[i] = 1;
            d->tam++;
        }
    }
    return d;
}

Conjunto * Atribuir(Conjunto * c, Conjunto * a){
    int i;
    c->tam = 0;
    for(i = 0; i < N; i++){
        c->con[i] = a->con[i];
        if(a->con[i])
            c->tam++;
    }
    return c;
}

int Tamanho(Conjunto * c){
    return c->tam;
}
