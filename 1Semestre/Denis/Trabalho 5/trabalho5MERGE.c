//Pedro José Garcia 11846943.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct palavras{ // início estrutura. 
	char palavra[121]; // variável para armazenar palavras de até 120 caracteres.
}; // fim estrutura.

typedef struct palavras Palavra; // crio um alias para a estrutura.

int main(){
	setlocale(LC_ALL, "Portuguese"); // para ler caracteres especiais, caso houver, nos arquivos.
	
	FILE *arq, *arq2; // ponteiro para os dois arquivos.
	char texto1[121], texto2[121], palavraIgual[121]; //texto1 -> para ler palavras de até 120 caracteres no arquivo1, 
	//texto2 -> para ler palavras de até 120 caracteres no arquivo2, e palavraIgual para armazenar uma palavra, de até 120 caracteres, e compará-la depois.
	int cont,cont2,cont3,cont4,cont5; // contadores
	Palavra *p, *p2;// ponteiros para a estrutura, e serão usados para armazenar as palavras dos arquivos.
	
	p  = (Palavra *) malloc(1 * sizeof(Palavra));// aloca 1 posição na memória para p.
	p2 = (Palavra *) malloc(1 * sizeof(Palavra));// aloca 1 posição na memória para p2.
		
	if((arq = fopen("dados.txt","r")) == NULL){// início if(tenta abrir o arquivo 1, se não conseguir exibe a mensagem e finaliza o programa).
		printf("\nErro ao abrir arquivo");
		exit(0); // finaliza o programa.
	} // fim if.
		
	if((arq2 = fopen("dados2.txt","r")) == NULL){// início if(tenta abrir o arquivo 2, se não conseguir exibe a mensagem e finaliza o programa).
		printf("\nErro ao abrir arquivo");
		exit(0);// finaliza o programa.
	}//fim if
	cont = 0;
	while(!feof(arq)){
		fscanf(arq,"%s",p[cont].palavra) != ' ';
		cont++;
		p = (Palavra *) realloc(p, (cont+1) * sizeof(Palavra));	
		
	}
	cont2 = 0;
	while(!feof(arq2)){
		fscanf(arq2,"%s",p2[cont2].palavra) != ' ';
		cont2++;
		p2 = (Palavra *) realloc(p2, (cont2+1) * sizeof(Palavra));	
		
	}
	
	fclose(arq);
	fclose(arq2);	
	
	for(cont3 = 0; cont3 < cont; cont3++){
		strcpy(palavraIgual,p[cont3].palavra);
		cont5 = 0;
		for(cont4 = 0; cont4 < cont; cont4++){
			if(!stricmp(p[cont4].palavra,palavraIgual))
				cont5++;
		}
		if(cont5 > 1)
			strcpy(p[cont3].palavra,"\0");
		else
			continue;
	}
	
	for(cont3 = 0; cont3 < cont2; cont3++){
		strcpy(palavraIgual,p2[cont3].palavra);
		cont5 = 0;
		for(cont4 = 0; cont4 < cont2; cont4++){
			if(!stricmp(p2[cont4].palavra,palavraIgual))
				cont5++;
		}
		if(cont5 > 1)
			strcpy(p2[cont3].palavra,"\0");
		else
			continue;
	}

	for(cont3 = 0; cont3 < cont; cont3++){
		for(cont4 = 0; cont4 < cont2; cont4++){
			if(!stricmp(p[cont3].palavra,p2[cont4].palavra)){
				strcpy(p[cont3].palavra,"\0");
			}
		}
	}
	
	for(cont3 = 0; cont3 < cont; cont3++){
		if(stricmp(p[cont3].palavra,"\0"))
			printf("%s\n",p[cont3].palavra);
	}
	for(cont3 = 0; cont3 < cont2; cont3++){
		if(stricmp(p2[cont3].palavra,"\0"))
			printf("%s\n",p2[cont3].palavra);
	}
	
	return 0;
}
