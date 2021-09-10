typedef struct no No;

struct no {
    int info;
    No * prox;
};

typedef struct lista {
    No * ini, * fim;
    int tam;
} Lista;

Lista * criar();
int inserir(Lista * l, int x);
int remover(Lista * l, int x);
void libera(Lista * l);
void imprimir(Lista * l);
int isEmpty(Lista * l);
int josefo(Lista * l, int k);

