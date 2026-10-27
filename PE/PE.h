#ifndef PE_H
#define PE_H

#define MAX_PE 500

typedef struct
{
    int v[MAX_PE];
    int topo;
} PilhaE;

typedef PilhaE Pilha;

Pilha *criaPilha();
int vazia(Pilha *p);
void liberaPilha(Pilha *p);
void push(Pilha *p, int x);
int pop(Pilha *p);

#endif
