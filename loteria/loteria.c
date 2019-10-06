#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#define N 15

unsigned int controle_escalonador = 3; //variavel que controla a randomização do escalonador

unsigned int escalonador_rand(unsigned int state) // Função de randomização
{
    state = ((unsigned int)state * 48271u) % 0x7fffffff;
    return state;
}


void processo(){
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
             printf(1, "Fork foi escolhido %d vezes!\n", N);
        }

        for(; i > 0; i--){
            wait();
        }
        exit();
}

int main(){
    processo();
    exit;
}
