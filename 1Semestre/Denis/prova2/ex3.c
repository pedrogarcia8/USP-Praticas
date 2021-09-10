//Pedro José Garcia 11846943
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trocaGenero(char * nomeArq, struct filme *f){
	FILE *arq;
	int cont;
	f = (struct filme *) malloc(1000 * sizeof(struct filme));
	
	arq = fopen(nomeArq,"rb");
	if(arq == NULL){
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}
	for(cont = 0; cont < 1000; cont++){
		fread(&f,sizeof(struct filme),1,arq);	
	}
	
	fclose(arq);
	
	arq = fopen(nomeArq,"wb");
	if(arq == NULL){
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}
	for(cont = 0; cont < 1000; cont++){
		if(!stricmp(f[cont].genero,"Aventura")){
			strcpy(f[cont].genero,"Acao");
		}
		fwrite(&f,sizeof(struct filme),1,arq);
	}
	fclose(arq);
	

}


