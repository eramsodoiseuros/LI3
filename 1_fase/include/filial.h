#ifndef __FILIAL_H__
#define __FILIAL_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"

typedef struct filial* Filial;


/**
 *	Função que dado os parametros de uma venda dá update na estrutura filial
 *	@param a estrutura filial a preencher, a filial, o mês, o preço correspondente a um certo produto,
 	o número de unidades, o código do produto e o código do cliente
*/
void update_filial(Filial f1, int filial, int mes, double preco, int unidades, char NP, char* produto, char* cliente);

/**
 *	Função que 
 *	@param 
 */
void f_produto(Filial f, char* id);

/**
 *	Função que 
 *	@param 
 */
void f_cliente(Filial f, char* id);

/**
 *	Função que inicia a estrutura filial com os respetivos valores a zero
 *	@param a estrutura filial a iniciar
*/
Filial iniciar_filial();

/**
 *	Função que 
 *	@param 
 */
RP get_produtos(Filial f);

/**
 *	Função que 
 *	@param 
 */
RC get_clientes(Filial f);


#endif
