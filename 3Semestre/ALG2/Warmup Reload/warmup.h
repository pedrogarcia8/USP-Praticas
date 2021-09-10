typedef struct aluno{
    int nUSP;
    char nomeCompleto[50];
    char curso[50];
    float nota;
} Aluno;

Aluno * Criar(); // Função para criar a estrutura

FILE * AbrirArquivo(char * nomeArquivo, char * tipoAbertura); // Função para abrir um arquivo
void ExibirRegistros(Aluno * alunos, int limite); // Função para exibir os registros
void EscreverRegistrosArquivo(Aluno * alunos, int tamanho); // Função para escrever os registros no arquivo binário
void LerUltimosDezRegistros(Aluno * alunos, char * nomeArquivo); // Função para pegar os últimos 10 registros de um arquivo binário
