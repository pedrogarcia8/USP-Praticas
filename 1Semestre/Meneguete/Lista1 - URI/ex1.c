#include <stdio.h>

int main(){
	int valor1, valor2;
	scanf("%d %d",&valor1,&valor2);
	if((valor1 % valor2 == 0) || (valor2 % valor1 == 0)){
		printf("Sao Multiplos\n");	
	}
	else{
		printf("Nao sao Multiplos");	
	}
	return 0;
}
