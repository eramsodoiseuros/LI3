#ifndef __CATALOGO_PRODUTOS_H__
#define __CATALOGO_PRODUTOS_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct produtos* Produtos;


/**
 * Função que verifica se um id existe na estrutura
 * @param estrutura produtos e o id a verificar
 * @param 1 caso exista, 0 caso não exista
 */
int search_P(Produtos p, char id[]);

/**
 * Função que valida um id de um produto
 * @param string a validar
 * @param 1 caso seja valida, 0 caso seja inválida
 */
int valida_produto(char * id);

/**
 * Função que lê de um ficheiro de produtos
 * @param estrutura de produtos a preencher, e o path para o ficheiro que se pretende ler
 * @param número de produtos válidos
 */
int load_produtos(Produtos p, char* path);

/**
 * Função que inicializa as estruturas, escreve na posição 2 e 3 do array
 * @param o array para escrever e a estrutura produtos
 */
void init_produtos(int* num, Produtos p);

/**
 * Função que liberta o espaço alocado para a estrutura
 * @param a estrutura a libertar
 */
void free_produtos(Produtos p);


#endif
