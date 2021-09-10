#include <stdio.h>
#include <stdlib.h>

int main(){
	int v,**m, lin, col, cont, aux = 0;
	do{
		scanf("%d",&v);
		m = (int **) calloc(v, sizeof(int *));
		for(lin = 0; lin < v; lin++){
			m[lin] = (int *) calloc(v, sizeof(int));
		}
		for(cont = 0; cont < v; cont++){
			if(v - (cont+1) > 0){
				for(lin = aux; lin < v-aux; lin++){
					for(col = aux; col < v-aux; col++){
						m[lin][col] = m[lin][col] + 1;
					}	
				}		
			}else
				m[0][0] = 1;	
			aux++;
		}
		aux = 0;
		for(lin = 0; lin < v; lin++){
			for(col = 0; col < v; col ++){
				printf(" %3d",m[lin][col]);
			}	
			printf("\n");
		}
		printf("\n");
	}while(v != 0);
	
	return 0;
}
