#include "../include/main.h"

int main(){
	
	clock_t i, f;
	double cpu_time_used;
	i = clock();

	menu();

	f = clock();
	cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
	return 0;
}
