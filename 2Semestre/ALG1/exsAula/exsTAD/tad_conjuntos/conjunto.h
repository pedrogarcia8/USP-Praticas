# define N 100

typedef struct conjunto{
    int con[N];
    int tam;
} Conjunto;

Conjunto * Criar_conjunto();
void Inserir(Conjunto * c, int num);
Conjunto * Membro(Conjunto * c, int num);
void Remover(Conjunto * c, int num);
void Imprimir(Conjunto * c);
Conjunto * Min(Conjunto * c);
Conjunto * Max(Conjunto * c);
void Liberar(Conjunto * c);
Conjunto * Igual(Conjunto * c, Conjunto * a);
Conjunto * Uniao(Conjunto * c, Conjunto * a,Conjunto * u);
Conjunto * Interseccao(Conjunto * c, Conjunto * a,Conjunto * i);
Conjunto * Diferenca(Conjunto * c, Conjunto * a,Conjunto * d);
Conjunto * Atribuir(Conjunto * c, Conjunto * a);
int Tamanho(Conjunto * c);
