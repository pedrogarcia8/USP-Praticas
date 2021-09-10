#include <stdio.h>
#include <ctype.h>

int main(){
	int C, lin, col;
	float M[12][12], soma = 0, media = 0;
	char T;
	scanf("%d",&C);
	scanf(" %c",&T);
	for(lin = 0; lin < 12; lin++){
		for(col = 0; col < 12; col++){
			scanf("%f",&M[lin][col]);
		}
	}
	for(lin = 0; lin < 12; lin++){
			soma = soma + M[lin][C];
	}
	if(toupper(T) == 'S'){		
		printf("%0.1f\n",soma);
	}
	if(toupper(T) == 'M'){
		media = soma / 12;
		printf("%0.1f\n",media);
	}
	
	return 0;
}
