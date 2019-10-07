/*EXEMPLO COM 3 PROCESSOS ELABORADO EM SALA DE AULA a=10tkts b=20tkts c=30tkts*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 3 /*Numero maximo de processos 3*/

struct process{ /*estrutura do processo*/
    int Pid;
    int tkts;
    char c;
};

char search_a_ticket(int count, struct process pross[]){/*função gera tickets, recebe 2 parametros*/
    int aux = 0, i;
    srand(time(NULL));
    aux = (rand() % (count)); /*sorteia o numero com o total de tickets definidos na leitura dos dados*/
    printf("\nO tickets sorteado foi: %d ", aux);
    for (i = 0; i < 1; i++){ /*laço apenas para verificação e retorno do intervalo do ticket sorteado*/
        if(aux <= pross[i].tkts) return pross[i].c; /*retorna 1º processo*/
        else if(aux > pross[i].tkts && aux <= pross[i+1].tkts) return pross[i+1].c; /*retorna o 2º processo*/
        else return pross[i+2].c; /*retorna 3º processo*/
    } 
    exit(-1);
}   

int main(){    
    struct process pross[MAX];   
    int count = 0, i;/*somador dos tickets definido pra passar como parametro e sanitizar o codigo*/

    for(i = 0; i < MAX; i++){/*for para ler os dados do processo*/
        printf("adicionar o char(ex: A):\n");
        scanf("%s", &pross[i].c);
        printf("Pid p/ process %d:\n", i);  
        scanf("%d", &pross[i].Pid);
        printf("quantidade de tickets pro processo:[Pid: %d, index: %d]: ",pross[i].Pid, i);
        scanf("%d", &pross[i].tkts);
        if(pross[i-1].tkts >= 0){ /*logica da soma dos tickets, processo anterior incrementado pelo atual*/
            pross[i].tkts += pross[i-1].tkts;
        }
        count = pross[i].tkts;/*
        printf("%d\n", count);
        printf("%c\n %d\n %d\n",pross[i].c, pross[i].Pid, pross[i].tkts);*/
    }
    
    char result = search_a_ticket(count, pross);     /*result recebe o retorno do processo*/
    printf("que pertence ao processo %c\n", result);
    
    return 0; 
}

