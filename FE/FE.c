#include "FE.h"
#include <string.h>

FilaE *criaFila(){
    FilaE *fila = (FilaE *)malloc(sizeof(FilaE));   
    fila->inicio = fila->fim = 0;

    return fila;
}

int vazia(FilaE *f) {
    return f->inicio == f->fim ? 1 : 0;
}

void push(FilaE *f, char nome[50], char tipo){
    strcpy(f->v[f->fim].nome, nome);
    f->v[f->fim].tipo = tipo;
    f->fim = (f->inicio + 1) % MAX;
}

Pessoa pop(FilaE *f){
    Pessoa x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;

    return x;
}