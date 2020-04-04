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

void query_2(Produtos* p, char letra, String* lista){
			
	lista_produtos(*p, letra, lista);
}


void query_3 (Faturacao* f){

    int vendas = 0;
    double fat_fil = 0;
    int exit = 0;

    int escolha;
    int mes;
    int filial;
    
    while(exit!=1){

	    printf("1. Total faturado\n");
	    printf("2. Total faturado por mês\n");
	    printf("3. Faturacao por filial por mês\n");
	    printf("4. Total faturado por filial\n");
	    printf("5. Total de vendas\n");
	    printf("6. Total de vendas por mês\n");
	    //printf("7. Total de vendas por filial\n");
	    //printf("8. Total de vendas em promoção\n");
	    //printf("9. Total de vendas em promoção por filial\n");
	    //printf("10. Faturação de produtos em promoção\n");
	    printf("0. Sair\n");


	    if(scanf("%d",&escolha))
	    if (escolha<0 || escolha>6)
	        printf("Opção invalida\n");

	    switch(escolha){
	        case 0:
	            exit = 1;
	            break;

	        case 1:
	            printf("Total faturado: %f\n",total_faturado(*f) );
	            printf("\n");
	            break;

	        case 2:
	            printf("Insira um mês [1..12]:\n");
	            if(scanf("%d",&mes))
	            printf("Total de faturado nesse mês: %f\n",faturado_mes(*f,mes));
	        	printf("\n");
	            break;

	        case 3:
	            printf("Insira filial:\n");
	            if(scanf("%d",&filial))
	            printf("Insira um mês [1..12]:\n");
	            if(scanf("%d",&mes))
	            printf("O total faturado nessa filial nesse mês: %f\n",faturado_in(*f,mes,filial));
	        	printf("\n");
	            break;

	        case 4:
	            printf("Insira filial:\n");
	            if(scanf("%d",&filial))
	            for (int i = 0; i < 12; ++i)
	                fat_fil += faturado_in(*f,i,filial);
	            printf("O total faturado nessa filial: %f\n",fat_fil);
	            printf("\n");
	            break;

	        case 5:
	            for (int i = 0; i < 12; ++i)
	                vendas += numero_vendas(*f,i);
	            printf("Total de vendas: %d\n",vendas);
	            printf("\n");
	            break;

	        case 6:
	            printf("Insira um mês [1..12]:\n");
	            if(scanf("%d",&mes))
	            printf("O total vendido nesse mês: %d\n", numero_vendas(*f,mes));
	        	printf("\n");
	            break;
    	}
	}
}