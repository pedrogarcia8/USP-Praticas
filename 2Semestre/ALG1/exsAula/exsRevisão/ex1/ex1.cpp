#include <stdio.h>
#include <stdlib.h>

struct linha {
	char conteudo[100];
};

typedef struct linha Linha;

int main(){
	Linha * linhas;
	FILE * arq;
	int cont = 0, cont2 = 0, cont3;
	
	arq = fopen("texto.txt", "rt");
	if (arq == NULL)
	{
    	printf("Problemas ao abrir o arquivo!\n");
    	exit(0);
	}
	
	linhas = (Linha *) malloc(1 * sizeof(Linha));
	while(!feof(arq)){
		fgets(linhas[cont].conteudo, sizeof(linhas[cont].conteudo), arq);
		linhas = (Linha *) realloc(linhas, (1 + cont) * sizeof(Linha));
		cont++;
	}
	
	fclose(arq);
	for(cont3 = 0; cont3 < cont; cont3++){
		printf("%s", linhas[cont3].conteudo);
	}
	free(linhas);
	return 0;
}
