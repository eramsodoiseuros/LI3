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
    int mesf;
    int mes2;
    int filial;
    int filial2;

    while(exit!=1){

	    printf("1.Total faturado\n");
	    printf("2.Total faturado por mês\n");
	    printf("3.Faturacao por filial por mês\n");
	    printf("4.Total faturado por filial\n");
	    printf("5.Total de vendas\n");
	    printf("6.Total de vendas por mês\n");
	    printf("0.Sair\n");


	    scanf("%d",&escolha);
	    if (escolha<0 || escolha>6)
	        printf("Opção invalida\n");

	    switch(escolha){
	        case 0:
	            exit = 1;
	            break;

	        case 1:
	            printf("Total faturado: %f\n",total_faturado(*f) );
	            break;

	        case 2:
	            printf("Insira um mês (1..12) :\n");
	            scanf("%d",&mes);
	            printf("Total de faturado nesse mês: %f\n",faturado_mes(*f,mes));
	            break;

	        case 3:
	            printf("Insira filial:\n");
	            scanf("%d",&filial);
	            printf("Insira um mês (1..12) :\n");
	            scanf("%d",&mesf);
	            printf("O total faturado nessa filial nesse mês: %f\n",faturado_in(*f,mesf,filial));
	            break;

	        case 4:
	            printf("Insira filial:\n");
	            scanf("%d",&filial2);
	            for (int i = 0; i < 12; ++i)
	                fat_fil += faturado_in(*f,i,filial2);
	            printf("O total faturado nessa filial: %f\n",fat_fil);
	            break;

	        case 5:
	            for (int i = 0; i < 12; ++i)
	                vendas += numero_vendas(*f,i);
	            printf("Total de vendas: %d\n",vendas);
	            break;

	        case 6:
	            printf("Insira um mês (1..12) :\n");
	            scanf("%d",&mes2);
	            printf("O total vendido nesse mês: %d\n", numero_vendas(*f,mes2));
	            break;
    	}
	}
}