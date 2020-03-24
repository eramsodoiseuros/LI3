#ifndef __CATALOGO_VENDAS_H__
#define __CATALOGO_VENDAS_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "catalogo_produtos.h"
#include "catalogo_clientes.h"
#include "filial.h"
#include "faturacao.h"


/**
 *	Função que valida uma linha de Vendas
 *	@param string a validar, a estrutura de produtos existentes e a estrutura de clientes existentes
 *	@param 1 caso seja valida, 0 caso seja inválida
 */
int validaVenda(char* linha, Produtos p, Clientes c);

/**
 *	Função que lê de um ficheiro de vendas
 *	@param path para o ficheiro que se pretende ler, estrutura de produtos existentes, estrutura de clientes existentes
 *	@param número de linhas válidas
 */
int load_vendas(char* path, Produtos p, Clientes c);

/**
 *	Função que preenche as estruturas Filial e Faturação, escreve na posição 4 e 5 do array
 *	@param o array a preencher na posição 4 e 5, a estrutura de produtos válidos, a estrutura de clientes válidos,
 	a estrutura filial a preencher e a estrutura faturação a preencher
*/
void init_Vendas(int num[6], Produtos p, Clientes c, Filial f1, Faturacao f2);

#endif
