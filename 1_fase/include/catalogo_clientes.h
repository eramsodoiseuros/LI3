#ifndef __CATALOGO_CLIENTES_H__
#define __CATALOGO_CLIENTES_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct clientes* Clientes;
typedef struct cliente* Cliente;

/**
 *	Função que inicializa um registo cliente
 *	@param o cliente
 */
Cliente iniciar_cliente();

/**
 *	Função que verifica se um id existe na estrutura
 *	@param estrutura clientes e o id a verificar
 *	@param 1 caso exista, 0 caso não exista
 */
int search_C(Clientes c, char id[]);

/**
 *	Função que valida um id de um cliente
 *	@param string a validar
 *	@param 1 caso seja valida, 0 caso seja inválida
 */
int valida_cliente(char * id);

/**
 *	Função que inicializa as estruturas, escreve na posição 0 e 1 do array
 *	@param o array para escrever e a estrutura clientes
 */
Clientes iniciar_clientes(int* num);

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param a estrutura a libertar
 */
void free_clientes(Clientes c);

/**
 *	Função que 
 *	@param 
 */
void update_cliente(Clientes c, char* cliente, int filial, int mes, double preco, int unidades, char* produto, char NP);

#endif
