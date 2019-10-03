#include <stdio.h>
#include <stdlib.h>

int main(){
    int number_process;

    printf("Entrar a quantidade de processo: ");
    scanf("%d", &number_process);

    if(number_process > 0 && number_process <= 3){

            //Implementation
    }
    else{
        printf("A quantidade de processo nao pode ultrapassar 3 nem pode ser menor do que 0");
    }

}
