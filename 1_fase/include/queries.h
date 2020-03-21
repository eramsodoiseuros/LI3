#ifndef __QUERIES_H__
#define __QUERIES_H__


#include "catalogo_vendas.h"
#include "catalogo_clientes.h"
#include "catalogo_produtos.h"


/**
 * 	Lê e inicializa os valores das estruturas através dos ficheiros
 	Opcionalmente, assumidos por omissão (sendo neste caso os ficheiros anteriormente referidos).
 	O resultado desta leitura deverá ser a apresentação imediata ao utilizador do nome do ficheiro lido e que vai ser usado, o número total de linhas lidas e validadas.
 	Note-se que qualquer nova leitura destes ficheiros deverá de imediato reiniciar e refazer as estruturas de dados em memória como se de uma reinicialização so tratasse.
 	
 * @param estrutura clientes a preencher, estrutura produtos a preencher, array de valores a preencher, inteiro que verifica as ações a tomar
 */
void query_1(Clientes c, Produtos p, int num[6], int r);




/**
 * 	Determinar a lista e o nº total de produtos cujo código se inicia por uma dada letra (maiúscula);

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_2();

/**
 *	Dado um mês e um código de produto, ambos válidos, determinar e apresentar o número total de vendas (nº de registos de venda)
 	e o total facturado com esse produto em tal mês, distinguindo os totais em modo N e os totais em modo P.
	O utilizador deverá decidir se pretende o resultado global ou os resultados filial a filial para todas as 3 filiais.

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_3();

/**
 *	Determinar a lista ordenada dos códigos dos produtos (e o seu número total) que ninguém comprou.
	O utilizador deverá decidir se pretende o resultado global ou os resultados filial a filial para todas as 3 filiais.

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_4();

/**
 *	Determinar a lista ordenada de códigos de clientes que realizaram compras em todas as filiais;

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_5();

/**
 *	Determinar o número de clientes registados que não realizaram compras bem como o número de produtos que ninguém comprou.

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_6();

/**
 *	Dado um código de cliente, criar uma tabela com o número total de produtos comprados (ou seja a soma das quantidades de todas as vendas do produto),
 	mês a mês (para meses em que não comprou a entrada deverá ficar a 0).
	A tabela deverá ser apresentada em ecrã organizada por filial.

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_7();

/**
 *	Dado um intervalo fechado de meses, por exemplo [1..3], determinar o total de vendas (nº de registos de venda) registadas nesse intervalo e o total facturado;

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_8();

/**
 *	Dado um código de produto e uma filial, determinar os códigos (e número total) dos clientes que o compraram, distinguindo entre compra N e compra P;

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_9();

/**
 *	Dado um código de cliente e um mês, determinar a lista de códigos de produtos que mais comprou por quantidade e não por facturação), por ordem descendente;

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_10();

/**
 *	Criar uma lista dos N produtos mais vendidos em todo o ano, indicando o número total de clientes e o número de unidades vendidas, filial a filial;

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_11();

/**
 *	Dado um código de cliente determinar quais os códigos dos N produtos em que mais gastou dinheiro durante o ano;

 * @param O QUE RECEBE
 * @param O QUE RETORNA
*/
// void query_12();

#endif
