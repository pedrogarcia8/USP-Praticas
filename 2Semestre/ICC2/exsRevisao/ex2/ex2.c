#include <stdio.h>
#include <stdlib.h>

int main(){
	int *V, N, i, menor, cont = 0;
	
	scanf("%d",&N);
	
	V = (int *) calloc(N, sizeof(int));
	
	for(i = 0; i < N; i++)
		scanf("%d",&V[i]);
	
	menor = V[0];
	for(i = 0; i < N; i++){
		if(i+1 < N){
			if(V[i + 1] >= menor){
				cont++;
				menor = V[i + 1];
			}else {
				cont--;
				menor = V[i + 1];
			}
		}	
	}
	
	if(cont+1 == N){
		printf("1\n");
	}else{
		if(cont-1 == -N){
			printf("-1\n");
		}
		else{
			printf("0\n");
		}
	} 
	
	return 0;
}
