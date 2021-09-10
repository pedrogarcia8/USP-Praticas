//Pedro José Garcia 11846943
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct texto{
	char palavra[120];
};

typedef struct texto Texto;

int main(){
	int cont = 1,cont2,cont3=0;
	char palavra[120];
	FILE *arqPalavra, *arqTexto;
	Texto *t;
	t = (Texto *) malloc(1000 * sizeof(Texto)); // considerei o arquivo texto.txt com 1000 palavras.
	
	arqPalavra = fopen("palavra.txt","r");
	if(arqPalavra == NULL){
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}
	
	fscanf(arqPalavra, "%s", palavra);
	
	fclose(arqPalavra);
	
	arqTexto = fopen("texto.txt","r");
	if(arqTexto == NULL){
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}
	
	do{
		fscanf(arqTexto, "%s", t[cont].palavra) != ' ';
		cont++;
	}while(!feof(arqTexto));
	
	fclose(arqTexto);
	
	for(cont2 = 0; cont2 < cont; cont2++){
		if(!stricmp(t[cont2].palavra,palavra))
			cont3++;
	}

	printf("O arquivo texto.txt possui %d vezes a palavra que esta no arquivo palavra.txt",cont3);
	
	return 0;
}
