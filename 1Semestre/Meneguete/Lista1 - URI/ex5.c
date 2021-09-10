#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int Q,D,P, pags;
	while(scanf("%d",&Q) != 0){	
		if(Q == 0) break;
		scanf("%d %d",&D,&P);
		pags = (Q*(D*P))/(P-Q);
		if (pags > 1)
			printf("%d paginas\n",pags);
		else
			printf("%d pagina\n",pags);	
	}	
	return 0;
}
