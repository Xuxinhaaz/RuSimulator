typedef struct 
{
    int info;
    No *prox;
} No;

typedef struct
{
    No *topo;
} PilhaD;

PilhaD *cria_pilha();
int vazia(PilhaD *p);   
void push(PilhaD *p, int x);
int pop(PilhaD *p);
