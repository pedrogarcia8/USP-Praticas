typedef struct no No;

struct no {
    No * esq, * dir;
    int info;
};

typedef struct arvore{
    No * raiz;
} Arvore;

Arvore * criar();
int esta_vazia(Arvore * a);
void finalizar(No * raiz);
void imprimir(No * raiz);
void imprimirInfos(No * raiz, No * raizInicial);
int altura(No * raiz);
No * busca(No * raiz, int x);
No * busca_pai(No * raiz, int x);
int inserir_esq(Arvore * a, int x, int pai);
int inserir_dir(Arvore * a, int x, int pai);
int grau(No * n);
char * tipo(No * n, No * pai);


