#ifndef __AVL_H__
#define __AVL_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct arvore* AVL;

typedef struct string* String;

char* getString (String s);

//Função strdup criada para evitar warnings
char* sdup(const char *s);

/**
 *	Função que inicia a estrutura string
 *	@param o numero do produto, a primeira letra e a segunda letra
 *	@param o apontador para a string
 */
String iniciar_string(char* id);

/**
 *	Função que cria um Nodo novo da arvore, ou até mesmo uma arvore nova, com um dado valor
 *	@param valor a inserir na arvore, tipo da arvore
 *	@param apontador para a estrutura
 */
AVL create_nodo(int valor, char* id, char tipo);

/**
 *	Função que recursivamente insere um valor numa AVL
 *	@param a arvore e um valor a adicionar na arvore, tipo da arvore
 *	@param apontador para a estrutura
 */
AVL insert_tree(AVL a, int val, char* id, char tipo);

/**
 *	Função que procura um elemento numa arvore binaria
 *	@param a arvore e um valor a procurar na arvore
 *	@param 1 caso o valor exista, 0 caso não exista
 */
int search_tree(AVL a, int id);

/**
 *	Função que transforma uma substring num numero
 *	@param string e um inteiro
 *	@param inteiro
 */
int num_(char string[], int index);

/**
 *	Função que devolve o lado esquerdo de uma arvore
 *	@param o apontador para a estrutura
 *	@param o apontador para a arvore da esquerda
 */
AVL esq(AVL a);

/**
 *	Função que devolve o lado direito de uma arvore
 *	@param o apontador para a estrutura
 *	@param o apontador para a arvore da direita
 */
AVL dir(AVL a);

/**
 *	Função que devolve o valor de uma arvore
 *	@param o apontador para a estrutura
 *	@param o valor da raiz da arvore
 */
int valor(AVL a);

/**
 *	Função que devolve a string de uma arvore
 *	@param o apontador para a estrutura
 *	@param a string da raiz da arvore
 */
char* codigo(AVL a);

void* search_update(AVL a, int id);

#endif
