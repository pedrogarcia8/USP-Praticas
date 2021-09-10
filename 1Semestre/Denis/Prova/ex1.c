//Pedro José Garcia 11846943
#include <stdio.h>
#include <stdlib.h>

long int coord(float matriz[10][10]);

int main(){
	float matriz[10][10] = {1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,1,0,
							1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,1,1,
							1,1,1,1,1,1,1,1,2,1};
	printf("%d",coord(matriz));
	
	
	return 0;
}

long int coord(float matriz[10][10]){
	int maior = 0,lin,col,menor = 0;
	long int coord;	
	
	for(lin = 0; lin < 10; lin++){
		for(col = 0; col < 10; col++){
			if(matriz[lin][col] > maior)
				maior = matriz[lin][col];
			if(matriz[lin][col] < menor)
				menor = matriz[lin][col];
		}
	}
	for(lin = 0; lin < 10; lin++){
		for(col = 0; col < 10; col++){
			if(matriz[lin][col] == maior){
				coord = lin + 1;
				coord = coord * 100;
				coord = coord + col + 1;
			}	
		}
	}
	
	for(lin = 0; lin < 10; lin++){
		for(col = 0; col < 10; col++){
			if(matriz[lin][col] == menor){
				coord = coord * 100;
				coord = coord + lin + 1;
				coord = coord * 100;
				coord = coord + col + 1;
			}	
		}
	}
	
	return coord; //retorna o valor as coordenadas no formato (XXYYXXYY) ou (XYYXXYY) sendo a coordenada do maior primeiro.
	
}
