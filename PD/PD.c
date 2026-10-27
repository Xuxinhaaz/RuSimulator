#include "PD.h"
#include <stdlib.h>

PilhaD *criaPilha(){
    PilhaD *p = (PilhaD *)malloc(sizeof(PilhaD));
    p->topo = NULL;

    return p;
}

int vazia(PilhaD *p){
    return p->topo == NULL ? 1 : 0;
}

void liberaPilha(PilhaD *p){
    while(!vazia(p)){
        pop(p);
    }
    free(p);
}

void push(PilhaD *p, int x){
    No *novo = (No *)malloc(sizeof(No));

    novo->info = x;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(PilhaD *p) {
    int x = p->topo->info;
    No *aux = p->topo->prox;

    free(p->topo);

    p->topo = aux;
    return x;
}
