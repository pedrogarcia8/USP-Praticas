//Pedro José Garcia 11846943.
#include <stdio.h>

double fatorial(int num);//função para calcular o fatorial de um número.

int main(){
	int n, cont,cont2;//n -> número de linhas definido pelo usuário. cont e cont2 -> contadores.
	
	printf("Digite o numero de linha do Triangulo de Pascal: ");
	scanf("%d",&n);//armazena o número de linhas definido pelo usuário.
	system("cls");//limpa a tela.
	
	for(cont = 0; cont <= n; cont++){//início for (percorrerá o número de linhas definido pelo usuário).
		for(cont2 = 0; cont2 <= cont; cont2++)//percorerrá o número de colunas conforme o triângulo de pascal.
			printf("%.0lf ",fatorial(cont) / (fatorial(cont-cont2) * fatorial(cont2)) );//exibirá o triângulo de pascal segundo a fórmula n! / ((n-p)! * p!).
		printf("\n");//pula a linha.
	}//fim for
	
	return 0;
}

double fatorial(int num){//início função para calcular o fatorial de um número. (foi usado double como retorno para conseguir calcular números muito grandes). Foi testado até n = 100.
	int cont;//cont -> contador.
	double fat = 1;//fat -> armazenará o fatorial do número calculado.
	
	for(cont = 1; cont <= num; cont++)//percorerrá até o número que se quer saber o fatorial.
		fat = fat * cont;//multiplicando os número até chegar no número que se quer saber o fatorial. 
		//Exemplo: se quer saber 3! multiplica 1*1, 1*2, 2*3. 3! = 6. Se quer saber 4! multiplica 1*1,1*2,2*3,6*4. 4! = 24.
	return fat;//retorna o fatorial de um número.
}//fim função para calcular o fatorial de um número.
