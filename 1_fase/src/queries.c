#include "../include/queries.h"
#include "../include/AVL.h"

///////////////////////////////////////////////////////////
// QUERY 1

void query_1(Clientes* c, Produtos* p, Filial* f1, Faturacao* f2, int num[6], int r){

	if(r == 1){
		free_clientes(*c);
		
		*f1 = iniciar_filial();
		*c = iniciar_clientes(num,*f1);
	}
	
	if(r == 2){
		free_produtos(*p);

		*f1 = iniciar_filial();
		*p = iniciar_produtos(num,*f1);
	}

	if (r == 3){
		free_clientes(*c);
		free_produtos(*p);

		*f1 = iniciar_filial();
		*c 	= iniciar_clientes(num,*f1);
		*p 	= iniciar_produtos(num,*f1);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_1M.txt");
	}

	if(r == 4){
		free_clientes(*c);
		free_produtos(*p);
		
		*f1 = iniciar_filial();
		*c 	= iniciar_clientes(num,*f1);
		*p 	= iniciar_produtos(num,*f1);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_3M.txt");
	}

	if(r == 5){
		free_clientes(*c);
		free_produtos(*p);
	
		*p 	= iniciar_produtos(num,*f1);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_5M.txt");
	}

	if(r == 6){
		free_produtos(*p);

		*p 	= iniciar_produtos(num,*f1);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_1M.txt");
	}

	if(r == 7){
		free_clientes(*c);

		*c = iniciar_clientes(num,*f1);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_1M.txt");
	}
}

///////////////////////////////////////////////////////////
// QUERY 2

String* query_2(Produtos* p, char letra, int tamanho){

	String* lista = malloc(sizeof(String)*tamanho);

	for(int i = 0; i < tamanho; i++){
		lista[i] = NULL;
	}

	lista_produtos(*p, letra, lista);

	return lista;
}

///////////////////////////////////////////////////////////
// QUERY 3
void query_3 (Faturacao* f, Filial* f2, Produtos* pr){

    int vendas = 0;
    int vendasP = 0;
    int vendasN = 0;
    //double fat_fil = 0;
    //int exit = 0;

    char* inpt = malloc(sizeof(char)*buffsize);
    int mes=1;
    int filial=1;
    char produto[7];

    RP p = get_produtos(*f2);

    printf("%sInsira um produto: %s\n",KBLU,RST);
    if(scanf("%s",produto)){
    	while(search_P(*pr, produto)==0){
	    	printf("%sProduto Invalido%s\n",KRED,RST);
	    	if(scanf("%s",produto));
	    }
    }
	
    printf("%sInsira um mes: %s\n",KBLU,RST);

    if(scanf("%s",inpt)){
		mes=atoi(inpt);

		while(mes<=0 || mes>12){
			printf("%sMês Invalido%s\n",KRED,RST);
			if(scanf("%s",inpt));
			mes=atoi(inpt);
		}
	}

	printf("%sInsira uma filial [1..3] ou [4] para valores globais: %s\n",KBLU,RST);
	
	if(scanf("%s",inpt)){
		filial=atoi(inpt);

		while(filial<=0 || filial>4){
			printf("%sOpção Invalida%s\n",KRED,RST);
			if(scanf("%s",inpt));
			filial=atoi(inpt);
		}

		if(filial == 4){
			for (int i = 0; i < 3; ++i)
			{
						
			vendas += p_vezes_comprado(p,produto,mes,i);
			vendasP += p_NP_vezes(p,produto,'P', i,mes);
			vendasN += p_NP_vezes(p,produto,'N', i,mes);
			}

			printf("A totalidade de vendas em todas as filiais desse produto com preço normal nesse mês é:  %d\n",vendasN );
			printf("A totalidade de vendas em todas as filiais desse produto em promoção nesse mês é:  %d\n",vendasP );
			printf("A totalidade de vendas em todas as filiais desse produto nesse mês é:  %d\n",vendas );
		}

		if(filial == 1){
			
			vendas = p_vezes_comprado(p,produto,mes,0);
			vendasP = p_NP_vezes(p,produto,'P', 0,mes);
			vendasN = p_NP_vezes(p,produto,'N', 0,mes);
			

			printf("A totalidade de vendas em todas as filiais desse produto com preço normal nesse mês é:  %d\n",vendasN );
			printf("A totalidade de vendas em todas as filiais desse produto em promoção nesse mês é:  %d\n",vendasP );
			printf("A totalidade de vendas em todas as filiais desse produto nesse mês é:  %d\n",vendas );
		}

		if(filial == 2){
			vendas = p_vezes_comprado(p,produto,mes,1);
			vendasP = p_NP_vezes(p,produto,'P', 1,mes);
			vendasN = p_NP_vezes(p,produto,'N', 1,mes);
			

			printf("A totalidade de vendas em todas as filiais desse produto com preço normal nesse mês é:  %d\n",vendasN );
			printf("A totalidade de vendas em todas as filiais desse produto em promoção nesse mês é:  %d\n",vendasP );
			printf("A totalidade de vendas em todas as filiais desse produto nesse mês é:  %d\n",vendas );
		}

		if(filial == 3){
			
			vendas = p_vezes_comprado(p,produto,mes,2);
			vendasP = p_NP_vezes(p,produto,'P', 2,mes);
			vendasN = p_NP_vezes(p,produto,'N', 2,mes);
			

			printf("A totalidade de vendas em todas as filiais desse produto com preço normal nesse mês é:  %d\n",vendasN );
			printf("A totalidade de vendas em todas as filiais desse produto em promoção nesse mês é:  %d\n",vendasP );
			printf("A totalidade de vendas em todas as filiais desse produto nesse mês é:  %d\n",vendas );
		}
	}
}


///////////////////////////////////////////////////////////
// QUERY 5
//void query_5(){}

///////////////////////////////////////////////////////////
// QUERY 6
void query_6(Filial* f, int c[1], int p[1]){

	RP produtos = get_produtos(*f);
	RC clientes = get_clientes(*f);

	c[0] = c_nao_comprou(clientes);
	p[0] = p_nao_vendeu(produtos);
}


///////////////////////////////////////////////////////////
// QUERY 7
void query_7 (){
	char* cliente=malloc(sizeof(char)*buffsize);
	int filial = 1;
	int vendas = 0;
	// String*int validstr = 0;
	printf("%sInsira um cliente: %s\n",KBLU,RST);
	if(scanf("%s",cliente));
	
	while (valida_cliente(cliente)==0) {
		printf("%sCliente Invalido%s\n",KRED,RST);
		if(scanf("%s",cliente));
	}

	printf("%s#############################################################\n",KBLU);
	printf("%s##                                                         ##\n",KBLU);
	printf("%s##%s                           %s                        %s##\n",KBLU,RST,cliente,KBLU);
	printf("%s##                                                         ##\n",KBLU);
	printf("%s#############################################################\n",KBLU);
	printf("%s##                     ##                ##                ##\n",KBLU);
	printf("%s##%s       Filial        %s##%s       Mês      %s##%s     Vendas     %s##\n",KBLU,RST,KBLU,RST,KBLU,RST,KBLU);
	printf("%s##                     ##                ##                ##\n",KBLU);
	printf("%s#############################################################\n",KBLU);

	for(filial = 1; filial<4; filial++){
		for (int mes = 1; mes < 13; ++mes){
		//vendas = n_vendas(cliente,filial,mes);
		printf("%s##                     ##                ##                ##\n",KBLU);
		printf("%s##%s        %d            %s##%s        %d       %s##%s      %d        %s##\n",KBLU,RST,filial,KBLU,RST,mes,KBLU,RST,vendas,KBLU);
		printf("%s#############################################################%s\n",KBLU,RST);
		}
	}
}

///////////////////////////////////////////////////////////
// QUERY 8
void query_8 (Faturacao* f1, int mes1, int mes2, int v[1] , double f[1]){
	int vendas = 0;
	double faturado = 0;

	for(int i = mes1; i<=mes2; i++)
		vendas += numero_vendas(*f1,i);

	for(int i = mes1; i<=mes2; i++)
		faturado += faturado_mes(*f1,i);

	v[0] = vendas;
	f[0] = faturado;
}

///////////////////////////////////////////////////////////
// QUERY 9
//void query_9(){}

///////////////////////////////////////////////////////////
// QUERY 10
//void query_10(){}

///////////////////////////////////////////////////////////
// QUERY 11
//void query_11(){}

///////////////////////////////////////////////////////////
// QUERY 12
//void query_12(){}