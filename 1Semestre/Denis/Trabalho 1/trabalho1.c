// Nome: Pedro José Garcia, número USP: 11846943
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
	int *seq, *seqd, cont = 1, cont2 = 0; //seq -> sequência aleatória, seqd -> sequência digitada, cont e cont2 -> contadores
	srand(time(NULL)); // inicializa a sequência de números aleatórios;
	seq  = (int *) calloc(1, sizeof(int)); // aloca um espaço e inicializa o valor dele como 0 na seq
	seqd = (int *) calloc(1, sizeof(int)); // aloca um espaço e inicializa o valor dele como 0 na seqd
	do{ // ínicio while infinito
		seq[cont-1] = rand()%10; // gera um número aleatório para a sequência
		printf("Sequencia para memorizar:");
		for(cont2 = 0; cont2 < cont; cont2++) // for de exibição da sequência aleatória
			printf(" %d",seq[cont2]); // exibe a sequência aleatória
		Sleep(5000); // pausa a exibição por 5 segundos
		system("cls"); // limpa a tela
		printf("Digite a sequencia: ");
		for(cont2 = 0; cont2 < cont; cont2++) // for de armazenamento da sequência digitada
			scanf("%d",&seqd[cont2]); // armazena a sequência digitada
		for(cont2 = 0; cont2 < cont; cont2++){ // ínicio for de verificação 
			if(seq[cont2] != seqd[cont2]){ // ínicio if verificador (verifica se a sequência aleatória é igual a digitada)
				printf("Pontuacao: %d",cont-1); // exibe a pontuação
				free(seq); // limpa a memória alocada para a seq
				free(seqd); // limpa a memória alocada para a seqd
				exit(0); // finaliza o programa
			} // fim if verificador
		} // fim for de verificação
		cont++; // soma mais um na quantidade de números das sequências
		seq  = (int *) realloc(seq,  cont  * sizeof(int)); // aloca mais um espaço na seq
		seqd = (int *) realloc(seqd, cont  * sizeof(int)); // aloca mais um espaço na seqd
		seq[cont-1]  = 0; // inicializa o valor como 0
		seqd[cont-1] = 0; // inicializa o valor como 0
		system("cls"); // limpa a tela
	}while(1);	// fim do while infinito
	
	return 0;
}
