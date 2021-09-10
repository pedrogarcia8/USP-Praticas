#include <stdio.h>
#include <stdlib.h>

int main(){
	int T, cont, cont2, *N;
	long long int *fib,aux, aux2, aux3 = 0;
	scanf("%d",&T);
	N   = (int *) malloc(T * sizeof(int));
	fib = (long long int *) malloc(T * sizeof(long long int));
	for(cont = 0; cont < T; cont++){
		scanf("%d",&N[cont]);
		if ((N[cont] < 0) || (N[cont] > 60))
			exit(0);
	}
	for(cont = 0; cont < T; cont++){
		aux = 0; aux2 = 1;
		if(N[cont] == 0) 
			fib[cont] = aux;
		else{
			if(N[cont] == 1) 
				fib[cont] = aux2;
			else{
				for(cont2 = 1; cont2 < N[cont]; cont2++){
					aux3 = aux + aux2;	
					aux  = aux2;
					aux2 = aux3;
				}	
				fib[cont] = aux3;
			}
		}	
	}
	for(cont = 0; cont < T; cont++){
		printf("Fib(%d) = %lld\n",N[cont],fib[cont]);
	}
	
	return 0;
}
