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
		
		*f1 = iniciar_filial();
		*c 	= iniciar_clientes(num,*f1);
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

int query_2(Produtos* p, char letra, Lista_Strings s){
	lista_produtos(*p, letra, s);

	return size_lista(s);
}

///////////////////////////////////////////////////////////
// QUERY 3

void query_3 (Filial* f2, char* produto, int mes, int vendas[3], int faturado[3], int filial){


   RP p = get_produtos(*f2);
   for (int j = 0; j < 3; ++j)
    {
    	vendas[j]=0;
    } 

    for (int k = 0; k < 3; ++k)
    {
    	faturado[k]=0;
    }

		if(filial == 4){
			for (int i = 1; i < 4; ++i){
						
			vendas[0] += p_vezes_comprado(p,produto,mes,i);
			vendas[2] += p_NP_vezes(p,produto,'P', i,mes);
			vendas[1] += p_NP_vezes(p,produto,'N', i,mes);

			faturado[0] += p_faturado_in(p,produto,mes,i,'N') + p_faturado_in(p,produto,mes,i,'P');
			faturado[1] += p_faturado_in(p,produto,mes,i,'N');
			faturado[2] += p_faturado_in(p,produto,mes,i,'P');
			}

		}

		if(filial == 1){
			
			vendas[0] = p_vezes_comprado(p,produto,mes,0);
			vendas[2] = p_NP_vezes(p,produto,'P', 0,mes);
			vendas[1] = p_NP_vezes(p,produto,'N', 0,mes);

			faturado[0] = p_faturado_in(p,produto,mes,0,'N') + p_faturado_in(p,produto,mes,0,'P');
			faturado[1] = p_faturado_in(p,produto,mes,0,'N');
			faturado[2] = p_faturado_in(p,produto,mes,0,'P');
			
		}

		if(filial == 2){
			vendas[0] = p_vezes_comprado(p,produto,mes,1);
			vendas[2] = p_NP_vezes(p,produto,'P', 1,mes);
			vendas[1] = p_NP_vezes(p,produto,'N', 1,mes);

			faturado[0] = p_faturado_in(p,produto,mes,1,'N') + p_faturado_in(p,produto,mes,1,'P');
			faturado[1] = p_faturado_in(p,produto,mes,1,'N');
			faturado[2] = p_faturado_in(p,produto,mes,1,'P');
			

		}

		if(filial == 3){
			
			vendas[0] = p_vezes_comprado(p,produto,mes,2);
			vendas[2] = p_NP_vezes(p,produto,'P', 2,mes);
			vendas[1] = p_NP_vezes(p,produto,'N', 2,mes);


			faturado[0] = p_faturado_in(p,produto,mes,2,'N') + p_faturado_in(p,produto,mes,2,'P');
			faturado[1] = p_faturado_in(p,produto,mes,2,'N');
			faturado[2] = p_faturado_in(p,produto,mes,2,'P');
		}
}


///////////////////////////////////////////////////////////
// QUERY 4

int query_4 (Filial* f, Lista_Strings s, int filial) {
	p_vendeu_todas(get_produtos(*f), s, filial);

	return size_lista(s);
}


///////////////////////////////////////////////////////////
// QUERY 5

int query_5(Filial* f, Lista_Strings s){
	c_comprou_tudo(get_clientes(*f), s);

	return size_lista(s);
}

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
void query_7 (Filial* f, Clientes* c, char* cliente, int vendas[12][3]){

	
	RC cl = get_clientes(*f);
	
	for (int mes = 0; mes < 12; ++mes){
		for(int filial = 0; filial<3; filial++){
		vendas[mes][filial] = c_vezes_comprou(cl,cliente,mes,filial);



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


/*

String* query_10(char* cliente, int mes, Clientes* c, Filial* f, Produtos* p, int add[1]){
	RC cl = get_clientes(*f);
	String s;
	int comprado = 0;

	for (int i = 0; i < 3; ++i)
	{
		//if(c_comprou_p()==1) comprado += c_vezes_comprouP(cl,pl,cliente,mes,i);
			}

}*/



///////////////////////////////////////////////////////////
// QUERY 11

//void query_11(){}

///////////////////////////////////////////////////////////
// QUERY 12

//void query_12(){}