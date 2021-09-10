#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N,cont, numAnos,A,B,C,D;
	float  crescAnual, decimal, crescTotal;
	scanf("%d",&N);
	for(cont=0;cont<N;cont++){
		scanf("%d %d %d %d", &A, &B, &C, &D);
		numAnos = abs(A-C);
		crescTotal = abs(B-D);
		crescAnual = crescTotal / numAnos;
		decimal = trunc( (crescAnual - (int)crescAnual) *100);
		printf("%d,%02.f\n",(int)crescAnual,decimal);
	}
	
	return 0;
}
