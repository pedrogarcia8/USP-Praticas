#define RED 1
#define BLACK 0

typedef struct no No;

struct no {
    int info;
    No * esq, * dir;
    int cor;
};

typedef struct arvore{
    No * raiz;
} allrb;

allrb * criar();
void finalizar(No * raiz);
void imprimir(No * raiz);
void pre_ordem(No * raiz);
void em_ordem(No * raiz);
void pos_ordem(No * raiz);
No * busca(No * raiz, int x);


