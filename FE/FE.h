#include "info.h"
#define MAX 1000

typedef struct {
    Pessoa v[MAX];
    int inicio, fim;
} FilaE;

FilaE *criaFila();
int vazia(FilaE *f);
void push(FilaE *p, char nome[50], char tipo);
Pessoa pop(FilaE *f);
