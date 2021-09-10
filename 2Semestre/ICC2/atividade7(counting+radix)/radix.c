#include <stdio.h>
#include <stdlib.h>

void radix(){

    int B, b, n, X=10, x;
    int *v, *a;

    scanf("%d", &B);
    scanf("%d", &n);

    v=malloc(n*(sizeof(int)));
    a=malloc(n*(sizeof(int)));

    for(int i=0; i<n; i++){

        scanf("%d", &v[i]);
    }

    b=B;
    x=X;

    //printf("\n");

        for(int h=0; h<33; h++){

            //int i;
            int ok=0;

            for(int i=0; i<n; i++){

                a[i]=(v[i]%B)/(B/b);
                ok++;

                //if((v[i]/(X/x))!=0){

                    //ok++;
                //}
            }

            if(ok>0){

                for(int i=0; i<n; i++){

                    int max = 0;

                    for(int j=0; j<(n-1);){

                        int cont = 0;

                        if(a[j]>a[j+1]){

                        int aux = a[j];
                        a[j]=a[j+1];
                        a[j+1]=aux;

                        aux=v[j];
                        v[j]=v[j+1];
                        v[j+1]=aux;

                        cont++;
                        }

                        if(v[j]>v[j+1])
                            max++;

                        if(cont>0)
                            j=0;
                        else
                            j++;

                    }

                    if(max==0)
                        h=33;

                    printf("%d ", v[i]);

                }
            }


            if(ok>0)
                printf("\n");

            B *= b;
            X *= x;
        }

    free(v);
    free(a);
}



int main(){

    radix();

    return 0;
}
