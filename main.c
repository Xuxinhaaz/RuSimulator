#include <stdio.h>
#include <string.h>
#include <info.h>
#include <PE.h>

int main () {
    char command[20];
    PilhaE *pAluno = criaPilha();
    PilhaE *pBolsista = criaPilha();
    PilhaE *pVisita = criaPilha();    
    int serieTickets = 0;

    while(scanf("%19s", command) == 1) {
        if(strcmp(command, "imprime") == 0){
            int n;
            char tipo;
            
            scanf("%d %c", &n, &tipo);
            printf("[DEBUG] imprime n=%d tipo=%c\n", n, tipo);
            //code


        } else if(strcmp(command, "chega") == 0) {
            char name[50];
            char tipo;

            scanf("%49s %c", name, &tipo); 
            printf("[DEBUG] chega name=[%s] tipo=%c\n", name, tipo);
            //code


        } else if(strcmp(command, "proximo") == 0){
            //code




        } else if(strcmp(command, "F") == 0){
            //code

            break;
        }


    }
}

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
