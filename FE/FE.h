#define MAX 500

typedef struct {
    int v[MAX];
    int inicio, fim;
} FilaE;

FilaE *criaFila();
int vazia(FilaE *f);
void push(FilaE *p, int x);
int pop(FilaE *f);
