#ifndef __AVL_H__
#define __AVL_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct arvore* AVL;

/**
 * Função que cria um Nodo novo da arvore, ou até mesmo uma arvore nova, com um dado valor
 * @param valor a inserir na arvore
 * @param apontador para a estrutura
 */
AVL create_nodo(int valor);

/**
 * Função que recursivamente insere um valor numa AVL
 * @param a arvore e um valor a adicionar na arvore
 * @param apontador para a estrutura
 */
AVL insert_tree(AVL a, int val);

/**
 * Função que procura um elemento numa arvore binaria
 * @param a arvore e um valor a procurar na arvore
 * @param 1 caso o valor exista, 0 caso não exista
 */
int search_tree(AVL a, int id);

/**
 * Função que transforma uma substring num numero
 * @param string e um inteiro
 * @param inteiro
 */
int num_(char string[], int index);

/**
 * Função que devolve o lado esquerdo de uma arvore
 * @param o apontador para a estrutura
 * @param o apontador para a arvore da esquerda
 */
AVL esq(AVL a);

/**
 * Função que devolve o lado direito de uma arvore
 * @param o apontador para a estrutura
 * @param o apontador para a arvore da direita
 */
AVL dir(AVL a);

/**
 * Função que devolve o valor de uma arvore
 * @param o apontador para a estrutura
 * @param o valor da raiz da arvore
 */
int valor(AVL a);

#endif
