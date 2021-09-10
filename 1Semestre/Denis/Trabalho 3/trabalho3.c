// Pedro José Garcia 11846943
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filmes{ // início estrutura ( armazena os dados dos filmes)
	char titulo[101]; //  titulo de um filme, até 100 caracteres
	char genero[51]; //  gênero de um filme, até 50 caracteres
	int ano; // ano do filme
};// fim estrutura

void armazena(struct filmes f[5]); // função para armazenar os dados do filme
void exibirPorAno(struct filmes f[5]); // função para exibir os dados dos filmes de 2001 a 2005
void exibirPorGenero(struct filmes f[5], char genero[51]); // função para exibir os dados dos filmes de determinado gênero

int main(){
	struct filmes f[5]; // vetor de estruturas
	int resp; // resposta do usuário
	char genero[51]; // gênero de um filme, até 50 caracteres
	armazena(f); // chama a função que armazena os dados do filme
	while(resp != 0){ // início while
		system("cls"); // limpa a tela
		printf(" Menu\n");
		printf("1 - Exibir filmes feito de 2001 a 2005\n");
		printf("2 - Exibir filmes de determinado genero\n");
		printf("0 - Finalizar programa\n");
		scanf("%d",&resp); // armazena a escolha do usuário
		switch(resp){// início switch
			case 1: // se a escolha for 1
				exibirPorAno(f); // chama a função que exibi os dados dos filmes de 2001 a 2005
				break;
			case 2: // se a escolha for 2 
				printf("\nDigite o genero a ser pesquisado: ");
				scanf(" %[^\n]s",genero); // armazena o gênero a ser pesquisado
				exibirPorGenero(f,genero); // chama a função que exibi os dados dos filmes de determinado gênero
			default: // se a escolha não for nenhuma das opções definidas
				continue; // volta ao menu para a escolha de uma opção disponível
		}// fim switch
	}// fim while
	
	return 0;
}

void armazena(struct filmes f[5]){ // início função para armazenar os dados do filme
	int cont; // contador
	for(cont = 0; cont < 5; cont++){// início for
		system("cls"); // limpa a tela
		printf("Digite o titulo do filme %d: ",cont+1); // cont + 1 para mostrar o número do filme que está sendo armazenado na estrutura
		scanf(" %[^\n]s",f[cont].titulo); // armazena o título do filme na estrutura
		printf("\nDigite o genero do filme %d: ",cont+1); // cont + 1 para mostrar o número do filme que está sendo armazenado na estrutura
		scanf(" %[^\n]s",f[cont].genero); // armazena o gênero do filme na estrutura
		printf("\nDigite o ano do filme %d: ",cont+1); // cont + 1 para mostrar o número do filme que está sendo armazenado na estrutura
		scanf("%d",&f[cont].ano);	// armazena o ano do filme na estrutura
	} // fim for
} // fim função para armazenar os dados do filme

void exibirPorAno(struct filmes f[5]){// início função para exibir os dados dos filmes de 2001 a 2005
	int cont; // contador
	for(cont = 0; cont < 5; cont++){// início for
		if((f[cont].ano >= 2001) && (f[cont].ano <= 2005)){ // início if (se o ano for de 2001 a 2005, exibe as informações dos filmes)
			printf("Titulo: %s\n",f[cont].titulo); 
			printf("Genero: %s\n",f[cont].genero);
			printf("Ano: %d\n", f[cont].ano);
		}// fim if
	}// fim for
	getch();// espera o usuário apertar uma tecla para continuar, foi usado para as informações dos filmes não sumirem rapidamente
} // fim função para exibir os dados dos filmes de 2001 e de 2005

void exibirPorGenero(struct filmes f[5], char genero[51]){ // início função para exibir os dados dos filmes de determinado gênero
	int cont;// contador
	for(cont = 0; cont < 5; cont++){// início for
		if(!stricmp(f[cont].genero,genero)){ // início if (se o genêro for igual ao escolhido pelo usuário, exibe as informações dos filmes)
			printf("Titulo: %s\n",f[cont].titulo);
			printf("Genero: %s\n",f[cont].genero);
			printf("Ano: %d\n", f[cont].ano);	
		} // fim if
	}// fim for
	getch();// espera o usuário apertar uma tecla para continuar, foi usado para as informações dos filmes não sumirem rapidamente
}// fim função para exibir os dados dos filmes de determinado gênero
