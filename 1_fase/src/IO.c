#include "../include/IO.h"


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

int escolhe_file(){
	int r;

	printf("\n\tQue ficheiro pretende ler? Clientes.txt [1], Produtos.txt [2], Vendas_1M.txt [3], todos [4]\n\t->  ");
	
	if(scanf("%d", &r)){
		r=r;
	}
	else {
		printf("\n\tO programa falhou na leitura de um número. [1...4]\n");
		escolhe_file();
	}

	return r;
}

// Função que escolhe a query a realizar
void escolhe_query(){
	int tarefa;
	int r;
	int num[6];
	for(int i = 0; i <= 5; i++) num[i] = 0; 
	Clientes c 		= NULL;
	Produtos p 		= NULL;
	Filial f1 		= NULL;
	Faturacao f2 	= NULL;

	printf("Escolha o numero da query que pretende executar [1...12]\n\tTerminar o programa: [0]   ");
	if(scanf("%d", &tarefa)){

		if(tarefa > 12 || tarefa < 0){
			printf("\n\n\tPara executar uma tarefa é necessário inserir um numero de [1...12]\n\n\tPara terminar o programa insira o número 0.\n\n");
			escolhe_query();
		}

		switch(tarefa){
			case 1:
				r = escolhe_file();
				if(r == 1){
					query_1(c, p, f1, f2, num, 1);
					printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes lidos__%s%d\n\t%sClientes escritos__%s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
				}
				if(r == 2){
					query_1(c, p, f1, f2, num, 2);
					printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos lidos__%s%d\n\t%sProdutos escritos__%s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
				}
				if (r == 3){
					query_1(c, p, f1, f2, num, 3);
					printf("%s\n\tFicheiro lido: %sVendas_1M.txt\n\t%sVendas lidas__%s%d\n\t%sVendas escritas__%s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);
				}
				if(r == 4){
					query_1(c, p, f1, f2, num, 4);
					printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes lidos__%s%d\n\t%sClientes escritos__%s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
					printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos lidos__%s%d\n\t%sProdutos escritos__%s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
					printf("%s\n\tFicheiro lido: %sVendas_1M.txt\n\t%sVendas lidas__%s%d\n\t%sVendas escritas__%s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);
				}
				break;
		/*
			case 2:
				query_2();
				break;
			case 3:
				query_3();
				break;
			case 4:
				query_4();
				break;
			case 5:
				query_5();
				break;
			case 8:
				query_8();
				break;
			case 9:
				query_9();
				break;
			case 10:
				query_10();
				break;
			case 11:
				query_10();
				break;
			case 12:
				query_10();
				break;
		*/
		}
	}
	else{
		printf("\n\tO programa falhou na leitura de um número.\n");
		escolhe_query();
	}
}

// to print or not to print
void menu(){
	char* r = malloc(sizeof(char*));
	printf("Pretende dar print ao menu? Yes: [y] No: [n]\n");
	if(scanf("%c", r)){
		if(r[0] == 'y' || r[0] == 'Y'){
			print_menu();
			escolhe_query();
		}

		if(r[0] == 'n' || r[0] == 'N'){
			escolhe_query();
		}
	}

	else {
		printf("\n\tO programa falhou na leitura da resposta. Yes: [y/Y] No: [n/N]\n");
		menu();
	}
}