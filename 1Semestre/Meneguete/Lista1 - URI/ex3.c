#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N,A,B,C,D,numAnos,cont;
	float *crescAnual,crescTotal,*auxCrescAnual;
	scanf("%d",&N);
	crescAnual    = (float *) malloc(N * sizeof(float));
	auxCrescAnual = (float *) malloc(N * sizeof(float));
	for(cont=0;cont<N;cont++){
		A=0;B=0;C=0;D=0;
		scanf("%d %d %d %d",&A,&B,&C,&D);
		numAnos = abs(A-C);
		crescTotal = abs(B-D);
		crescAnual[cont] = crescTotal / numAnos;	
	}
	for(cont=0;cont<N;cont++){
		auxCrescAnual[cont] = trunc((crescAnual[cont]-(int)crescAnual[cont])*100);
		printf("%d,%02.f\n",(int)crescAnual[cont],auxCrescAnual[cont]); 
	}
	
	free(crescAnual);
	free(auxCrescAnual);
	return 0;
}
