typedef struct fila{
    int inicio, fim, total;
    char * pessoas[100];
}Fila;

Fila * Create();
int IsEmpty(Fila * f);
int IsFull(Fila * f);
int Insert(Fila * f, char * x);
int Remove(Fila * f, char * x);
void Destroy(Fila * f);
