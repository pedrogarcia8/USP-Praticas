//Pedro Jos� Garcia 11846943
#include <stdio.h>

int main(){
	float comprimentoEstrada, custoCombustivel, distanciaPedagios, valorPedagio, custoViagem;
	int numPedagios;
	
	printf("Digite o comprimento da estrada em Km: ");
	scanf("%f",&comprimentoEstrada);
	
	printf("Digite o custo do combustivel por Km percorrido: ");
	scanf("%f",&custoCombustivel);
	
	printf("Digite a distancia entre pedagios: ");
	scanf("%f",&distanciaPedagios);
	
	printf("Digite o valor de cada pedagio: ");
	scanf("%f",&valorPedagio);
	
	if(distanciaPedagios == 0)
		numPedagios = comprimentoEstrada - 1;
		//se a distancia entre os ped�gios for 0, o n�mero de ped�gios ser� o comprimento da estrada -1, hava vista que no come�o da estrada n�o existe ped�gio, segundo o enunciado.
	else
		numPedagios = (comprimentoEstrada/distanciaPedagios);
	
	custoViagem = (numPedagios * valorPedagio) + (comprimentoEstrada * custoCombustivel);
	
	printf("O valor da viagem e %.2f",custoViagem);
	
	return 0;
	
}
