#ifndef FD_H
#define FD_H

#include "../info.h"

typedef struct noFila {
    Pessoa info;
    struct noFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} FilaD;

typedef FilaD Fila; //nome generico usado no main

Fila *criaFila();
int filaVazia(Fila *f);
void liberaFila(Fila *f);
void enfileira(Fila *f, Pessoa x);
Pessoa desenfileira(Fila *f);

#endif