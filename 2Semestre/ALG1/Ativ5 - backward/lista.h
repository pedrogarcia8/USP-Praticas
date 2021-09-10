typedef struct no No;

struct no {
  int info, tempo;
  No *ant, *prox;
};

typedef struct lista{
  No *ini, *fim;
  int tam;
} Lista;

Lista * criar();
void liberar(Lista * l);
void imprimir(Lista * l);
void inserir(Lista * l, int x, int j, int tempo);
void remover(Lista * l, int x);
