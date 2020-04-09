#ifndef __REGISTOS_PRODUTO_H__
#define __REGISTOS_PRODUTO_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct registos_produto* RP;
typedef struct produto* Produto;


/**
 *	Função que inicializa um registo produto
 *	@param o produto
 */
Produto iniciar_produto();
/**
 *	Função que insere um index, de tipologia Produto, numa estrutura de dados
 *	@param 
 */
int insert_p(RP p, char* id);

/**
 *	Função que 
 *	@param 
 */
void update_produto(RP p, char* produto, int filial, int mes, double preco, int unidades, char* cliente, char NP);

/**
 *	Função que 
 *	@param 
 */
RP iniciar_RP();

#endif
