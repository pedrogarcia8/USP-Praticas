#define VERMELHO 1 // Define a cor vermelha como 1
#define PRETO 0 // Define a cor preta como 0

typedef struct no No;

struct no {
    int info; // Chave (valor) do nó
    No * esq, * dir; // Ponteiros para os filho esq -> esquerdo e dir -> direito
    int cor; // Cor da aresta
}; // Estrutura dos nós da rubronegra

typedef struct arvore{
    No * raiz; // Ponteiro para a raiz da rubronegra
} rubronegra; // Estrutura da rubronegra

rubronegra * criar(); // Função para criar a rubronegra
void finalizar(No * raiz); // Função para liberar a memória da rubronegra

void imprimir(No * raiz); // Função para imprimir a rubronegra na forma atual
void pre_ordem(No * raiz); // Função para imprimir a rubronegra na forma pre ordem
void em_ordem(No * raiz); // Função para imprimir a rubronegra na forma em ordem
void pos_ordem(No * raiz); // Função para imprimir a rubronegra na forma pos ordem

void predecessor(No * raiz, int x); // Função para achar o predecessor de um nó na rubronegra
void sucessor(No * raiz, int x); // Função para achar o sucessor de um nó na rubronegra

int min(No * raiz); // Função para achar o nó com a menor chave na rubronegra
int max(No * raiz); // Função para achar o nó com a maior chave na rubronegra

void inserir(rubronegra * a, int x); // Função para inserir uma chave na rubronegra

