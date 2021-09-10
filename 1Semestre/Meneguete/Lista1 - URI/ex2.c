#include <stdio.h>

int main(){
	int X,cont=0;
	scanf("%d",&X);
	system("cls");
	if(X % 2 == 0)
		X = X + 1;
	for(cont = 0;cont<6;cont++){
		printf("%d\n",X);
		X = X + 2;
	}	
	
	return 0;
}
