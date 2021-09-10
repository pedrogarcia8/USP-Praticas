#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, fib[60022], cont = 1;
    unsigned long long int n;
    int b;

    fib[0] = 1;
    fib[1] = 1;

    do{
    	scanf("%llu %d", &n, &b);
		if((n == 0)&&(b == 0))
			exit(0);
		
		if((b > 10000)||(b == 0))
			break;
		
    	for(i = 2;(i <= n)&&(i <= 60001); i++)
        {	
				fib[i] = (fib[i-1] + fib[i-2] + 1) % b;	
        	
           		if((fib[i-1] == 0) && (fib[i] == 1))
            		fib[i] = fib[n % (i-1)];
       	}

        i--;

        printf("Case %d: %llu %d %.0f\n", cont, n, b, (double) fib[i]);
        	
        cont++;
    }while(1);

    return 0;
}
