typedef struct aluno{
    int nUSP;
    char nome[50];
    char sobrenome[50];
    char curso[50];
    float nota;
} Aluno;

typedef struct indice{
    int nUSP;
    int deslocamento;
} Indice;

Aluno * Criar(); // Função para criar a estrutura
Indice * CriarIndice(); // Função para criar a estrutura de índices
void criarArquivos(); // Função para criar e limpar os arquivos

FILE * AbrirArquivo(char * nomeArquivo, char * tipoAbertura); // Função para abrir um arquivo
void ExibirRegistros(Aluno * alunos, int limite); // Função para exibir os registros

void EscreverRegistrosArquivo(Aluno * aluno); // Função para escrever os registros no arquivo binário
void inserirIndiceOrdenado(int nUSP, int deslocamento); // Função para inserir os índices de forma ordenada no arquivo

int Buscar(int nUSP); // Função para buscar uma chave primária no arquivo de índices
void BuscarRegistro(int nUSP); //Função para buscar um registro no arquivo de registros

void remover(int nUSP); // Função para fazer a remoção lógica de um registro
