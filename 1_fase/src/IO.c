#include "../include/IO.h"
#include "../include/AVL.h"



// Print do menu, com a informação das queries
void print_menu(){
	printf("%s\n************************************************** Sistema de Gestão de Vendas ************************************************** %s\n", KCYN, RST);
	printf("%s\n\t->%s Query 1:  Ler ficheiros (os ficheiros disponiveis para leitura são: \'Produtos.txt\', \'Clientes.txt\', \'Vendas_1M.txt\').\n", KCYN, RST);
	printf("%s\n\t->%s Query 2:  Determinar a lista e o número de produtos começados por uma Letra à escolha (A...Z).\n" , KCYN, RST);
	printf("%s\n\t->%s Query 3:  Dado um mês e um produto, determinar e apresentar o nº total de registos\n\t   de venda e o total facturado com esse produto nesse mês, tendo em conta a distinção N/P,\n\t   há possibilidade de escolher a apresentação dos resultados dividida por filial.\n" , KCYN, RST);
	printf("%s\n\t->%s Query 4:  Determinar a lista ordenada de produtos que ninguém comprou, e o seu total,\n\t   há possibilidade de escolher a apresentação dos resultados dividida por filial.\n", KCYN, RST);
	printf("%s\n\t->%s Query 5:  Determinar a lista ordenada de clientes que realizaram compras em todas as filiais.\n", KCYN, RST);
	printf("%s\n\t->%s Query 6:  Determinar o nº de clientes registados que não realizaram compras.\n\t   Determinar o nº de produtos que ninguém comprou.\n", KCYN, RST);
	printf("%s\n\t->%s Query 7:  Dado um cliente, criar uma tabela com o nº total de produtos comprados, mês a mês, organizado por filial.\n", KCYN, RST);
	printf("%s\n\t->%s Query 8:  Dado um intervalo de tempo (de mês __ a mês __):\n\t   Determinar o total de vendas registadas nesse intervalo e o total facturado.\n", KCYN, RST);
	printf("%s\n\t->%s Query 9:  Dado um produto e uma filial, determinar os clientes e o nº de clientes que o compraram,\n\t   distinguindo a compra entre N e P.\n", KCYN, RST);
	printf("%s\n\t->%s Query 10: Dado um cliente e um mês, determinar a lista de\n\t   produtos que esse cliente mais comprou, por ordem decrescente.\n", KCYN, RST);
	printf("%s\n\t->%s Query 11: Criar uma lista dos N produtos mais vendidos em todo o ano,\n\t   indicando o nº total de clientes e o nº total de unidades vendidas, filial a filial.\n", KCYN, RST);
	printf("%s\n\t->%s Query 12: Dado um cliente, determinar os 3 produtos em que gastou mais dinheiro durante o ano.\n\n", KCYN, RST);
	printf("%s********************************************************************************************************************************* %s\n", KCYN, RST);
}

// Função que
int escolhe_file(){
	int r=1;
	char* inpt=malloc(sizeof(char)*buffsize);
	printf("\n\tQue ficheiro pretende ler? Clientes.txt [1], Produtos.txt [2], Vendas_1M.txt [3], Vendas_3M [4], Vendas_5M [5]\n\t->  ");
	
	if(scanf("%s", inpt)){
		r = atoi(inpt);
	
		if(r<1 || r>5){	
			printf("\n\tO programa falhou na leitura de um número. [1...5]\n");
			escolhe_file();
		}
	}
	else {
		printf("\n\tO programa falhou na leitura de um número. [1...5]\n");
		escolhe_file();
	}


	return r;
}

// Função que
void navegador(Lista_Strings lista, int tamanho){

	int val = 1, exit = 0;
	char* scanS = malloc(sizeof(char)*buffsize);
	int validstr = 1, scanout = 1;
	int pag = 1, i = 0, count = 0;

	while(exit!=1){
		printf("pag_%d_tamanho_%d\n",pag, tamanho );

		if(scanout==0 || pag>(tamanho/10) || pag<0 || val==0 || lista==NULL){
			val=1;
			printf("Página inválida ou não existente\n");
		}
		else{

			if(lista || pag < (tamanho/10))
			printf("%s************ Página %d ************%s\n",KBLU,(pag), RST);
			printf("Existem %s%d%s resultados\n\n",KBLU, tamanho, RST);
	             
			for(i=(pag*10)-Pagsize; count<Pagsize; i++){
				printf("%s \n", get_elem(lista,i));
				count++;
			}
			count = 0;
		}

		printf("\n");
		printf("%s(D para Proxima página) \n",KBLU);
		printf("%s(A para Página Anterior) \n",KBLU);
		printf("%s(E para sair)%s \n",KBLU,RST);
		printf("Inserir número página: \n");

		scanout = read(0,scanS,buffsize);
		scanS = strtok(scanS," \n");

		validstr = atoi(scanS);
		printf("\n");

		if(strcmp(scanS,"e") == 0) {exit = 1;}
		else if(strcmp(scanS,"d") == 0 && pag<((tamanho/10)+1)) pag++;
		else if(strcmp(scanS,"a") == 0 && pag>1) pag--;
		else if(validstr==0) val = 0;
		else if(validstr!=0) pag = validstr;
    }

	free(scanS);
}

// Função que
char letra_(){
	char* inpt = malloc(sizeof(char)*buffsize);
	char letra = '1';
	printf("%sInsira uma Letra [A...Z]: %s\n",KBLU,RST);

	if(scanf("%s", inpt)){
		letra = inpt[0];
		if(letra < 'A' || letra >'Z'){
			printf("%sInput Inválido.%s\n",KRED,RST);
			letra = letra_();
		}
	}

	free(inpt);
	return letra;
}


// Função que
int mes_(){
	char* inpt = malloc(sizeof(char)*buffsize);
	int mes = 0;
	printf("%sInsira um Mês: %s\n",KBLU,RST);

	if(scanf("%s", inpt)){
		mes = atoi(inpt);
	}

 	if(mes < 1 || mes > 12){
 		printf("%sInput Inválido.%s\n",KRED,RST);
    	mes = mes_();
  	}

  	free(inpt);
	return mes;
}

// Função que
int deseja_sair(){
	char* inpt = malloc(sizeof(char)*buffsize);
	int decisao = 1;

	printf("%s[E para Sair] %s\n",KRED,RST);
	printf("%s[Qualquer outra letra para Ficar] %s\n",KRED,RST);
	if(scanf("%s",inpt)){
		if(strcmp(inpt,"e") == 0 || strcmp(inpt,"E") == 0)
			decisao = 0;
	}

	free(inpt);
	return decisao;
}


char* produto_(Produtos* pr){
	char* produto = malloc(sizeof(char)*buffsize);

	printf("%sInsira um produto: %s\n",KBLU,RST);
    if(scanf("%s",produto)){
   	
   		while(search_P(*pr, produto)==0){
			printf("%sProduto Invalido%s\n",KRED,RST);
			produto = produto_(pr);
		}
    }
    return produto;

}

char* cliente_(Clientes* c){
	char* cliente = malloc(sizeof(char)*buffsize);

	printf("%sInsira um cliente: %s\n",KBLU,RST);
    if(scanf("%s",cliente)){
    	while(search_C(*c, cliente)==0){
		printf("%sCliente Invalido%s\n",KRED,RST);
			cliente = cliente_(c);
		}
    }
    return cliente;

}

int filial_(){
	char* inpt = malloc(sizeof(char)*buffsize);
	int filial = 0;
	printf("%sInsira uma filial [1..3] ou [4] para valores globais: %s\n",KBLU,RST);
	
	if(scanf("%s",inpt)){
		filial=atoi(inpt);

		while(filial<=0 || filial>4){
			printf("%sOpção Invalida%s\n",KRED,RST);
			if(scanf("%s",inpt));
			filial=atoi(inpt);
		}


	}
	free(inpt);
	return filial;
}








void faz_tabela7 (char* cliente, int vendas[12][3]){

	int venda_tot = 0;

	printf("%s#################################################################################################################################\n",KBLU);
	printf("%s##                                                                                                                             ##\n",KBLU);
	printf("%s##%s                                                         %s                                                              %s ##\n",KBLU,RST,cliente,KBLU);
	printf("%s##                                                                                                                             ##\n",KBLU);
	printf("%s#################################################################################################################################\n",KBLU);
	printf("%s##                     ##                          ##                       ##                        ##                       ##\n",KBLU);
	printf("%s##%s       Mês           %s##%s       Filial 1           %s##%s     Filial 2          %s##%s      Filial 3          %s##%s    Vendas Totais%s      ##%s\n",KBLU,RST,KBLU,RST,KBLU,RST,KBLU,RST,KBLU,RST,KBLU,RST);
	printf("%s##                     ##                          ##                       ##                        ##                       ##\n",KBLU);
	printf("%s#################################################################################################################################\n",KBLU);

	
		for (int mes = 0; mes < 12; ++mes){
			for (int i = 0; i < 3; ++i)
			{
				venda_tot += vendas[mes][i];
			}
			printf("%s##                     ##                          ##                       ##                        ##                       ##\n",KBLU);
			printf("%s##%s         %d                      %d                           %d                          %d                      %d         \n",KBLU,RST,mes+1,vendas[mes][0],vendas[mes][1],vendas[mes][2],venda_tot);
			printf("%s#################################################################################################################################%s\n",KBLU,RST);
			venda_tot = 0;
		}
}



// Função que escolhe a query a realizar
void escolhe_query(Clientes* c, Produtos* p, Filial* f1, Faturacao* f2){
	clock_t inicio, fim;
	double cpu_time_used;

	int tarefa, tamanho = 0;
	int m1, m2, decisao = 1;

	char* inpt = malloc(sizeof(char)*buffsize);
	char* cliente=malloc(sizeof(char)*buffsize);
	char letra;
	Lista_Strings lista;
	int v[1]; v[0] = 0;
	int aux_c[1], aux_p[1];
	aux_c[0] = 0; aux_p[0] = 0;
	double f[1]; f[0] = 0;
	int filial=0;
	char* produto=malloc(sizeof(char)*buffsize);
	int vendas[12][3];
	int vendasT[1];
    int vendasP[1];
    int vendasN [1];

	for (int mes = 0; mes < 12; ++mes){
		for(int filial = 0; filial<3; filial++){
			vendas[mes][filial] = 0;
		}
	}	
	printf("Escolha o numero da query que pretende executar [2...12]\n\tTerminar o programa: [1]   ");
	if(scanf("%s", inpt)){
		tarefa = atoi(inpt);
		if(tarefa > 12 || tarefa < 1){
			printf("\n\n\tPara executar uma tarefa é necessário inserir um numero de [2...12]\n\n\tPara terminar o programa insira o número 1.\n\n");
			escolhe_query(c,p,f1,f2);
		}
		switch(tarefa){
			case 1:
				exit(1);
				break;

			case 2:
				letra = letra_();
				inicio = clock();

				tamanho = get_size(*p, letra);
			    lista = query_2(p, letra);

			    fim = clock();
				navegador(lista, tamanho);
				cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
				printf("CPUTIME: %f\n",cpu_time_used);

				break;

			case 3:

    			produto = produto_(p);
    			m1 = mes_();
    			filial = filial_();
				query_3(f2,f1,p,produto,m1,vendasT,vendasP,vendasN,filial);

				printf("A totalidade de vendas em todas as filiais desse produto com preço normal nesse mês é:  %d\n",vendasN[0] );
				printf("A totalidade de vendas em todas as filiais desse produto em promoção nesse mês é:  %d\n",vendasP[0] );
				printf("A totalidade de vendas em todas as filiais desse produto nesse mês é:  %d\n",vendasT[0] );
				break;
			/*	
			case 4:
					//lista = query_4(f1,p,s);
					//navegador(lista,s[0]);
					break;
			*/

			//case 5:
			
			case 6:
				query_6(f1,aux_c,aux_p);
				printf("c_%d_p_%d\n",aux_c[0],aux_p[0]);
				break;

			case 7:
				cliente = cliente_(c);
				inicio = clock();
				query_7(f1,c,cliente,vendas);
				fim = clock();
				faz_tabela7(cliente,vendas);
				cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
				printf("CPUTIME: %f\n",cpu_time_used);

				break;

			case 8:
				while(decisao){
					printf("%sInsira os meses que deseja consultar [1..12]:%s",KBLU,RST);
					m1 = mes_();
					printf("%sAté: %s\n",KBLU,RST);
					m2 = mes_();

					inicio = clock();
					query_8(f2, m1, m2, v, f);
					fim = clock();

					printf("%sTotal de vendas nesse intervalo é:%s %d\n",KBLU,RST,v[0]);
					printf("%sE o total faturado nesse intervalo é:%s %f\n",KBLU,RST,f[0]);
					
					cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
					printf("CPUTIME: %f\n",cpu_time_used);
					
					decisao = deseja_sair();
				}
				break;

				/*	
				case 9:
					query_9();
					break;
				*/

				case 10:
					cliente = sdup(cliente_());
					m1 = mes_();
	
					//query_10();
					break;
				/*	
				case 11:
					query_10();
					break;
				*/
				/*
				case 12:
					query_10();
					break;
				*/
		}
	}
	else{
		printf("\n\tO programa falhou na leitura de um número.\n");
		escolhe_query(c, p, f1, f2);
	}

	free(inpt);
	free(cliente);
}

// Função que
void load_query1 (Clientes* c, Produtos* p, Filial* f1, Faturacao* f2){
	int r, num[6];
	
	clock_t i, f;
	double cpu_time_used;
	
	for(int i = 0; i <= 5; i++) num[i] = 0; 

	r = escolhe_file();
	if(r == 1){
		i = clock();
		query_1(c, p, f1, f2, num, 1);
		f = clock();
		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos__%s%d\n\t%sClientes lidos__%s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		
		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);

		query_1(c, p, f1, f2, num, 6);
	}
	if(r == 2){
		i = clock();
		query_1(c, p, f1, f2, num, 2);
		f = clock();

		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos__%s%d\n\t%sProdutos lidos__%s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);

		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);

		query_1(c, p, f1, f2, num, 7);
	}
	if (r == 3){
		i = clock();
		query_1(c, p, f1, f2, num, 3);
		f = clock();
		
		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos__%s%d\n\t%sClientes lidos__%s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos__%s%d\n\t%sProdutos lidos__%s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
		printf("%s\n\tFicheiro lido: %sVendas_1M.txt\n\t%sVendas válidas__%s%d\n\t%sVendas lidas__%s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);

		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);
	}
	if(r == 4){
		i = clock();
		query_1(c, p, f1, f2, num, 4);
		f = clock();

		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos__%s%d\n\t%sClientes lidos__%s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos__%s%d\n\t%sProdutos lidos__%s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
		printf("%s\n\tFicheiro lido: %sVendas_3M.txt\n\t%sVendas válidas__%s%d\n\t%sVendas lidas__%s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);
		
		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);
	}

	if(r == 5){
		i = clock();
		query_1(c, p, f1, f2, num, 5);
		f = clock();

		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos__%s%d\n\t%sClientes lidos__%s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos__%s%d\n\t%sProdutos lidos__%s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
		printf("%s\n\tFicheiro lido: %sVendas_5M.txt\n\t%sVendas válidas__%s%d\n\t%sVendas lidas__%s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);
		
		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);
	}
}

// to print or not to print
void menu(Clientes* c, Produtos* p, Filial* f1, Faturacao* f2){
	char* r = malloc(sizeof(char*));
	printf("Pretende dar print ao menu? Yes: [y] No: [n]\n");

	if(scanf("%s", r)){
		if(r[0] == 'y' || r[0] == 'Y'){
			print_menu();
			load_query1(c,p,f1,f2);
			while(1){
				escolhe_query(c,p,f1,f2);
			}
		}

		if(r[0] == 'n' || r[0] == 'N'){
			load_query1(c,p,f1,f2);
			while(1){
				escolhe_query(c,p,f1,f2);
			}
		}
	}
	else {
		printf("\n\tO programa falhou na leitura da resposta. Yes: [y/Y] No: [n/N]\n");
		menu(c,p,f1,f2);
	}

	free(r);
}
