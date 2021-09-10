#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    Pilha * p;
    char c;
    int i,j,k,l;

    p = Create();

    do{
        scanf("%c",&c);
        if((c == '{') || (c == '}') || (c == '[') || (c == ']') || (c == '(') || (c == ')'))
            Push(p,c);
    }while(c != '\n');

    for(i = p->topo; i >= 0; i--){
        switch(p->caracteres[i]){
            case '}':
                for(j = i - 1; j >= 0; j--){
                    if(p->caracteres[j] == ']'){
                        for(k = j - 1; k >= 0; k--){
                            if(p->caracteres[k] != ')')
                                continue;

                            for(l = k - 1; l >= 0; l--){
                                if(p->caracteres[l] == '('){
                                    p->caracteres[k] = ' ';
                                    p->caracteres[l] = ' ';
                                    break;
                                }
                            }
                        }
                        for(k = j - 1; k >= 0; k--){
                            if(p->caracteres[k] == '['){
                                p->caracteres[j] = ' ';
                                p->caracteres[k] = ' ';
                                break;
                            }
                        }
                    }
                }
                for(j = i - 1; j >= 0; j--){
                    if(p->caracteres[j] == '}'){
                        p->caracteres[i] = ' ';
                        p->caracteres[j] = ' ';
                        break;
                    }
                }
            break;
            case ']':

            break;
            case ')':

            break;
        }
    }
    j = 0;
    for(i = p->topo; i >= 0; i--){
        if((p->caracteres[i] == '{') || (p->caracteres[i] == '[') || (p->caracteres[i] == '('))
            j++;
    }

    if(j == 0)
        printf("Balanceados");
    else
        printf("Desbalanceados");

    return 0;
}
