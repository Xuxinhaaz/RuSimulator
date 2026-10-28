#include "FD.h"
#include <stdlib.h>

FilaD *criaFila() {
    FilaD *fila = (FilaD *)malloc(sizeof(FilaD));
    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

int filaVazia(FilaD *fila) {
    return fila->inicio == NULL;
}

void enfileira(FilaD *fila, Pessoa info) {
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));

    if (novo == NULL) {
        return;
    }

    novo->info = info;
    novo->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

Pessoa desenfileira(FilaD *fila) {
    Pessoa info = {{0}, 0};

    if (filaVazia(fila)) {
        return info;
    }

    NoFila *removido = fila->inicio;
    info = removido->info;

    fila->inicio = removido->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);

    return info;
}

void liberaFila(FilaD *fila) {
    while (!filaVazia(fila)) {
        NoFila *removido = fila->inicio;
        fila->inicio = removido->prox;
        free(removido);
    }

    free(fila);
}