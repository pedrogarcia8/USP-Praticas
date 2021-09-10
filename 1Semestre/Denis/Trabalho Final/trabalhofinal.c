//Pedro Jos� Garcia 11846943.
#include <stdio.h>

double fatorial(int num);//fun��o para calcular o fatorial de um n�mero.

int main(){
	int n, cont,cont2;//n -> n�mero de linhas definido pelo usu�rio. cont e cont2 -> contadores.
	
	printf("Digite o numero de linha do Triangulo de Pascal: ");
	scanf("%d",&n);//armazena o n�mero de linhas definido pelo usu�rio.
	system("cls");//limpa a tela.
	
	for(cont = 0; cont <= n; cont++){//in�cio for (percorrer� o n�mero de linhas definido pelo usu�rio).
		for(cont2 = 0; cont2 <= cont; cont2++)//percorerr� o n�mero de colunas conforme o tri�ngulo de pascal.
			printf("%.0lf ",fatorial(cont) / (fatorial(cont-cont2) * fatorial(cont2)) );//exibir� o tri�ngulo de pascal segundo a f�rmula n! / ((n-p)! * p!).
		printf("\n");//pula a linha.
	}//fim for
	
	return 0;
}

double fatorial(int num){//in�cio fun��o para calcular o fatorial de um n�mero. (foi usado double como retorno para conseguir calcular n�meros muito grandes). Foi testado at� n = 100.
	int cont;//cont -> contador.
	double fat = 1;//fat -> armazenar� o fatorial do n�mero calculado.
	
	for(cont = 1; cont <= num; cont++)//percorerr� at� o n�mero que se quer saber o fatorial.
		fat = fat * cont;//multiplicando os n�mero at� chegar no n�mero que se quer saber o fatorial. 
		//Exemplo: se quer saber 3! multiplica 1*1, 1*2, 2*3. 3! = 6. Se quer saber 4! multiplica 1*1,1*2,2*3,6*4. 4! = 24.
	return fat;//retorna o fatorial de um n�mero.
}//fim fun��o para calcular o fatorial de um n�mero.
