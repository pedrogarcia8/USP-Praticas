#include <stdio.h>
 
int quant_chamadas(long long n, int b);
 
int main(){
    long long n;
    int b, quant, cont = 0;
 
    do{
        scanf("%lld %d",&n,&b);
        if((n == 0) && (b == 0))
        	break;
        quant = ((2 * quant_chamadas(n + 1, b)) - 1 + b) % b;
        printf("Case %d: %lld %d %.0f\n", ++cont, n, b,(double) quant);
    }while(1);
 
    return 0;
}

int quant_chamadas(long long n, int b){
	
    long long e, f, g, h, i;
    
    e = 1, f = 0, g = 0, h = 1;
    
    if (n <= 0) 
        return 0;
    
    n--;
 
    while (n > 0){
    	
        if (n % 2 == 1){	
        	i = ((h * f) + (g * e)) % b;
            f = (h * (f + e) + (g * f)) % b; 
            e = i; 
        }
 
        i = ((g * g) + (h * h)) % b;
        h = (h * ((2 * g) + h)) % b;
        g = i; 
 
        n = n / 2;
    }
 
    return (e + f) % b;
}
