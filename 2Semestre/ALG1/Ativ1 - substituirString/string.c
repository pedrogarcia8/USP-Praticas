#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"

Texto * Create(){
    Texto * t = (Texto *) malloc(sizeof(Texto));
    assert(t != NULL);

    return t;
}

Texto * Realloc(Texto * t, int tam){
    assert(t != NULL);
    t = (Texto *) realloc(t,(tam + 1) * sizeof(Texto));
    return t;
}

void Destroy(Texto * t){
    assert(t != NULL);
    free(t);
    t = NULL;
}

int strleng(char * str){
    int i = 0;
    do{
        i++;
    }while(str[i] != '\0');

    return i;
}

char * strcopy(char * strCopia, char * strCopiada){
    int i;
    for(i = 0; strCopiada[i]; i++){
        strCopia[i] = strCopiada[i];
    }
    strCopia[i] = '\0';

    return strCopia;
}

char * substituir(char * str1, char * str2, char * str3){
	int pos_str1, pos_str2 = 0,pos_aux, cont4 = 0;
	char aux[101];

	for(pos_str1 = 0; str1[pos_str1]; pos_str1++){
		if(str1[pos_str1] == str2[pos_str2]){
			pos_str2++;
			if(str2[pos_str2] == '\0'){
				for(pos_aux = 0; pos_aux < pos_str1 - pos_str2 + 1; pos_aux++){
					aux[pos_aux] = str1[pos_aux];
				}
				for(cont4 = 0; cont4 < strleng(str3); cont4++){
					aux[pos_aux] = str3[cont4];
					pos_aux++;
				}
				for(cont4 = pos_str1 + 1; str1[cont4]; cont4++){
					aux[pos_aux] = str1[cont4];
					pos_aux++;
				}
				aux[pos_aux] = '\0';
				strcopy(str1,aux);

                substituir(str1,str2,str3);
			}

		}else{
			pos_str2 = 0;
		}
	}

	return str1;

}
