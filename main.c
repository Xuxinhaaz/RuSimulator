#include <stdio.h>
#include <string.h>
#include "PE/PE.h"
#include "FE/FE.h"
#include <info.h>

//imprime os tickets
void imprime(int n, int *serieTickets, char tipo, PilhaE *pAluno, PilhaE *pBolsista, PilhaE *pVisita){
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



//main
int main () {
    //comando inicial
    char command[20];
    //criação das pilhas
    PilhaE *pAluno = criaPilha();
    PilhaE *pBolsista = criaPilha();
    PilhaE *pVisita = criaPilha(); 
    //criação da fila
    FilaE *f = criaFila();
    //contage de tickets   
    int serieTickets = 0;

    while(scanf("%19s", command) == 1) {
        if(strcmp(command, "imprime") == 0){
            int n;
            char tipo;
            
            scanf("%d %c", &n, &tipo);
            imprime(n, &serieTickets, tipo, pAluno, pBolsista, pVisita);      
            //code


        } else if(strcmp(command, "chega") == 0) {
            char nome[50];
            char tipo;

            scanf("%49s %c", nome, &tipo); 
            printf("[DEBUG] chega nome=[%s] tipo=%c\n", nome, tipo);
            push(f, nome, tipo);

            if (tipo == 'A')      printf("aluno %s chegou com fome.\n", nome);
            else if (tipo == 'B') printf("bolsista %s chegou com fome.\n", nome);
            else if (tipo == 'V')             printf("visitante %s chegou com fome.\n", nome);
        } else if(strcmp(command, "proximo") == 0){
            //code




        } else if(strcmp(command, "F") == 0){
            //code

            break;
        }


    }
}

