//Pedro José Garcia 11846943
#include <stdio.h>
#include <stdlib.h>

int main(){
	int horas,minutos,segundos;
	printf("Digite a hora: ");
	scanf("%d",&horas);
	printf("Digite os minutos: ");
	scanf("%d",&minutos);
	printf("Digite os segundos: ");
	scanf("%d",&segundos);
	segundos = (horas * 3600) + (minutos * 60) + segundos;
	horas = segundos/10000;
	minutos = (segundos % 10000)/100;
	segundos = segundos - (horas*10000) - (minutos * 100);
	printf("Hora: %d Minutos: %d Segundos %d",horas,minutos,segundos);
	
	return 0;
}
