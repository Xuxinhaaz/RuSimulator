#include <stdio.h>
#include <string.h>
#include "info.h"
#include "PE/PE.h"  
#include "FE/FE.h"  

//precos em centavos
#define PRECO_A 350
#define PRECO_B 0
#define PRECO_V 1016
#define CUSTO_REFEICAO 1016

//imprime os tickets
void imprime(int n, int *serieTickets, char tipo, Pilha *pAluno, Pilha *pBolsista, Pilha *pVisita){
    int inicio = *serieTickets + 1;

    for(int i = 0; i < n; i++){
        (*serieTickets)++;

        switch (tipo) {
            case 'A': push(pAluno, *serieTickets); break;
            case 'B': push(pBolsista, *serieTickets); break;
            case 'V': push(pVisita, *serieTickets); break;
        }
    }

    printf("tickets #%d a #%d impressos.\n", inicio, *serieTickets);
}

//atende a proxima pessoa da fila
void proximo(Fila *f, int *serieTickets, int *totalPago, int *totalSubsidio, Pilha *pAluno, Pilha *pBolsista, Pilha *pVisita){
    if(filaVazia(f)){
        printf("ninguem na fila\n");
        return;
    }

    Pessoa p = desenfileira(f);
    Pilha *pilha = pAluno;
    int preco = PRECO_A;

    //escolhe a pilha e o preco de acordo com o tipo da pessoa
    switch (p.tipo) {
        case 'A': pilha = pAluno;    preco = PRECO_A; break;
        case 'B': pilha = pBolsista; preco = PRECO_B; break;
        case 'V': pilha = pVisita;   preco = PRECO_V; break;
    }

    int ticket;

    if(vazia(pilha)){
        //pilha vazia: imprime um ticket avulso na hora
        (*serieTickets)++;
        ticket = *serieTickets;
        printf("ticket #%d impresso.\n", ticket);
    } else {
        ticket = pop(pilha);
    }

    *totalPago += preco;
    *totalSubsidio += CUSTO_REFEICAO - preco;

    printf("%s comprou ticket #%d por R$ %d.%02d.\n", p.nome, ticket, preco / 100, preco % 100);
}
 
//conta recursivamente quantos tickets sobraram (esvazia a pilha)
int contaTickets(Pilha *p){
    if(vazia(p)){
        return 0;
    }

    pop(p);
    return 1 + contaTickets(p);
}
 
//finaliza a simulacao: imprime o resumo e libera a memoria
void finaliza(int totalPago, int totalSubsidio, Fila *f, Pilha *pAluno, Pilha *pBolsista, Pilha *pVisita){
    int tA = contaTickets(pAluno);
    int tB = contaTickets(pBolsista);
    int tV = contaTickets(pVisita);

    //libera a memoria das pilhas
    liberaPilha(pAluno);
    liberaPilha(pBolsista);
    liberaPilha(pVisita);

    printf("===\n");
    printf("Total recebido de usuarios: R$ %d.%02d\n", totalPago / 100, totalPago % 100);
    printf("Total do subsidio da universidade: R$ %d.%02d\n", totalSubsidio / 100, totalSubsidio % 100);
    printf("===\n");
    printf("Sobraram %d tickets de alunos.\n", tA);
    printf("Sobraram %d tickets de bolsistas.\n", tB);
    printf("Sobraram %d tickets de visitantes.\n", tV);

    liberaFila(f);
}

//main
int main () {
    //comando inicial
    char command[20];

    //criação das pilhas
    Pilha *pAluno = criaPilha();
    Pilha *pBolsista = criaPilha();
    Pilha *pVisita = criaPilha();

    //criação da fila
    Fila *f = criaFila();

    //contage de tickets
    int serieTickets = 0;

    //totais em centavos
    int totalPago = 0;
    int totalSubsidio = 0;

    while(scanf("%19s", command) == 1) {
        if(strcmp(command, "imprime") == 0){
            int n;
            char tipo;

            scanf("%d %c", &n, &tipo);

            imprime(n, &serieTickets, tipo, pAluno, pBolsista, pVisita);

        } else if(strcmp(command, "chega") == 0) {
            char nome[50];
            char tipo;

            scanf("%49s %c", nome, &tipo);

            enfileira(f, nome, tipo);

            if (tipo == 'A') printf("aluno %s chegou com fome.\n", nome);
            else if (tipo == 'B') printf("bolsista %s chegou com fome.\n", nome);
            else if (tipo == 'V') printf("visitante %s chegou com fome.\n", nome);

        } else if(strcmp(command, "proximo") == 0){
            proximo(f, &serieTickets, &totalPago, &totalSubsidio, pAluno, pBolsista, pVisita);

        } else if(strcmp(command, "F") == 0){
            finaliza(totalPago, totalSubsidio, f, pAluno, pBolsista, pVisita);
            break;
        }
    }
    return 0;
}

