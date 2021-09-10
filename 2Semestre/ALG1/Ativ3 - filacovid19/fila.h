typedef struct pessoas{
   char nome[101];
   int idade;
   int condicao;
} Pessoa;

typedef struct fila{
    int inicio, fim, total;
    Pessoa * pessoas;
}Fila;

Fila * criar(int N);
int isEmpty(Fila * f);
int isFull(Fila * f, int TamFila);
void inserir(Fila * f, Pessoa * x, int TamFila);
Pessoa * remover(Fila * f,int TamFila);
void destroy(Fila * f);

