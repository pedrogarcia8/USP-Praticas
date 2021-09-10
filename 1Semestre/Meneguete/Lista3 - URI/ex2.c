#include <stdio.h>

int main(){
	unsigned long long int N, fat;
	do{
		scanf("%llu",&N);
		
		if(N < 3)
			break;
		
		for(fat = 1; N > 3; N--){
			fat = (fat * N) % 1000000009;
		}
		printf("%llu\n",(fat));	
	}while(N != 0);
	return 0;
}
