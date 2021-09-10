#include <stdio.h>
#include <stdlib.h>

int * countingSort(int * v, int k, int n);

int main(){
    int * aux, * p, * v, i, j, k, n;

    scanf("%d",&k);
    scanf("%d",&n);
    v = (int *) calloc(n, sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d",&v[i]);

    p = (int *) calloc(n, sizeof(int));
    aux = countingSort(v,k,n);

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(v[i] == aux[j]){
               aux[j] = -1;
               p[i] = j;
               break;
            }
        }

    }

    for(i = 0; i < n; i++)
        printf("%d %d\n",v[i],p[i]);
    return 0;
}

int * countingSort(int * v, int k, int n){
    int i, j, h, g = 0, num[k], * aux;

    aux = (int *) calloc(n, sizeof(int));

    for(j = 0;j < k; j++){
       num[j] = 0;
       for(h = 0; h < n; h++){
          if(j == v[h]){
             num[j]++;
          }
       }
    }

    for(i = 0; i < k; i++){
        h = i;
        for(j = 0; j < num[i]; j++){
            aux[g] = h;
            g++;
        }
    }

    return aux;


}
