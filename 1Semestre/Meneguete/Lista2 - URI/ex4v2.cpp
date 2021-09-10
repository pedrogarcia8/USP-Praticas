#include <stdio.h>
#include <stdlib.h>


int main(){
	int *v,**m, lin, col, cont = 0, cont2 = 0, aux = 0;
	v = (int *) calloc(1, sizeof(int));
	do{
		scanf("%d",&v[cont]);
		cont++;
		v = (int *) realloc(v, (sizeof(v) + cont) * sizeof(int));
	}while(v[cont-1] != 0);
	
	for(cont2 = 0; cont2 < v[cont2]; cont2++){
		m = (int **) calloc(v[cont2], sizeof(int *));
		for(lin = 0; lin < v[cont2]; lin++){
			m[lin] = (int *) calloc(v[cont2], sizeof(int));
		}
		for(cont = 0; cont < v[cont2]; cont++){
			if(v[cont2] - (cont+1) > 0){
				for(lin = aux; lin < v[cont2]-aux; lin++){
					for(col = aux; col < v[cont2]-aux; col++){
						m[lin][col] = m[lin][col] + 1;
					}	
				}		
			}else
				m[0][0] = 1;	
			aux++;
		}
		aux = 0;
		
		for(lin = 0; lin < v[cont2]; lin++){
			for(col = 0; col < v[cont2]; col ++){
				if(col == 0)
					printf("%3d",m[lin][col]);
				else	
					printf(" %3d",m[lin][col]);
			}	
			printf("\n");
		}
		printf("\n");
		
	}
	free(v);
	free(m);	
	return 0;
}
