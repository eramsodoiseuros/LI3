#include "../include/queries.h"
#include "../include/AVL.h"

///////////////////////////////////////////////////////////
// QUERY 1

void query_1(Clientes* c, Produtos* p, Filial* f1, Faturacao* f2, int num[6], int r){

	free_clientes(*c);
	free_produtos(*p);

		
	if(r == 1){
		*c = iniciar_clientes(num);
	}
	
	if(r == 2){
		*p = iniciar_produtos(num);
	}

	if (r == 3){
		*c 	= iniciar_clientes(num);
		*p 	= iniciar_produtos(num);
		// iniciar_filial(f1);
		*f2 	= iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2);
	}

	if(r == 4){
		*c 	= iniciar_clientes(num);
		*p 	= iniciar_produtos(num);
		*f2 	= iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2);
	}
}

///////////////////////////////////////////////////////////
// QUERY 2

void query_2(Produtos* p, char letra){

	printf("ENTROU 2\n");
	int tamanho = get_size(*p,letra);

	printf("DEU TAMANHO _%d_\n", tamanho);
	String lista[tamanho];

	for(int i = 0; i < tamanho; i++){
		lista[i] = NULL;
	}

	printf("vai entrar na lista\n");
	lista_produtos(*p, letra, lista);

	navegador(lista, tamanho);
}