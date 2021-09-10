#include <stdio.h>
#include <stdlib.h>

/*

SSC0503 - ICC II
Atividade Avaliativa 02

Grupo 08

Alunos:
Kalilo Teixeira
Lucas Carneiro
Pedro Garcia

*/

typedef struct{
    int nElements, *elements;
} array;

int controleComp = 0, controleTroca = 0;

void scanArrayElements(array *arrayX, array *arrayXCopy);
void freeArrayOfArrays(array *arrayOfArrays, int q);
void insertion(int v[], int n);
void merge(int v[], int c, int f, int contComp, int contTroca);
void intercala(int v[], int c1, int f1, int c2, int f2, int contComp, int contTroca);

int main()
{
    int q, n, i;
    int *contComp, *contTroca;
    array *arrayOfArrays, *arrayOfArraysCopy;

    // Defini a quantidade de Vetores
    scanf("%d", &q);
    arrayOfArrays = malloc(q * sizeof(array));
    arrayOfArraysCopy = malloc(q * sizeof(array));

    contComp = (int *) calloc(q, sizeof(int));
    contTroca = (int *) calloc(q, sizeof(int));

    // Defini o tamanho de cada Vetor
    for (i = 0; i < q; i++)
    {
        scanf("%d", &n);
        arrayOfArrays[i].nElements = n;
        arrayOfArraysCopy[i].nElements = n;
    }

    // Chama a funcao para cada Vetor
    for (i = 0; i < q; i++)
        scanArrayElements(&arrayOfArrays[i], &arrayOfArraysCopy[i]);

    for (i = 0; i < q; i++)
    {
        merge(arrayOfArrays[i].elements, 0, arrayOfArrays[i].nElements - 1, contComp[i], contTroca[i]);

        contComp[i] = controleComp;
        contTroca[i] = 2 * controleTroca; // Multiplica por 2, porque o merge para ordernar se divide em 2.
        controleComp = 0;
        controleTroca = 0;
    }

    for (i = 0; i < q; i++){
        insertion(arrayOfArraysCopy[i].elements, arrayOfArraysCopy[i].nElements);
        printf("M %d %d %d\n",arrayOfArrays[i].nElements, contTroca[i], contComp[i]);
    }


    free(contComp);
    free(contTroca);
    freeArrayOfArrays(arrayOfArrays, q);
    freeArrayOfArrays(arrayOfArraysCopy, q);

    return 0;
}

void scanArrayElements(array *arrayX, array *arrayXCopy)
{
    int number;
    // Aloca espaço para o vetor de elementos
    arrayX->elements = malloc(arrayX->nElements * sizeof(int));
    arrayXCopy->elements = malloc(arrayX->nElements * sizeof(int));

    // Ler um inteiro para cada posição do vetor
    for (int i = 0; i < arrayX->nElements; i++)
    {
        scanf("%d", &number);
        arrayX->elements[i] = number;
        arrayXCopy->elements[i] = number;
    }
}

void freeArrayOfArrays(array *arrayOfArrays, int q)
{
    // Desaloca todos os Vetores elementos do vetor de vetores.
    for (int i = 0; i < q; i++)
        free(arrayOfArrays[i].elements);

    // Desaloca o espaço de arrayOfArrays
    free(arrayOfArrays);
}

void insertion(int v[], int n){
    int troca = 0, comp = 0, x = 0, j = 0, i;
    for(i = 1; i < n; i++){
        x = v[i];
        j = i - 1;
        troca++;
        while((j >= 0) && (v[j] > x)){
            comp++;
            troca++;
            v[j + 1] = v[j];
            j--;
        }
        if((v[j] <= x) && (j >= 0))
            comp++;
        troca++;
        v[j + 1] = x;
    }
    printf("I %d %d %d\n",n,troca,comp);
}

void intercala(int v[], int c1, int f1, int c2, int f2, int contComp, int contTroca)
{
    int len = (f1 - c1 + 1) + (f2 - c2 + 1);
    int a[len];
    int i1 = c1;
    int i2 = c2;
    int k = 0;
    while (i1 <= f1 && i2 <= f2)
    {
        contComp++; //conta as comparações
        if (v[i1] <= v[i2])
        {
            a[k++] = v[i1++];
            contTroca++; // conta as trocas
        }
        else
        {
            a[k++] = v[i2++];
            contTroca++; // conta as trocas
        }
    }

    while (i1 <= f1)
    {
        a[k++] = v[i1++];
        contTroca++; // conta as trocas
    }

    while (i2 <= f2)
    {
        a[k++] = v[i2++];
        contTroca++; // conta as trocas
    }

    k = 0;
    for (int i = c1; i <= f2; i++, k++)
        v[i] = a[k];

    controleComp += contComp;   // atribui a variável global a cada chamada de função
    controleTroca += contTroca; // atribui a variável global a cada chamada de função
}

void merge(int v[], int c, int f, int contComp, int contTroca)
{
    if (f > c)
    {
        int m = (c + f) / 2;
        merge(v, c, m, contComp, contTroca);
        merge(v, m + 1, f, contComp, contTroca);
        intercala(v, c, m, m + 1, f, contComp, contTroca);
    }
}
