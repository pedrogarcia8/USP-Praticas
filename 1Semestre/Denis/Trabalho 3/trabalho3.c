// Pedro Jos� Garcia 11846943
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filmes{ // in�cio estrutura ( armazena os dados dos filmes)
	char titulo[101]; //  titulo de um filme, at� 100 caracteres
	char genero[51]; //  g�nero de um filme, at� 50 caracteres
	int ano; // ano do filme
};// fim estrutura

void armazena(struct filmes f[5]); // fun��o para armazenar os dados do filme
void exibirPorAno(struct filmes f[5]); // fun��o para exibir os dados dos filmes de 2001 a 2005
void exibirPorGenero(struct filmes f[5], char genero[51]); // fun��o para exibir os dados dos filmes de determinado g�nero

int main(){
	struct filmes f[5]; // vetor de estruturas
	int resp; // resposta do usu�rio
	char genero[51]; // g�nero de um filme, at� 50 caracteres
	armazena(f); // chama a fun��o que armazena os dados do filme
	while(resp != 0){ // in�cio while
		system("cls"); // limpa a tela
		printf(" Menu\n");
		printf("1 - Exibir filmes feito de 2001 a 2005\n");
		printf("2 - Exibir filmes de determinado genero\n");
		printf("0 - Finalizar programa\n");
		scanf("%d",&resp); // armazena a escolha do usu�rio
		switch(resp){// in�cio switch
			case 1: // se a escolha for 1
				exibirPorAno(f); // chama a fun��o que exibi os dados dos filmes de 2001 a 2005
				break;
			case 2: // se a escolha for 2 
				printf("\nDigite o genero a ser pesquisado: ");
				scanf(" %[^\n]s",genero); // armazena o g�nero a ser pesquisado
				exibirPorGenero(f,genero); // chama a fun��o que exibi os dados dos filmes de determinado g�nero
			default: // se a escolha n�o for nenhuma das op��es definidas
				continue; // volta ao menu para a escolha de uma op��o dispon�vel
		}// fim switch
	}// fim while
	
	return 0;
}

void armazena(struct filmes f[5]){ // in�cio fun��o para armazenar os dados do filme
	int cont; // contador
	for(cont = 0; cont < 5; cont++){// in�cio for
		system("cls"); // limpa a tela
		printf("Digite o titulo do filme %d: ",cont+1); // cont + 1 para mostrar o n�mero do filme que est� sendo armazenado na estrutura
		scanf(" %[^\n]s",f[cont].titulo); // armazena o t�tulo do filme na estrutura
		printf("\nDigite o genero do filme %d: ",cont+1); // cont + 1 para mostrar o n�mero do filme que est� sendo armazenado na estrutura
		scanf(" %[^\n]s",f[cont].genero); // armazena o g�nero do filme na estrutura
		printf("\nDigite o ano do filme %d: ",cont+1); // cont + 1 para mostrar o n�mero do filme que est� sendo armazenado na estrutura
		scanf("%d",&f[cont].ano);	// armazena o ano do filme na estrutura
	} // fim for
} // fim fun��o para armazenar os dados do filme

void exibirPorAno(struct filmes f[5]){// in�cio fun��o para exibir os dados dos filmes de 2001 a 2005
	int cont; // contador
	for(cont = 0; cont < 5; cont++){// in�cio for
		if((f[cont].ano >= 2001) && (f[cont].ano <= 2005)){ // in�cio if (se o ano for de 2001 a 2005, exibe as informa��es dos filmes)
			printf("Titulo: %s\n",f[cont].titulo); 
			printf("Genero: %s\n",f[cont].genero);
			printf("Ano: %d\n", f[cont].ano);
		}// fim if
	}// fim for
	getch();// espera o usu�rio apertar uma tecla para continuar, foi usado para as informa��es dos filmes n�o sumirem rapidamente
} // fim fun��o para exibir os dados dos filmes de 2001 e de 2005

void exibirPorGenero(struct filmes f[5], char genero[51]){ // in�cio fun��o para exibir os dados dos filmes de determinado g�nero
	int cont;// contador
	for(cont = 0; cont < 5; cont++){// in�cio for
		if(!stricmp(f[cont].genero,genero)){ // in�cio if (se o gen�ro for igual ao escolhido pelo usu�rio, exibe as informa��es dos filmes)
			printf("Titulo: %s\n",f[cont].titulo);
			printf("Genero: %s\n",f[cont].genero);
			printf("Ano: %d\n", f[cont].ano);	
		} // fim if
	}// fim for
	getch();// espera o usu�rio apertar uma tecla para continuar, foi usado para as informa��es dos filmes n�o sumirem rapidamente
}// fim fun��o para exibir os dados dos filmes de determinado g�nero
