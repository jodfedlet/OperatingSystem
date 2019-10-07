#include <stdio.h>
#include <stdlib.h>

int search_a_ticket(int x){
	srand(time(NULL));
	int aux = rand() % (100);

	printf("O aleatório gerado foi: %d \n", aux);
	
	if(aux <= 60){
		printf("1 escolhido\n");
	}
	else {
		printf("2 escolhido\n");
	}
}

int main(int argc, char const *argv[])
{
	printf("teste\n");
	int a = search_a_ticket(1);
	return 0;
}