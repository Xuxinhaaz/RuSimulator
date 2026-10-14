#include<FE.h>

FilaE *criaFila(){
    FilaE *fila = (FilaE *)malloc(sizeof(FilaE));   
    fila->inicio = fila->fim = 0;
}

int vazia(FilaE *f) {
    return f->inicio == f->fim ? 1 : 0;
}

void push(FilaE *f, int x){
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % MAX;
}

int pop(FilaE *f){
    inx x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;

    return x;
}