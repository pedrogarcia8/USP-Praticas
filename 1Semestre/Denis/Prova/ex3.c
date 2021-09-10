//Pedro José Garcia 11846943
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filmes{
	char nome[201];
	char genero[101];
	int ano;
	float avaliacao;
};

void pesquisaFilme(struct filmes *f,int quantFilmes);//quantFilmes -> quantidade de filmes digitados pelo usuário.

int main(){
	struct filmes f[5]; // considerei que o usuário vai digitar 5 filmes.
	int cont;
	
	for(cont = 0; cont < 5; cont++){
		printf("Digite o nome do filme %d: ",cont+1);
		scanf(" %[^\n]s",f[cont].nome);
		printf("Digite o genero do filme %d: ",cont+1);
		scanf(" %[^\n]s",f[cont].genero);
		printf("Digite o ano do filme %d: ",cont+1);
		scanf("%d",&f[cont].ano);
		printf("Digite a avaliacao do filme %d: ",cont+1);
		scanf("%f",&f[cont].avaliacao);
	}	
	system("cls");
	pesquisaFilme(f,5);
	return 0;
}

void pesquisaFilme(struct filmes *f,int quantFilmes){
	int cont;
	for(cont = 0; cont < quantFilmes; cont++){
		if((!stricmp(f[cont].genero,"aventura"))&&((f[cont].ano >= 2000)&&(f[cont].ano <= 2010)))
			printf("Nome: %s\nGenero: %s\nAno: %d\nAvalicao: %.2f\n",f[cont].nome,f[cont].genero,f[cont].ano,f[cont].avaliacao);
	}
}
