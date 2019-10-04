#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct process{
    int *pid;
    int tickets_each_process;
};

int main(){    
    struct process pross;
    int i, n, *tmp, count = 0;
    scanf("%d", &n);
    tmp = (int *)malloc(n * sizeof(int));
    if(n > 0 && n <= MAX && tmp){
        pross.pid = tmp; 
        for(i = 0; i < n && n <= MAX; i++){
            printf("Pid p/ process %d\n", i);  
            scanf("%d", &pross.pid[i]);
            printf("quantidade de tickets pro processo:[Pid: %d]: ",i);
            scanf("%d", &pross.tickets_each_process);

/*            printf("Entre a quantidade de bilhete do processo %s: ", process);
            scanf("%d", &tickets_each_process);
            if(process[i].tickets_each_process >= process[i+1].tickets_each_process)
        }*/
       }
       for (i = 0; i < tmp; i++){
           count += pross.tickets_each_process;
       }
       printf("count: %d\n", count);
    }
    else{
        printf("A quantidade de processo nao pode ultrapassar 3 nem pode ser menor do que 0\n");
    }

}
