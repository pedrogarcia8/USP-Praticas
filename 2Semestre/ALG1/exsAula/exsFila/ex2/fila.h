#define TamFila 10

typedef int elem;
typedef struct fila{
    int inicio, fim, total;
    elem itens[TamFila];
}fila_t;

fila_t * criar();
int isEmpty(fila_t * f);
int isFull(fila_t * f);
int inserir(fila_t * f, elem x);
int remover(fila_t * f, elem *x);
void destroy(fila_t * f);

