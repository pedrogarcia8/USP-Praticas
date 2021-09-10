#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * substituir(char * str1, char * str2, char * str3);

int main(){
	char str1[100], str2[100], str3[100];
	scanf(" %[^\n]s", str1);
	scanf(" %[^\n]s", str2);
	scanf(" %[^\n]s", str3);
	printf("String substituida:  %s", substituir(str1,str2,str3));

	return 0;
}

char * substituir(char * str1, char * str2, char * str3){
	int pos_str1, pos_str2 = 0,pos_aux, cont4 = 0;
	char aux[100];

	for(pos_str1 = 0; str1[pos_str1]; pos_str1++){
		if(str1[pos_str1] == str2[pos_str2]){
			pos_str2++;
			if(str2[pos_str2] == '\0'){
				for(pos_aux = 0; pos_aux < pos_str1 - pos_str2 + 1; pos_aux++){
					aux[pos_aux] = str1[pos_aux];
				}
				for(cont4 = 0; cont4 < strlen(str3); cont4++){
					aux[pos_aux] = str3[pos_aux];
					pos_aux++;
				}
				for(cont4 = pos_str1; cont4 < str1[cont4]; cont4++){
					aux[pos_aux] = str1[cont4];
					pos_aux++;
				}
				break;
			}
		}else{
			pos_str2 = 0;
		}
	}
	printf("\n%d\n",pos_aux);
	strcpy(str1,aux);
	free(aux);
	return str1;

}
