#include <stdio.h>
#include <string.h>

int main(){
	char S[100000];
	int cont,cont2 = 0, cont3 = 0;
	scanf(" %[^\n]s",S);
	for(cont = 0; cont < 100000; cont++){
		if((S[cont] == "(")&&(S[cont+1] == ")"))
			cont2++;	
	}
	if(cont2 > 0)
		printf("Ainta temos %d assunto(s) pendente(s)",cont2);
	else
		printf("Partiu RU!");
	return 0;
}
