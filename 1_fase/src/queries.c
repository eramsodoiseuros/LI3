#include "../include/queries.h"


///////////////////////////////////////////////////////////
// QUERY 1

void query_1(Clientes c, Produtos p, Filial f1, Faturacao f2, int num[6], int r){

	free(c);
	free(p);
	free(f1);
	free(f2);
		
	if(r == 1){
		c = iniciar_clientes(num);
	}
	
	if(r == 2){
		p = iniciar_produtos(num);
	}

	if (r == 3){
		c 	= iniciar_clientes(num);
		p 	= iniciar_produtos(num);
		// iniciar_filial(f1);
		f2 	= iniciar_faturacao();
		init_Vendas(num, p, c, f1, f2);
	}

	if(r == 4){
		c 	= iniciar_clientes(num);
		p 	= iniciar_produtos(num);
		f2 	= iniciar_faturacao();
		init_Vendas(num, p, c, f1, f2);
	}
}

///////////////////////////////////////////////////////////