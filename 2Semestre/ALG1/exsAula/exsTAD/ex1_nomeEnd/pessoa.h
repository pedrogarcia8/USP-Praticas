typedef struct pessoas{
	char * nome;
	char * end;
} Pessoa;

Pessoa * criar(char * nome, char * end);

int excluir(char * nome);

char * buscar(char * nome);

