#include <stdio.h>
#include <stdlib.h>
#include "llrb.h"

int main(){
    int n, o, x;
    allrb * a = criar();
    
    scanf("%d",&n);
    while(n > 0){
        scanf("%d",&o);
        if((o == 1) || (o == 2) || (o == 3))
            scanf("%d",&x);

        n--;
    }
    
    finalizar(a->raiz);
    return 0;
}
