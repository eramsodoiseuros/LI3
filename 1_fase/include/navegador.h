#ifndef __NAVEGADOR_H__
#define __NAVEGADOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define Pagsize 10
#define buffsize 200

#define RESET  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct *Strings;


/**
 *	Função que navega numa struck string
 *	@param estrutura string a ler
 */
void navegador(Strings s);


#endif
