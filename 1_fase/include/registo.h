#ifndef __AVL_H__
#define __AVL_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct arvore_registo* Registo;

// Função strdup criada para evitar warnings
char* sdup(const char *s);

/**
 *	Função que inicia a estrutura string
 *	@param o numero do produto, a primeira letra e a segunda letra
 *	@param o apontador para a string
 */
String iniciar_string(char* id);

/**
 *	Função que cria um Nodo novo da arvore, ou até mesmo uma arvore nova, com um dado valor
 *	@param valor a inserir na arvore
 *	@param apontador para a estrutura
 */
Registo create_nodo(int valor, char* id);

/**
 *	Função que recursivamente insere um valor numa AVL
 *	@param a arvore e um valor a adicionar na arvore
 *	@param apontador para a estrutura
 */
Registo insert_tree(Registo a, int val, char* id);

/**
 *	Função que procura um elemento numa arvore binaria
 *	@param a arvore e um valor a procurar na arvore
 *	@param 1 caso o valor exista, 0 caso não exista
 */
int search_tree(Registo a, int id);

/**
 *	Função que transforma uma substring num numero
 *	@param string e um inteiro
 *	@param inteiro
 */
int num_(char string[], int index);

#endif
