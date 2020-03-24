#include "../include/queries.h"


///////////////////////////////////////////////////////////
// QUERY 1

void query_1(Clientes c, Produtos p, Filial f1, Faturacao f2, int num[6], int r){

		free(c);
		free(p);
		free(f1);
		free(f2);
		
	if(r == 1){
		init_clientes(num,c);
	}
	
	if(r == 2){
		init_produtos(num,p);
	}

	if (r == 3){
		init_clientes(num,c);
		init_produtos(num,p);
		iniciar_filial(f1);
		iniciar_faturacao(f2);
		init_Vendas(num, p, c, f1, f2);
	}

/*
	if(r == 4){
		init_clientes(num,c);
		init_produtos(num,p);
		iniciar_faturacao(f2);
	}
*/

}

///////////////////////////////////////////////////////////