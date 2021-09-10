//Pedro José Garcia 11846943
#include <stdio.h>

int verificaDivisoresComum(int num, int num2){
	int cont, menor;
	if(num > num2){
		menor = num2;
	}else{
		menor = num;
	}
	for(cont = 2; cont <= menor; cont++){ //começa com 2 porque 1 divide todos os números.
		if((num % cont == 0) && (num2 % cont == 0))
			return 0;
	}
	return 1;
}
