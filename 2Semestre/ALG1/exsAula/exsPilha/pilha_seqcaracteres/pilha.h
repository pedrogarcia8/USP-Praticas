typedef struct pilha{
    int topo;
    char * caracteres;
}Pilha;

Pilha * Create();
void Destroy(Pilha * p);
void Push(Pilha * p, char c);

