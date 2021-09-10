typedef struct texto{
    char original[101];
    char erro[21];
    char correcao[21];
} Texto;


Texto * Create();
Texto * Realloc(Texto * t, int tam);
void Destroy(Texto * t);
int strleng(char * str);
char * strcopy(char * strCopia, char * strCopiada);
char * substituir(char * str1, char * str2, char * str3);
