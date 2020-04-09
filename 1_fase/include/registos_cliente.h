#ifndef __REGISTOS_CLIENTE_H__
#define __REGISTOS_CLIENTE_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct registos_cliente* RC;
typedef struct cliente* Cliente;

/**
 *	Função que inicializa um registo cliente
 *	@param o cliente
 */
Cliente iniciar_cliente();

/**
 *	Função que 
 *	@param 
 */
void update_cliente(RC c, char* cliente, int filial, int mes, double preco, int unidades, char* produto, char NP);

#endif
