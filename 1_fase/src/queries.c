#include "../include/queries.h"


///////////////////////////////////////////////////////////
// QUERY 1

void query_1(Clientes c, Produtos p, int num[6], int r){

	if(r == 1){
		free(c);
		init_clientes(num,c);
	}
	
	if(r == 2){
		free(p);
		init_produtos(num,p);
	}

	if (r == 3){
		free(c);
		free(p);
		init_clientes(num,c);
		init_produtos(num,p);
	}

	if(r == 4){
		free(c);
		free(p);
		init_clientes(num,c);
		init_produtos(num,p);
	}
}

///////////////////////////////////////////////////////////