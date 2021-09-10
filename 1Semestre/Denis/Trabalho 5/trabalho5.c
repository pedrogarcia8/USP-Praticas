//Pedro Jos� Garcia 11846943.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct palavras{ // in�cio estrutura. 
	char palavra[121]; // vari�vel para armazenar palavras de at� 120 caracteres.
}; // fim estrutura.

typedef struct palavras Palavra; // crio um alias para a estrutura.

void tiraPalavraRepetida(Palavra *p, int tam);//fun��o para tirar as palavras repetidas de uma mesma estrutura.

int main(){
	setlocale(LC_ALL, "Portuguese"); // para ler caracteres especiais, caso houver, nos arquivos.
	
	FILE *arq, *arq2; // ponteiro para os dois arquivos.
	char texto1[121], texto2[121]; //texto1 -> para ler palavras de at� 120 caracteres no arquivo1, 
	//texto2 -> para ler palavras de at� 120 caracteres no arquivo2;
	int cont,cont2,cont3,cont4,cont5; // contadores
	Palavra *p, *p2;// ponteiros para a estrutura, que ser�o usados para armazenar as palavras dos arquivos.
	
	p  = (Palavra *) malloc(1 * sizeof(Palavra));// aloca 1 posi��o na mem�ria para p.
	p2 = (Palavra *) malloc(1 * sizeof(Palavra));// aloca 1 posi��o na mem�ria para p2.
		
	if((arq = fopen("dados.txt","r")) == NULL){// in�cio if(tenta abrir o arquivo 1, se n�o conseguir exibe a mensagem e finaliza o programa).
		printf("\nErro ao abrir arquivo");
		exit(0); // finaliza o programa.
	} // fim if.
		
	if((arq2 = fopen("dados2.txt","r")) == NULL){// in�cio if(tenta abrir o arquivo 2, se n�o conseguir exibe a mensagem e finaliza o programa).
		printf("\nErro ao abrir arquivo");
		exit(0);// finaliza o programa.
	}//fim if
	
	cont = 0; // zera o primeiro contador.
	while(!feof(arq)){ //in�cio while (percorrer� at� o final do arquivo 1).
		fscanf(arq,"%s",p[cont].palavra) != ' ';//armazena cada palavra, que esteja separada por espa�o ou quebra de linha, no ponteiro 1 da estrutura.
		cont++;// acrescenta mais 1 no primeiro contador.
		p = (Palavra *) realloc(p, (cont+1) * sizeof(Palavra));	// aloca mais 1 posi��o na mem�ria para p.	
	}// fim while
	
	cont2 = 0; // zera o segundo contador.
	while(!feof(arq2)){//in�cio while (percorrer� at� o final do arquivo 2). 
		fscanf(arq2,"%s",p2[cont2].palavra) != ' ';//armazena cada palavra, que esteja separada por espa�o ou quebra de linha, no ponteiro 2 da estrutura.
		cont2++;// acrescenta mais 1 no segundo contador.
		p2 = (Palavra *) realloc(p2, (cont2+1) * sizeof(Palavra));// aloca mais 1 posi��o na mem�ria para p2.	
	}// fim while.
	
	fclose(arq); // fecha o arquivo 1.
	fclose(arq2);// fecha o arquivo 2.	
	
	tiraPalavraRepetida(p,cont);// chama a fun��o "tiraPalavraRepetida" passando o ponteiro 1 da estrutura e o tamanho do mesmo.
	tiraPalavraRepetida(p2,cont2);// chama a fun��o "tiraPalavraRepetida" passando o ponteiro 2 da estrutura e o tamanho do mesmo.
	
	for(cont3 = 0; cont3 < cont; cont3++){//in�cio for (percorrer� at� o final do ponteiro 1 da estrutura).
		for(cont4 = 0; cont4 < cont2; cont4++){//in�cio for (percorrer� at� o final do ponteiro 2 da estrutura).
			if(!stricmp(p[cont3].palavra,p2[cont4].palavra)){//in�cio if (verifica se a string que est� na posi��o "cont3" � igual a da posi��o "cont4".
				if(stricmp(p2[cont4].palavra,"\0"))// se sim, verifica se � uma string n�o nula.
					printf("%s\n",strlwr(p2[cont4].palavra));//se sim, exibe na tela a string toda min�scula. 
			}//fim if
		}//fim for
	}//fim for
	
	free(p);// limpa a mem�ria alocada para p.
	free(p2);// limpa a mem�ria alocada para p2.
	
	return 0;
}

void tiraPalavraRepetida(Palavra *p, int tam){ //in�cio fun��o para tirar as palavras repetidas de uma mesma estrutura.
	int cont, cont2, cont3;// contadores
	char palavraIgual[121];// a vari�vel palavraIgual serve para armazenar uma palavra, de at� 120 caracteres, e compar�-la depois.
	for(cont = 0; cont < tam; cont++){//in�cio for (percorrer� at� o final do ponteiro da estrutura).
		strcpy(palavraIgual,p[cont].palavra);// copia a palavra que est� na posi��o "cont" para a vari�vel "palavraIgual".
		cont3 = 0;// zera o terceiro contador.
		for(cont2 = 0; cont2 < tam; cont2++){//in�cio for (percorrer� novamente at� o final do ponteiro da estrutura).
			if(!stricmp(p[cont2].palavra,palavraIgual))//verifica se a vari�vel "palavraIgual" � igual ao valor que est� posi��o "cont2" do ponteiro.
				cont3++;// se for igual, acrescenta mais 1 no terceiro contador.
		}//fim for.
		if(cont3 > 1)//in�cio if (verifica se o terceiro contador � maior que 1).
			strcpy(p[cont].palavra,"\0");// se sim, zera a string que est� armazenada na posi��o "cont".
	}//fim for.	
}// fim fun��o para tirar as palavras repetidas de uma mesma estrutura.
