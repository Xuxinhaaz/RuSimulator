#ifndef PD_H
#define PD_H

typedef struct No
{
    int info;
    struct No *prox;
} No;

typedef struct
{
    No *topo;
} PilhaD;

typedef PilhaD Pilha;

Pilha *criaPilha();
int vazia(Pilha *p);
void liberaPilha(Pilha *p);
void push(Pilha *p, int x);
int pop(Pilha *p);

#endif
