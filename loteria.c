#include <stdio.h>
#include <stdlib.h>

int main(){
    int number_process;
    char process[5];

    printf("Entrar a quantidade de processo: ");
    scanf("%d", &number_process);

    if(number_process > 0 && number_process <= 3){
        //lendo os processo
        for(int i = 0; i< number_process; i++){
            printf("Digite o processo [%d]: ",i+1);
            scanf("%s",process);
        }
    }
    else{
        printf("A quantidade de processo nao pode ultrapassar 3 nem pode ser menor do que 0\n");
    }

}
