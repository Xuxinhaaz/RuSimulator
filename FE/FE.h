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
int filaVazia(Fila *f); // f é um ponteiro para a fila
void liberaFila(Fila *f);
void enfileira(Fila *f, Pessoa x); //x é a Pessoa a ser inserida (ou, em desenfileira, a pessoa removida)
Pessoa desenfileira(Fila *f);

#endif