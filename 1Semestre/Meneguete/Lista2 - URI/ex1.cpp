#include <stdio.h>

int main(){
	int V, N[10],cont;
	scanf("%d",&V);
	N[0] = V;
	for(cont = 1; cont < 10; cont++){
		N[cont] = N[cont-1] * 2;
	}
	for(cont = 0; cont < 10; cont++){
		printf("N[%d] = %d\n",cont,N[cont]);	
	}
		
	return 0;
}
