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
void query_3 (Faturacao* f, Filial* f2, Produtos* pr, char* produto, int mes, int vendasT[1], int vendasP[1], int vendasN[1], int filial){

      
    RP p = get_produtos(*f2);
    

		if(filial == 4){
			for (int i = 1; i < 4; ++i)
			{
						
			vendasT[0] += p_vezes_comprado(p,produto,mes,i);
			vendasP[0] += p_NP_vezes(p,produto,'P', i,mes);
			vendasN[0] += p_NP_vezes(p,produto,'N', i,mes);
			}

		}

		if(filial == 1){
			
			vendasT[0] = p_vezes_comprado(p,produto,mes,0);
			vendasP[0] = p_NP_vezes(p,produto,'P', 0,mes);
			vendasN[0] = p_NP_vezes(p,produto,'N', 0,mes);
			
		}

		if(filial == 2){
			vendasT[0] = p_vezes_comprado(p,produto,mes,1);
			vendasP[0] = p_NP_vezes(p,produto,'P', 1,mes);
			vendasN[0] = p_NP_vezes(p,produto,'N', 1,mes);
			

		}

		if(filial == 3){
			
			vendasT[0] = p_vezes_comprado(p,produto,mes,2);
			vendasP[0] = p_NP_vezes(p,produto,'P', 2,mes);
			vendasN[0] = p_NP_vezes(p,produto,'N', 2,mes);
		}
}


///////////////////////////////////////////////////////////
// QUERY 4
/*String* query_4 (Filial* f,Produtos* pr, int add[1]) {


	return lista_Nvendidos(f,pr,add);

}
*/
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
// QUERY 5
//void query_5(){}



///////////////////////////////////////////////////////////
// QUERY 6
//void query_6(){}



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
/*String* query_10(char* cliente, int mes, Clientes* c, Filial* f, Produtos* p, int add[1]){

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