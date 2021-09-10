typedef struct aluno{
    int nUSP;
    char nomeCompleto[50];
    char curso[50];
    float nota;
} Aluno;


Aluno * Criar(); // Função para criar a estrutura

void PegarTodosRegistros(Aluno * alunos, char * nomeArquivo); // Função para ler todos os registros de um arquivo 
void PegarRegistrosDoInicioAoMeio(Aluno * alunos, char * nomeArquivo); // Função para ler os registros do começo até o meio de um arquivo
void PegarRegistrosDoMeioAoFim(Aluno * alunos, char * nomeArquivo); // Função para ler os registros do meio até o fim de um arquivo

// Função para ler os registros de uma faixa
void PegarRegistrosEmFaixa(Aluno * alunos, char * nomeArquivo, int inicioFaixa, int fimFaixa); 
void PegarRegistroPosicao(Aluno * alunos, char * nomeArquivo, int posicaoRegistro);// Função para ler o registro de uma posição

FILE * AbrirArquivo(char * nomeArquivo); // Função para abrir um arquivo
void ExibirRegistros(Aluno * alunos, int limite); // Função para exibir os registros