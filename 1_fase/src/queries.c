#include "../include/queries.h"
#include "../include/AVL.h"

///////////////////////////////////////////////////////////
// SGV

struct sgv {
	Clientes c;
 	Produtos p; 
	Filial f1;
 	Faturacao f2;
};

SGV iniciar_sgv (){

	SGV s = malloc(sizeof(struct sgv));

	s->c = NULL;
	s->p = NULL;
	s->f1 = NULL;
	s->f2 = NULL;

	return s;
}


Clientes get_clientes_(SGV s){
	return s->c;
}

Produtos get_produtos_(SGV s){
	return s->p;
}

Filial get_filial_(SGV s){
	return s->f1;
}

Faturacao get_faturacao_(SGV s){
	return s->f2;
}

///////////////////////////////////////////////////////////
// QUERY 1

void query_1(SGV s, int num[6], int r){

	if(r == 1){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
	}
	
	if(r == 2){
		s->f1 = iniciar_filial();
		s->p = iniciar_produtos(num,s->f1);
	}

	if (r == 3){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "../Vendas_1M.txt");
	}

	if(r == 4){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "../Vendas_3M.txt");
	}

	if(r == 5){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "../Vendas_5M.txt");
	}

	if(r == 6){
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "../Vendas_1M.txt");
	}

	if(r == 7){
		s->c = iniciar_clientes(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "../Vendas_1M.txt");
	}
}

///////////////////////////////////////////////////////////
// QUERY 2

int query_2(SGV s, char letra, Lista_Strings ls){
	lista_produtos(s->p, letra, ls);

	return size_lista(ls);
}

///////////////////////////////////////////////////////////
// QUERY 3

void query_3(SGV s, char* produto, int mes, int vendas[3], int faturado[3], int filial){


   RP p = get_produtos(s->f1);

	for (int j = 0; j < 3; j++){
		vendas[j] = 0;
	}

	for (int k = 0; k < 3; k++){
		faturado[k] = 0;
	}

	if(filial == 4){
		for (int i = 1; i <= 3; i++){
			
			vendas[0] += p_vezes_comprado(p, produto, mes, i);
			vendas[1] += p_NP_vezes(p, produto,'N', i, mes);
			vendas[2] += p_NP_vezes(p, produto,'P', i, mes);

			faturado[1] += p_faturado_in(p, produto, mes, i, 'N');
			faturado[2] += p_faturado_in(p, produto, mes, i, 'P');
			faturado[0] += faturado[1] + faturado[2];
		}
	}
	else{
		vendas[0] = p_vezes_comprado(p, produto, mes, filial);
		vendas[1] = p_NP_vezes(p, produto, 'N', filial, mes);
		vendas[2] = p_NP_vezes(p, produto, 'P', filial, mes);

		faturado[1] = p_faturado_in(p, produto, mes, filial, 'N');
		faturado[2] = p_faturado_in(p, produto, mes, filial, 'P');
		faturado[0] = faturado[1] + faturado[2];	
	}
}


///////////////////////////////////////////////////////////
// QUERY 4

int query_4(SGV s, Lista_Strings ls, int filial) {
	if(filial == 4)
		p_vendeu_todas(get_produtos(s->f1), ls, 0);
	else p_vendeu_todas(get_produtos(s->f1), ls, filial);

	return size_lista(ls);
}


///////////////////////////////////////////////////////////
// QUERY 5

int query_5(SGV s, Lista_Strings ls){
	c_comprou_tudo(get_clientes(s->f1), ls);

	return size_lista(ls);
}

///////////////////////////////////////////////////////////
// QUERY 6

void query_6(SGV s, int c[1], int p[1]){

	RP produtos = get_produtos(s->f1);
	RC clientes = get_clientes(s->f1);

	c[0] = c_nao_comprou(clientes);
	p[0] = p_nao_vendeu(produtos);
}

///////////////////////////////////////////////////////////
// QUERY 7
void query_7(SGV s, char* cliente, int vendas[12][3]){

	
	RC cl = get_clientes(s->f1);
	
	for (int mes = 0; mes < 12; ++mes){
		for(int filial = 0; filial<3; filial++){
			vendas[mes][filial] = c_vezes_comprou(cl,cliente,mes,filial);
		}
	}
}

///////////////////////////////////////////////////////////
// QUERY 8

void query_8 (SGV s, int mes1, int mes2, int v[1] , double f[1]){
	int vendas = 0;
	double faturado = 0;

	for(int i = mes1; i<=mes2; i++)
		vendas += numero_vendas(s->f2,i);

	for(int i = mes1; i<=mes2; i++)
		faturado += faturado_mes(s->f2,i);

	v[0] = vendas;
	f[0] = faturado;
}

///////////////////////////////////////////////////////////
// QUERY 9

void query_9(SGV s, char* produto, int filial, Lista_Strings N, Lista_Strings P){
	search_9("../Vendas_1M.txt", s->c, produto, filial, N, P);
}

///////////////////////////////////////////////////////////
// QUERY 10

void query_10(SGV s, char* cliente, int mes, Lista_Ordenada P){
	search_10("../Vendas_1M.txt", s->p, cliente, mes, P);
}



///////////////////////////////////////////////////////////
// QUERY 11

/*

Criar uma lista dos N produtos mais vendidos em todo o ano, indicando o número total de clientes e o número de unidades vendidas, filial a filial;

*/

void query_11(Filial* f, int N){
	//Lista_N_Maiores s = iniciar_nm(N);

}

///////////////////////////////////////////////////////////
// QUERY 12

//void query_12(){}