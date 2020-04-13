#ifndef __CATALOGO_CLIENTES_H__
#define __CATALOGO_CLIENTES_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AVL.h"
#include "filial.h"

#define PATH_C "../Clientes.txt"

typedef struct clientes* Clientes;

void load_(Clientes* c, char* path, int num[2]);

/**
 *	Função que verifica se um id existe na estrutura
 *	@param estrutura clientes e o id a verificar
 *	@param 1 caso exista, 0 caso não exista
 */
int search_C(Clientes c, char* id);

/**
 *	Função que valida um id de um cliente
 *	@param string a validar
 *	@param 1 caso seja valida, 0 caso seja inválida
 */
int valida_cliente(char* id);

/**
 *	Função que inicializa as estruturas, escreve na posição 0 e 1 do array
 *	@param o array para escrever e a estrutura clientes
 */
Clientes iniciar_clientes(int* num, Filial f);

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param a estrutura a libertar
 */
void free_clientes(Clientes c);


#endif
