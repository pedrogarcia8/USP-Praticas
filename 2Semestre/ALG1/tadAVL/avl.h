typedef struct no No;

struct no {
    No * esq, * dir;
    int fb;
    int info;
};

typedef struct arvore{
    No * raiz;
} avl;

avl * criar();
int esta_vazia(avl * a);
void finalizar(No * raiz);
void imprimir(No * raiz);
int altura(No * raiz);
void pre_ordem(No * raiz);
void em_ordem(No * raiz);
void pos_ordem(No * raiz);
No * busca(No * raiz, int x);
void inserir(avl * a, int x);
void remover(avl * a, int x);
