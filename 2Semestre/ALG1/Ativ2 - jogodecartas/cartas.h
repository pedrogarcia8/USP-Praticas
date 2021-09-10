typedef struct pilha_cartas {
    int topo;
    int * cartas;
} PilhaCartas;

PilhaCartas * Create(int tam);
void Destroy(PilhaCartas * pc);
void Push(PilhaCartas * pc, int carta);
void Pop(PilhaCartas * pc);
