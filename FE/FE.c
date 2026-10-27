#include "FE.h"
#include <string.h>
#include <stdlib.h>

FilaE *criaFila(){
    FilaE *fila = (FilaE *)malloc(sizeof(FilaE));
    fila->inicio = fila->fim = 0;

    return fila;
}

int filaVazia(FilaE *f) {
    return f->inicio == f->fim ? 1 : 0;
}

void liberaFila(FilaE *f){
    free(f);
}

void enfileira(FilaE *f, char nome[50], char tipo){
    strcpy(f->v[f->fim].nome, nome);
    f->v[f->fim].tipo = tipo;
    f->fim = (f->fim + 1) % MAX_FE;
}

Pessoa desenfileira(FilaE *f){
    Pessoa x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FE;

    return x;
}
