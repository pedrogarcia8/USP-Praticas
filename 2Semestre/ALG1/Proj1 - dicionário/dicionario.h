typedef struct palavra{
    char verbete[51];// Armazena um verbete de até 50 caracteres
    char definicao[141];// Armazena uma definição de até 140 caracteres
} Palavra; // Estrutura para facilitar o armazenamento dos verbetes e das definições do dicionário

typedef struct no No; // Renomeando a estrutura dos nós da Skip List

struct no{
    Palavra * valor; // Ponteiro para a estrutura dos verbetes e das definições do dicionário
    int nivel; // Armazena o nível do nó na Skip List
    No * prox; // Ponteiro para o próximo nó da Skip List
    No * abaixo; // Ponteiro para o nó abaixo do nó atual da Skip List
} ;// Estrutura dos nós da Skip List

typedef struct skiplist{
    int nivel; // Armazena o maior nível atual da Skip List
    int maiorNivel; // Armazena o nível máximo que a Skip List pode ter
    No * anteriorAcima; // Ponteiro para o nó anterior acima do nó atual da Skip List
} Lista; // Estrutura da Skip List 

// Função para criar e inicializar um novo nó da Skip List
No * criarNo(char * verbete, char * definicao, int nivel, No * prox, No * abaixo);
// Função para criar e inicializar uma nova Skip List
Lista * criar();
// Função para inserir um novo nó nos níveis sorteados na Skip List
int inserir(Lista * l, char * verbete, char * definicao);
// Função para buscar um verbete na Skip List, se existir retorna a definição, caso contrário retorna "0"
char * buscar(Lista * l, char * verbete);
// Função para remover um verbete e sua definição da Skip List
int remover(Lista * l, char * verbete);
// Função para alterar a definição de um determinado verbete da Skip List
int alterar(Lista * l, char * verbete, char * definicao);
// Função que imprime a Skip List inteira, usada apenas para debugar
void imprimir(Lista * l);
// Função que imprime todos os verbetes que comecem com uma determinada letra, e suas respectivas definições, da Skip List
int imprimirPorLetra(Lista * l, char letra);
// Função para gerar níveis aleatórios para a inserção na Skip List
int gerarNiveis();
//Função para liberar a memória da Skip List
void liberar(Lista * l);




