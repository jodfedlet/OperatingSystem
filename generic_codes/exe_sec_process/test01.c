/*EXEMPLO COM 2 PROCESSOS*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 2 /*numero maximo de processos*/
int i; /*variavel global do for*/

struct process{ /*estrutura do processo*/
    int pid;
    int tickets_each_process;
    char c;
};

char search_a_ticket(int count, struct process pross[]){ /*função de gerar tickets, recebe 2 parametros*/
    int aux = 0;    /*param-> count contador com tamanho dos tickets e um vetor process[] ->*/
    srand(time(NULL));
    aux = rand() % (count); /*variavel aux recebe o sorteio de um numero aleatorio até (max tickets == count)*/
    printf("\nO tickets sorteado foi: %d ", aux); 
    for (i = 0; i < 1; i++){ /*um de repetição p/ descobrir a relação do intervalo do ticket sorteado*/
        if(aux <= pross[i].tickets_each_process) return pross[i].c; /*retorna o nome do primeiro processo(A) definido por um char e intervalo de 0 até 60 tickets*/
        else if(aux > pross[i].tickets_each_process && aux <= pross[i+1].tickets_each_process) return pross[i+1].c; /*retorna o nome do segundo(B) processo intervalo de 60 até 100 tickets*/
    } 

    exit(-1); /*interrompe se não entrar no for*/
}   

int main(){    
    struct process pross[MAX];   
    int count = 0; /*somador dos tickets definido p/ passaar como parametro e sanitizar o codigo*/
      for(i = 0; i < MAX; i++){ /*laço de repetição p/ ler os dados do processo*/
        printf("adicionar o char:\n");
        scanf("%s", &pross[i].c);
        printf("Pid p/ process %d:\n", i);  
        scanf("%d", &pross[i].pid);
        printf("quantidade de tickets pro processo:[Pid: %d, index: %d]: ",pross[i].pid, i);
        scanf("%d", &pross[i].tickets_each_process);
        if(pross[i-1].tickets_each_process >= 0){/* logica da soma dos tickets, processo anterior incrementado pelo atual*/
            pross[i].tickets_each_process += pross[i-1].tickets_each_process;
        }
        count = pross[i].tickets_each_process;
 /*       printf("%c\n %d\n %d\n",pross[i].c, pross[i].pid, pross[i].tickets_each_process);
        printf("%d", count);

*/       }
       char result = search_a_ticket(count, pross);/*  result recebe o retorno do processo */  
       printf("que pertence ao processo %c\n", result); /*mostra o processo e encerra*/
    return 1; 
}
