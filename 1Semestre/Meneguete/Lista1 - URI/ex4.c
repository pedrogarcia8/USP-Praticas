#include <stdio.h>
#include <math.h>

int main(){
	int A,B,C,lado;
	while((A != 0)&&(B != 0)&&(C != 0)){
		scanf("%d",&A);
		if(A == 0) exit(0);
		scanf("%d",&B);
		scanf("%d",&C);
		if((A != 0)&&(B != 0)&&(C != 0)){
			lado = sqrt((A*B)/((float)C /100));	
			printf("%d\n",lado);	
		}	
	}	
	return 0;
}
