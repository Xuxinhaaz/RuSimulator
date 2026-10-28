#ifndef FE_H
#define FE_H

#include "../info.h"
#define MAX_FE 1000

typedef struct {
    Pessoa v[MAX_FE];
    int inicio, fim;
} FilaE;

typedef FilaE Fila;

Fila *criaFila();
int filaVazia(Fila *f);
void liberaFila(Fila *f);
void enfileira(Fila *f, Pessoa x);
Pessoa desenfileira(Fila *f);

#endif