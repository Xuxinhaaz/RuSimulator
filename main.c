#include <stdio.h>
#include <string.h>


int main () {
    char command[20];
    
    while(scanf("%19s", command) == 1) {
        if(strcmp(command, "imprime") == 0){
            int n;
            char type;
            
            scanf("%d %c", &n, &type);
            printf("[DEBUG] imprime n=%d tipo=%c\n", n, type);
            //code


        } else if(strcmp(command, "chega") == 0) {
            char name[50];
            char type;

            scanf("%49s %c", name, &type); 
            printf("[DEBUG] chega name=[%s] type=%c\n", name, type);
            //code


        } else if(strcmp(command, "proximo")){
            //code




        } else if(strcmp(command, "F")){
            //code

        }


    }
}


