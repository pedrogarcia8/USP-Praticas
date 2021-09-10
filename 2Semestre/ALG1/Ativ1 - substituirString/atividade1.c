#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(){
    Texto * t;
    int cont = 0, i = 0;
    char * str, str2[101];


    while(scanf(" %[^\n]s", str2) != EOF){
        t = Create();
        strcopy(t->original,str2);
        scanf(" %[^\n]s",t->erro);
        scanf(" %[^\n]s",t->correcao);
        str = substituir(t->original,t->erro,t->correcao);
        printf("%s\n",str);
        Destroy(t);
    }



    return 0;
}
