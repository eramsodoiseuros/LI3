#include "../include/main.h"

int main(){
	
	clock_t i, f;
	double cpu_time_used;
	i = clock();
	
	
	Clientes c 		= NULL;
	Produtos p 		= NULL;
	Filial f1 		= NULL;
	Faturacao f2 	= NULL;

	menu(&c,&p,&f1,&f2);

	f = clock();
	cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
	return 0;
}
