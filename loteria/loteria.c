#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

unsigned int controle_escalonador = 3; //variavel que controla a randomização do escalonador

unsigned int escalonador_rand(unsigned int state) // Função de randomização
{
    state = ((unsigned int)state * 48271u) % 0x7fffffff;
    return state;
}


void processo(int N){
    int i, pid;
        for(i = 0; i< N; i++){
           controle_escalonador = escalonador_rand(controle_escalonador) % 100;
           pid = fork(controle_escalonador);
           if (pid < 0)break;
           if (pid == 0){
               for (;;);               
           }
        }

        if(i == N){
             printf(1, "Fork foi chamado %d vezes!\n", N);
        }

        for(; i > 0; i--){
            wait();
        }
        exit();
}

int main(){
    int number_process; //Quantidade de processo

    printf("Entrar a quantidade de processo: ");
    scanf("%d", &number_process);

    if(number_process > 0 && number_process <= 3){
        processo(number_process);
    }
    else{
        printf("A quantidade de processo nao pode ultrapassar 3 nem pode ser menor do que 0\n");
    }

}
