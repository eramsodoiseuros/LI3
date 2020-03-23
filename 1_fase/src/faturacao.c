#include "../include/faturacao.h"

struct faturacao{
	double tabela_faturacao[12][4];
	double total_faturado;
};


// Função que devolve o total faturado
double total_faturado(Faturacao f1){
	return f1.total_faturado;
}

// Função que devolve o total faturado num certo mês
double faturado_mes(Faturacao f1, int mes){
	double r = -1;
	
	if(filial<=12 && filial>=0) r = f1.tabela_faturacao[mes][4];

	return r;
}

// Função que devolve o total faturado num certo mês e numa certa filial
double faturado_in(Faturacao f1, int mes, int filial){
	double r = -1;
	
	if(filial<=3 && filial>=0) r = f1.tabela_faturacao[mes][filial];

	return r;
}

// Função que dado os parametros de uma venda dá update na estrutura faturação
void update_faturacao(Faturacao f1, int filial, int mes, double preco, int unidades){
	f1.tabela_faturacao[mes][4]+=preco*unidades;
	f1.tabela_faturacao[mes][filial]+=preco*unidades;
	f1.total_faturado+=preco*unidades;
}