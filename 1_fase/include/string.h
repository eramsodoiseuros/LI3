#ifndef __STRING_H__
#define __STRING_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct string* String;

/**
 *	Função que inicia a estrutura string
 *	@param o numero do produto, a primeira letra e a segunda letra
 *	@param o apontador para a string
 */
String iniciar_string(int id, int l1, int l2);

void navegador(String* lista, int tamanho);

#endif
