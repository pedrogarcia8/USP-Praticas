// Nome: Pedro Jos� Garcia, n�mero USP: 11846943
#include <stdio.h>
#include <stdlib.h>

float **somaMatriz(float **A, float **B, int l, int c);

int main(){
	float **A, **B, **soma; // A -> matriz A, B -> matriz B e soma -> matriz soma
	int l,c,lin,col; //l -> num. de linhas, c -> num. de colunas, lin e col -> contadores
	printf("Digite o numero de linhas e o numero de colunas: ");
	scanf("%d %d",&l,&c);// armazena o num. de linhas e o num. de colunas
	if((l<1)||(c<1)){//�nicio if (verifica se o num. de linhas e se o num. de colunas � menor do que 1)
		printf(" Erro: Parametros invalidos ");
		exit(0); // finaliza o programa
	}// fim if
	A 	 = (float **) calloc(l, sizeof(float *)); //aloca l espa�os de mem�ria para as linhas da matriz A e inicializa com 0
	B 	 = (float **) calloc(l, sizeof(float *)); //aloca l espa�os de mem�ria para as linhas da matriz B e inicializa com 0
	soma = (float **) calloc(l, sizeof(float *)); //aloca l espa�os de mem�ria para as linhas da matriz soma e inicializa com 0
	if((A == NULL)||(B == NULL)||(soma == NULL)){// �nicio if (verifica se foi alocado espa�os de mem�ria)
		printf(" Erro: Memoria insuficiente ");
		exit(0);// finaliza o programa
	}// fim if
	for(lin = 0; lin < l; lin++){// �nicio for de aloca��o de mem�ria
		A[lin] 	  = (float *) calloc(c, sizeof(float)); //aloca c espa�os de mem�ria para as colunas da matriz A e inicializa com 0
		B[lin] 	  = (float *) calloc(c, sizeof(float)); //aloca c espa�os de mem�ria para as colunas da matriz B e inicializa com 0
		soma[lin] = (float *) calloc(c, sizeof(float)); //aloca c espa�os de mem�ria para as colunas da matriz soma e inicializa com 0
		if((A[lin] == NULL)||(B[lin] == NULL)||(soma[lin] == NULL)){// �nicio if (verifica se foi alocado espa�os de mem�ria)
			printf(" Erro: Memoria insuficiente ");
			exit(0);//finaliza o programa
		}// fim if
	}// fim for de aloca��o de mem�ria
	for(lin = 0; lin < l; lin++){ // �nicio for de armazenamento nas linhas
		for(col = 0; col < c; col++){//�nicio for de armazenamento nas colunas
			printf("Matriz A (%d,%d): ",lin+1,col+1);//exibe a posi��o da matriz que vai ser armazenado o valor
			scanf("%f",&A[lin][col]);// armazena os valores
		}// fim for
	}// fim for
	for(lin = 0; lin < l; lin++){// �nicio for de armazenamento nas linhas
		for(col = 0; col < c; col++){// �nicio for de armazenamento nas colunas
			printf("Matriz B (%d,%d): ",lin+1,col+1);//exibe a posi��o da matriz que vai ser armazenado o valor
			scanf("%f",&B[lin][col]);// armazena os valores
		}// fim for
	}// fim for
	system("cls");// limpa a tela
	soma = somaMatriz(A,B,l,c); // armazena o retorno da fun��o somaMatriz na matriz soma
	for(lin = 0; lin < l; lin++){// �nicio for de exibi��o da matriz soma
		for(col = 0; col < c; col++){//�nicio for
			printf("%.2f ",soma[lin][col]);//exibe os valores da matriz soma com 2 casas decimais
		}//fim for
		printf("\n");//pula linha
	}// fim for
	
	free(A);// limpa a mem�ria alocada para a matriz A
	free(B);// limpa a mem�ria alocada para a matriz B
	free(soma);// limpa a mem�ria alocada para a matriz soma
	
	return 0;
}

float **somaMatriz(float **A, float **B, int l, int c){
	int lin, col;//contadores
	float **soma;// matriz soma
	soma = (float **) calloc(l, sizeof(float *));//aloca l espa�os de mem�ria para as linhas da matriz soma e inicializa com 0
	for(lin = 0; lin < l; lin++)//for de aloca��o de mem�ria
		soma[lin] = (float *) calloc(c, sizeof(float));//aloca c espa�os de mem�ria para as colunas da matriz soma e inicializa com 0
	for(lin = 0; lin < l; lin++){// �nicio for de soma de matrizes
		for(col = 0; col < c; col++){// �nicio for
			soma[lin][col] = A[lin][col] + B[lin][col];// soma as matrizes A e B e armazena na matriz soma
		}// fim for
	}// fim for
	return soma; // retorna a matriz soma
}

