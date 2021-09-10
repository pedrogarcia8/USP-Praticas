// Nome: Pedro Jos� Garcia, n�mero USP: 11846943
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
	int *seq, *seqd, cont = 1, cont2 = 0; //seq -> sequ�ncia aleat�ria, seqd -> sequ�ncia digitada, cont e cont2 -> contadores
	srand(time(NULL)); // inicializa a sequ�ncia de n�meros aleat�rios;
	seq  = (int *) calloc(1, sizeof(int)); // aloca um espa�o e inicializa o valor dele como 0 na seq
	seqd = (int *) calloc(1, sizeof(int)); // aloca um espa�o e inicializa o valor dele como 0 na seqd
	do{ // �nicio while infinito
		seq[cont-1] = rand()%10; // gera um n�mero aleat�rio para a sequ�ncia
		printf("Sequencia para memorizar:");
		for(cont2 = 0; cont2 < cont; cont2++) // for de exibi��o da sequ�ncia aleat�ria
			printf(" %d",seq[cont2]); // exibe a sequ�ncia aleat�ria
		Sleep(5000); // pausa a exibi��o por 5 segundos
		system("cls"); // limpa a tela
		printf("Digite a sequencia: ");
		for(cont2 = 0; cont2 < cont; cont2++) // for de armazenamento da sequ�ncia digitada
			scanf("%d",&seqd[cont2]); // armazena a sequ�ncia digitada
		for(cont2 = 0; cont2 < cont; cont2++){ // �nicio for de verifica��o 
			if(seq[cont2] != seqd[cont2]){ // �nicio if verificador (verifica se a sequ�ncia aleat�ria � igual a digitada)
				printf("Pontuacao: %d",cont-1); // exibe a pontua��o
				free(seq); // limpa a mem�ria alocada para a seq
				free(seqd); // limpa a mem�ria alocada para a seqd
				exit(0); // finaliza o programa
			} // fim if verificador
		} // fim for de verifica��o
		cont++; // soma mais um na quantidade de n�meros das sequ�ncias
		seq  = (int *) realloc(seq,  cont  * sizeof(int)); // aloca mais um espa�o na seq
		seqd = (int *) realloc(seqd, cont  * sizeof(int)); // aloca mais um espa�o na seqd
		seq[cont-1]  = 0; // inicializa o valor como 0
		seqd[cont-1] = 0; // inicializa o valor como 0
		system("cls"); // limpa a tela
	}while(1);	// fim do while infinito
	
	return 0;
}
