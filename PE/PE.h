#define MAX 500

typedef struct 
{
    int v[MAX];
    int topo;
} PilhaE;

PilhaE *criaPilha();
void liberaPilha(PilhaE);
void push(PilhaE *p, int x);
int pop(PilhaE *p);


