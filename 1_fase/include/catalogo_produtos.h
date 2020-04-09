#ifndef __CATALOGO_PRODUTOS_H__
#define __CATALOGO_PRODUTOS_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AVL.h"
#include "filial.h"

typedef struct produtos* Produtos;

/**
 *	Função que verifica se um id existe na estrutura
 *	@param estrutura produtos e o id a verificar
 *	@param 1 caso exista, 0 caso não exista
 */
int search_P(Produtos p, char* id);

/**
 *	Função que valida um id de um produto
 *	@param string a validar
 *	@param 1 caso seja valida, 0 caso seja inválida
 */
int valida_produto(char * id);

/**
 *	Função que inicializa as estruturas, escreve na posição 2 e 3 do array
 *	@param o array para escrever e a estrutura produtos
 */
Produtos iniciar_produtos(int* num, Filial f);

/**
 *	Função que cria uma lista de produtos validos
 *	@param estrutura com os produtos, e letra dos produtos pretendidos
 *	@param a lista de produtos começados por uma letra
 */
void lista_produtos(Produtos p, char letra, String* lista);

/**
 *	Função que devolve o numero de produtos com uma determinada letra
 *	@param estrutura com os produtos, e letra dos produtos pretendidos
 *	@param o número de produtos começados por uma letra
 */
int get_size(Produtos p, char letra);

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param a estrutura a libertar
 */
void free_produtos(Produtos p);


#endif
