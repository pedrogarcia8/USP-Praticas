typedef struct no No;

struct no {
    int info; // Chave (valor) do nó
    No * esq, * dir; // Ponteiros para os filho esq -> esquerdo e dir -> direito
    int p; // Prioridade do nó
}; // Estrutura dos nós da treap

typedef struct arvore{
    No * raiz; // Ponteiro para a raiz da treap
} treap; // Estrutura da treap

treap * criar(); // Função para criar a treap
void finalizar(No * raiz); // Função para liberar a memória da treap

void imprimir(No * raiz); // Função para imprimir a treap na forma atual
void pre_ordem(No * raiz); // Função para imprimir a treap na forma pre ordem
void em_ordem(No * raiz); // Função para imprimir a treap na forma em ordem
void pos_ordem(No * raiz); // Função para imprimir a treap na forma pos ordem
void largura(No * raiz, int nivel); // Função para imprimir a treap na forma dos níveis

No * busca(No * raiz, int x); // Função para buscar o nó de uma chave na treap
void inserir(treap * a, int x, int p); // Função para inserir uma chave de acordo com sua prioridade na treap
void remover(treap * a, int x);// Função para remover uma chave da treap
int altura(No * raiz); // Função para pegar a altura da treap
