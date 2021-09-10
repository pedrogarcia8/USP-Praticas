// Nome: Pedro José Garcia, número USP: 11846943
#include <stdio.h>
#include <stdlib.h>

float **somaMatriz(float **A, float **B, int l, int c);

int main(){
	float **A, **B, **soma; // A -> matriz A, B -> matriz B e soma -> matriz soma
	int l,c,lin,col; //l -> num. de linhas, c -> num. de colunas, lin e col -> contadores
	printf("Digite o numero de linhas e o numero de colunas: ");
	scanf("%d %d",&l,&c);// armazena o num. de linhas e o num. de colunas
	if((l<1)||(c<1)){//ínicio if (verifica se o num. de linhas e se o num. de colunas é menor do que 1)
		printf(" Erro: Parametros invalidos ");
		exit(0); // finaliza o programa
	}// fim if
	A 	 = (float **) calloc(l, sizeof(float *)); //aloca l espaços de memória para as linhas da matriz A e inicializa com 0
	B 	 = (float **) calloc(l, sizeof(float *)); //aloca l espaços de memória para as linhas da matriz B e inicializa com 0
	soma = (float **) calloc(l, sizeof(float *)); //aloca l espaços de memória para as linhas da matriz soma e inicializa com 0
	if((A == NULL)||(B == NULL)||(soma == NULL)){// ínicio if (verifica se foi alocado espaços de memória)
		printf(" Erro: Memoria insuficiente ");
		exit(0);// finaliza o programa
	}// fim if
	for(lin = 0; lin < l; lin++){// ínicio for de alocação de memória
		A[lin] 	  = (float *) calloc(c, sizeof(float)); //aloca c espaços de memória para as colunas da matriz A e inicializa com 0
		B[lin] 	  = (float *) calloc(c, sizeof(float)); //aloca c espaços de memória para as colunas da matriz B e inicializa com 0
		soma[lin] = (float *) calloc(c, sizeof(float)); //aloca c espaços de memória para as colunas da matriz soma e inicializa com 0
		if((A[lin] == NULL)||(B[lin] == NULL)||(soma[lin] == NULL)){// ínicio if (verifica se foi alocado espaços de memória)
			printf(" Erro: Memoria insuficiente ");
			exit(0);//finaliza o programa
		}// fim if
	}// fim for de alocação de memória
	for(lin = 0; lin < l; lin++){ // ínicio for de armazenamento nas linhas
		for(col = 0; col < c; col++){//ínicio for de armazenamento nas colunas
			printf("Matriz A (%d,%d): ",lin+1,col+1);//exibe a posição da matriz que vai ser armazenado o valor
			scanf("%f",&A[lin][col]);// armazena os valores
		}// fim for
	}// fim for
	for(lin = 0; lin < l; lin++){// ínicio for de armazenamento nas linhas
		for(col = 0; col < c; col++){// ínicio for de armazenamento nas colunas
			printf("Matriz B (%d,%d): ",lin+1,col+1);//exibe a posição da matriz que vai ser armazenado o valor
			scanf("%f",&B[lin][col]);// armazena os valores
		}// fim for
	}// fim for
	system("cls");// limpa a tela
	soma = somaMatriz(A,B,l,c); // armazena o retorno da função somaMatriz na matriz soma
	for(lin = 0; lin < l; lin++){// ínicio for de exibição da matriz soma
		for(col = 0; col < c; col++){//ínicio for
			printf("%.2f ",soma[lin][col]);//exibe os valores da matriz soma com 2 casas decimais
		}//fim for
		printf("\n");//pula linha
	}// fim for
	
	free(A);// limpa a memória alocada para a matriz A
	free(B);// limpa a memória alocada para a matriz B
	free(soma);// limpa a memória alocada para a matriz soma
	
	return 0;
}

float **somaMatriz(float **A, float **B, int l, int c){
	int lin, col;//contadores
	float **soma;// matriz soma
	soma = (float **) calloc(l, sizeof(float *));//aloca l espaços de memória para as linhas da matriz soma e inicializa com 0
	for(lin = 0; lin < l; lin++)//for de alocação de memória
		soma[lin] = (float *) calloc(c, sizeof(float));//aloca c espaços de memória para as colunas da matriz soma e inicializa com 0
	for(lin = 0; lin < l; lin++){// ínicio for de soma de matrizes
		for(col = 0; col < c; col++){// ínicio for
			soma[lin][col] = A[lin][col] + B[lin][col];// soma as matrizes A e B e armazena na matriz soma
		}// fim for
	}// fim for
	return soma; // retorna a matriz soma
}

