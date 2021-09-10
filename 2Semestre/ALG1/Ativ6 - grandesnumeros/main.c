#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesnumeros.h"

int main(){
    int n, x, i, j, k;
    char opcao[4];
    char entrada[25];
    
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        Lista* l1 = criar();
        Lista* l2 = criar();
        scanf("%s ",opcao);
        
        for(j = 0; j < 2; j++){
            k = 0;
            x = 0;
            scanf(" %s",entrada);
            if(entrada[0] == '-'){
                if(j == 0)
                    inserir(l1,99);
                else
                    inserir(l2,99);
                k = 1;
            }
            while(entrada[k]){
                x = (entrada[k] - 48);
                if(j == 0)
                    inserir(l1,x);
                else
                    inserir(l2,x);
                k++;
                x = 0;
            }
        }

        if(strcmp(opcao,"sum") == 0){
            printf("Resultado %d: ",i+1);
            imprimir(somar(l1,l2));
        }
        if(strcmp(opcao,"big") == 0){
            printf("Resultado %d: %d\n",i+1,verificaMaior(l1,l2));
        }
        if(strcmp(opcao,"sml") == 0){
            printf("Resultado %d: %d\n",i+1,verificaMenor(l1,l2));
        }
        if(strcmp(opcao,"eql") == 0){
            printf("Resultado %d: %d\n",i+1,verificaIgual(l1,l2));
        }

        liberar(l1);
        liberar(l2);
    }
    
    return 0;
}
