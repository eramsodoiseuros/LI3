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
 *	Função que inicia a estrutura filial com os respetivos valores a zero
 *	@param a estrutura filial a iniciar
*/
Filial iniciar_filial();

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
