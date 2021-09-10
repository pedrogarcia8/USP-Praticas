#include <stdio.h>

int main(){
	long long int n;
	int b, cont, cont2 = 0, aux1, aux2, aux3;
	float c;
	while(1){
		cont = 0; aux1 = 0; aux2 = 1; aux3 = 0;
		scanf("%lld %d",&n,&b);
		if((n == 0) && (b == 0))
			exit(0);
		do{
			aux3 = aux1 + aux2;
			aux1 = aux2;
			aux2 = aux3;
			cont++;	
		}while(aux3 <= n);
		cont2++;
		if(n == 0)
			c = cont % b;
		if(n == 1)
			c = (cont % b) - 1;
		if(n == 2)
			c = cont % b;	
		if(n > 2)
			c = (cont % b) + 1;	
		printf("Case %d: %lld %d %.0f\n",cont2,n,b,c);
	}
	return 0;
}
