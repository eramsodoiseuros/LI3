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
 *	Função que 
 *	@param 
 */
void update_produto(RP p, char* produto, int filial, int mes, double preco, int unidades, char* cliente, char NP);

#endif

