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
		c = iniciar_clientes(num);
		printf("estou a entrar na clientes\n");
		
		p = iniciar_produtos(num);
		printf("estou a entrar na produtos\n");
		// iniciar_filial(f1);
		printf("estou a entrar na faturacao\n");
		//f2 = iniciar_faturacao();
		printf("estou a entrar nas vendas\n");
		init_Vendas(num, p, c, f1, f2);
	}

/*
	if(r == 4){
		init_clientes(num,c);
		init_produtos(num,p);
		iniciar_faturacao(f2);
	}
*/
	printf("estou a sair da Q1\n");

}

///////////////////////////////////////////////////////////