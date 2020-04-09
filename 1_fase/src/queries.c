#include "../include/queries.h"
#include "../include/AVL.h"

///////////////////////////////////////////////////////////
// QUERY 1

void query_1(Clientes* c, Produtos* p, Filial* f1, Faturacao* f2, int num[6], int r){
		
	if(r == 1){
		free_clientes(*c);
		*c = iniciar_clientes(num);
	}
	
	if(r == 2){
		free_produtos(*p);
		*p = iniciar_produtos(num);
	}

	if (r == 3){
		free_clientes(*c);
		free_produtos(*p);

		*c 	= iniciar_clientes(num);
		*p 	= iniciar_produtos(num);
		// iniciar_filial(f1);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_1M.txt");
	}

	if(r == 4){
		free_clientes(*c);
		free_produtos(*p);

		*c 	= iniciar_clientes(num);
		*p 	= iniciar_produtos(num);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_3M.txt");
	}

	if(r == 5){
		free_produtos(*p);

		*p 	= iniciar_produtos(num);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_1M.txt");
	}

	if(r == 6){
		free_clientes(*c);

		*c = iniciar_clientes(num);
		*f2 = iniciar_faturacao();
		init_Vendas(num, *p, *c, *f1, *f2, "../Vendas_1M.txt");
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

    char* inpt =malloc(sizeof(char)*buffsize);
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
	    printf("E. Sair\n");


	    if(scanf("%s",inpt))
	    escolha=atoi(inpt);
		if(strcmp(inpt,"e")==0 || strcmp(inpt,"E")==0) exit = 1;
	    if(exit!=1)
	    if (escolha<1 || escolha>6)
	        printf("%sOpção invalida%s\n",KRED,RST);
	    	printf("\n");

	    switch(escolha){
	       
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




void query_7 (){
	char* cliente=malloc(sizeof(char)*buffsize);
	int filial = 1;
	int vendas = 50;
	int validstr = 0;
	printf("%sInsira um cliente: %s\n",KBLU,RST);
	if(scanf("%s",cliente));
	validstr = atoi(cliente);
	while (validstr =! 0) {
		printf("%sProduto Invalido%s\n",KRED,RST);
		if(scanf("%s",cliente));
		printf("%d\n",validstr );
		validstr = atoi(cliente);
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
		for (int mes = 1; mes < 13; ++mes)
		{
		printf("%s##                     ##                ##                ##\n",KBLU);
		printf("%s##%s        %d            %s##%s        %d       %s##%s      %d        %s##\n",KBLU,RST,filial,KBLU,RST,mes,KBLU,RST,vendas,KBLU);
		printf("%s#############################################################%s\n",KBLU,RST);
		}
	}



}

void query_8 (Faturacao* f){
	char* inpt=malloc(sizeof(char)*buffsize);
	int mes1=1;
	int mes2;
	int vendas =0;
	double faturado = 0;
	int validstr = 1;
	int exit = 0;
	

	while(exit!=1){

		printf("%sInsira os meses que deseja consultar [1..12]:%s      %s[E para Sair] %s\n",KBLU,RST,KRED,RST);
		if(scanf("%s",inpt));
		validstr = atoi(inpt);
		mes1 = atoi(inpt);
		if(strcmp(inpt,"e")==0 || strcmp(inpt,"E")==0) exit = 1;

		if(exit!=1){
		while(validstr == 0){	
		if(mes1>11 || mes1<0 || validstr == 0){
		printf("Mês invalido. Tente novamente\n");
		if(scanf("%s",inpt));
		validstr = atoi(inpt);

	}
}
			
		printf("%sAté: %s\n",KBLU,RST);
		if(scanf("%s",inpt));
		validstr = atoi(inpt);
		mes2 = atoi(inpt);
		while(validstr==0){
		if(mes2>12 || mes2<mes1 || validstr == 0){
			printf("Mês invalido. Tente novamente\n");
			if(scanf("%s",inpt));
			validstr = atoi(inpt);
		}
	}
								
								
		
		for(int i = mes1; i<=mes2; i++){

		vendas+=numero_vendas(*f,i);
		}

		printf("%sTotal de vendas nesse intervalo é:%s %d\n",KBLU,RST,vendas);

		for(int i = mes1; i<=mes2; i++){

		faturado+=faturado_mes(*f,i);
		}

		printf("%sE o total faturado nesse intervalo é:%s %f\n",KBLU,RST,faturado);
				


			

		
}

}
}