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

typedef struct Strings
{
	char** string;
	char* file;
	int nr;

}Strings;



void navegador(Strings s);
