#ifndef __READ_H__
#define __READ_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * Função que valida um id de um produto
 * @param string a validar
 * @param 1 caso seja valida, 0 caso seja inválida
 */
int validaProduto(char * id);

/**
 * Função que valida um id de um cliente
 * @param string a validar
 * @param 1 caso seja valida, 0 caso seja inválida
 */
int validaCliente(char * id);

/**
 * Função que valida uma linha de Vendas
 * @param string a validar, a estrutura de produtos existentes e a estrutura de clientes existentes
 * @param 1 caso seja valida, 0 caso seja inválida
 */
int validaVenda(char* linha, Produtos p, Clientes c);

/**
 * Função que lê de um ficheiro de produtos
 * @param estrutura de produtos a preencher, e o path para o ficheiro que se pretende ler
 * @param número de produtos válidos
 */
int load_produtos(Produtos p, char* path);

/**
 * Função que lê de um ficheiro de clientes
 * @param estrutura de clientes a preencher, e o path para o ficheiro que se pretende ler
 * @param número de clientes válidos
 */
int load_clientes(Clientes c, char* path);

/**
 * Função que lê de um ficheiro de vendas
 * @param path para o ficheiro que se pretende ler, estrutura de produtos existentes, estrutura de clientes existentes
 * @param número de linhas válidas
 */
int load_vendas(char* path, Produtos p, Clientes c);

#endif
