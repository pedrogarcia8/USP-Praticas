typedef struct no No;

struct no{
    int info;
    No * ant, * prox;
};

typedef struct lista{
    No * ini, * fim;
    int tam;
} Lista;

Lista * criar();
void inserir(Lista * l, int x);
void liberar(Lista * l);
void imprimir(Lista * l);
Lista * somar(Lista * l, Lista * l2);
int verificaMaior(Lista * l, Lista * l2);
int verificaMenor(Lista * l, Lista * l2);
int verificaIgual(Lista * l, Lista * l2);