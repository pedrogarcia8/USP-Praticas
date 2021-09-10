#include <stdio.h>
#include <stdlib.h>
#include "cartas.h"

int main(){
    PilhaCartas * compra, * descarte, * morto;
    int N, carta, tam, cont = 0;

    scanf("%d",&N);

    if((N < 1) || (N > 100000))
        exit(0);

    compra   = Create(N);
    descarte = Create(N);
    morto    = Create(N);

    tam = N;

    while(N > 0){
        scanf("%d",&carta);
        Push(compra,carta);
        N--;
    }
   
    N = tam + 1;
    while(morto->topo != (tam - 1)){
        while(compra->topo != -1){
            N--;
            while(compra->topo != -1){
                if(compra->cartas[compra->topo] == N){
                    Push(morto,N);
                    Pop(compra);
                    break;
                }
                else
                    Push(descarte,compra->cartas[compra->topo]);   
                Pop(compra);
            } 
        }
        N = morto->cartas[morto->topo];
        if(compra->topo == -1) 
            cont++;

        while(descarte->topo >= 0){
            Push(compra,descarte->cartas[descarte->topo]);
            Pop(descarte);
        }
           
    }

    printf("%d\n", cont);

    Destroy(compra);
    Destroy(descarte);
    Destroy(morto);

    return 0;
}

        