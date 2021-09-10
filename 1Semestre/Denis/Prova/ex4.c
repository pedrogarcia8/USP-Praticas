//Pedro José Garcia 11846943
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

char * tiraLetra(char palavra[101], char letra);

int main(){
	char palavra[101];
	char palavraNova[101];
	char letra;
	
	printf("Digite uma letra: ");
	letra = getchar();
	printf("Digite uma palavra: ");
	scanf(" %[^\n]s",palavra);

	strcpy(palavraNova,tiraLetra(palavra,letra));
	printf("\n%s\n",palavraNova);
	Sleep(3000);
	
	return 0;
}

char * tiraLetra(char palavra[101], char letra){
	int cont;
	char palavraNova[101];
	for(cont = 0; cont < 101; cont++){
		if(palavra[cont] != letra)
			palavraNova[cont] = palavra[cont];
		
	}
	return palavraNova;
}
