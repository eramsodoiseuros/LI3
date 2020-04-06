#ifndef __FILIAL_H__
#define __FILIAL_H__

typedef struct filial* Filial;


// #include

/**
 *	Função que dado os parametros de uma venda dá update na estrutura filial
 *	@param a estrutura filial a preencher, a filial, o mês, o preço correspondente a um certo produto,
 	o número de unidades, o código do produto e o código do cliente
*/
void update_filial(Filial f1, int filial, int mes, double preco, int unidades, char* produto, char* cliente);

/**
 *	Função que inicia a estrutura filial com os respetivos valores a zero
 *	@param a estrutura filial a iniciar
*/
Filial iniciar_faturacao();


#endif
