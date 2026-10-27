#include "PE.h"
#include <stdio.h>
#include <stdlib.h>

PilhaE *criaPilha(){
    PilhaE *p = (PilhaE *)malloc(sizeof(PilhaE));
    p->topo = -1;

    return p;
}

int vazia(PilhaE *p){
    return p->topo == -1 ? 1 : 0;
}

void liberaPilha(PilhaE *p){
    free(p);
}

void push(PilhaE *p, int x) {
    p->topo++;
    p->v[p->topo] = x;
}

int pop(PilhaE *p){
    int x = p->v[p->topo];
    p->topo--;

    return x;
}