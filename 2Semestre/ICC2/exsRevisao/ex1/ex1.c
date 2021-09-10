#include <stdio.h>
#include <stdlib.h>

int main(){
	int * V, N, i, menor;
	scanf("%d",&N);
	
	V = (int *) calloc(N, sizeof(int));
	
	for(i = 0; i < N; i++)
		scanf("%d",&V[i]);
		
	menor = V[0];
	for(i = 0; i < N; i++){
		if(menor > V[i])
			menor = V[i];
	}
	
	for(i = 0; i < N; i++){
		if(menor == V[i]){
			printf("%d\n",i);
			break;
		}
	}
	
	return 0;
}
