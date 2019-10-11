#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#define number_process 10 /*definindo a quantidade de processos*/

unsigned int lcg = 3; /*variável do controle de randomização*/
unsigned int lcg_lotttery_random(unsigned int state){ /*função para gerar um número
 aleatório que tem um unsigned int como parametro*/
  return ((unsigned int)state *48271u) % 0x7fffffff; /*gera um número aleatório*/
  /*retorna*/
}

void test_fork(void){
	int i, pid;
	printf(1, "Executando os testes\n");
	for(i = 0; i < number_process; i++){ /*laço até quantidade de processos
	 										de processos defenido*/
		lcg = lcg_lotttery_random(lcg) % 100; /*sorteia um bilhete*/
		pid = fork(lcg); /*gera pid da thread como id*/
		if(pid < 0) break; 
		else if(pid == 0) for(;;);
	}

	if (i == number_process){
		printf(1, "Fork foi chamado %d vezes.\n", number_process);
	}	
	for(; i < 0; i--){
		wait(); 
	}
	exit();
}


int main(int argc, char const *argv[]){
	test_fork(); /*chamada da função craida*/
	exit();
}