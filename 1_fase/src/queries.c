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

void query_2(Produtos* p, char letra, String* lista){
			
	lista_produtos(*p, letra, lista);
}


void query_3 (Faturacao* f, Filial* f2){

    int vendas = 0;
    //double fat_fil = 0;
    //int exit = 0;

    char* inpt =malloc(sizeof(char)*buffsize);
    int mes=1;
    int filial=1;
    char produto[7];

    RP p = get_produtos(f2);

    printf("%sInsira um produto: %s\n",KBLU,RST);
    if(scanf("%s",produto));

    while(valida_produto(produto)==0){
    	printf("%sProduto Invalido%s\n",KRED,RST);
    	if(scanf("%s",produto));
    }
    
    printf("%sInsira um mes: %s\n",KBLU,RST);

    if(scanf("%s",inpt));
	mes=atoi(inpt);

	while(mes<=0 || mes>12){
		printf("%sMês Invalido%s\n",KRED,RST);
		if(scanf("%s",inpt));
		mes=atoi(inpt);
	}

	printf("%sInsira uma filial [1..3] ou [4] para valores globais: %s\n",KBLU,RST);
	if(scanf("%s",inpt))
	filial=atoi(inpt);

	while(filial<=0 || filial>4){
		printf("%sOpção Invalida%s\n",KRED,RST);
		if(scanf("%s",inpt));
		filial=atoi(inpt);
	}

	if(filial == 4){

	vendas = produto_vendido(p,produto,4);

	printf("A totalidade de vendas desse produto é:  %d\n",vendas );
	}

	if(filial == 1){

	vendas = produto_vendido(p,produto,1);

	printf("O numero de vendas desse produto nessa filial:  %d\n",vendas );
	}

	if(filial == 2){

	vendas = produto_vendido(p,produto,2);

	printf("A totalidade de vendas desse produtp é:  %d\n",vendas );
	}

	if(filial == 3){

	vendas = produto_vendido(p,produto,3);

	printf("A totalidade de vendas desse produtp é:  %d\n",vendas );
	}
}




void query_7 (){
	char* cliente=malloc(sizeof(char)*buffsize);
	int filial = 1;
	int vendas = 0;
	int validstr = 0;
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
		for (int mes = 1; mes < 13; ++mes)
		{
		//vendas = n_vendas(cliente,filial,mes);
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