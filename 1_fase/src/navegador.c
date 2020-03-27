#include "../include/navegador.h"


/**

void navegador (Strings s){


	int numP = 30, pag = 1, index = 0, conta = 0,op;
	
	while(1){

		conta = 0;

		printf("\n\n");
		printf("%s************ Página %d ************%s\n",KBLU,pag, RESET);

		while(conta < s.file[index]){
			if(index <= s.inUse){
					printf("%s \t-> %s %d  - %s",KCYN, RESET, index,  s.string[index]);
					conta++;
					index++;
			}
			else break;
		}

		printf("%s**********************************%s\n",KBLU, RESET);
		printf("\n%s[1]%s = Página anterior\n%s[2]%s = Página seguinte\n%s[0]%s = Sair \n",KCYN, RESET,KCYN, RESET,KCYN, RESET);

		scanf("%d", &op );
		if(op == 1){
			if(index >= 0){
				index = index - 2*(s.file[index])-1;
				if(index < 0) index = 0;
				if(pag > 1) pag--;
			}
		}

		if(op == 2){
			if(index <= s.inUse){
				index++;;
				if(index > s.inUse) index = s.inUse;
				pag++;
			}
		}

		if( op == 0){
			break;
		}	
	}
	printf("%s\n","Terminou!!!!!!!" );



}

typedef struct Strings
{
	char** string;
	char* file;
	int nr;

}Strings;
**/

void navegador(Strings s){
int ind=Pagsize;
int val=1;
int exit=0;
char* scanS=malloc(sizeof(char)*buffsize);
int validstr=1;
int scanout=1;

while(exit!=1){

	
 if(scanout==0 || ind>s.nr || ind<0 || val==0){
    val=1;
    if(s.file!=NULL)printf("%s\n",s.file);
    printf("Página inválida ou não existente\n");
  }

 else{
   if(s.file != NULL) printf("%s\n",s.file);
   printf("%s************ Página %d ************%s\n",KBLU,(ind/10), RESET);

  for(int i=ind-Pagsize; i<ind && i<s.nr; i++)
   printf("%s \n",s.string[i]);

  }

  printf("\n");
  printf("Inserir número página: %s(exit para sair) \n",KBLU);
  scanout=read(0,scanS,buffsize);
  scanS=strtok(scanS," \n");

  validstr=atoi(scanS);
  printf("\n");

  if(strcmp(scanS,"exit") == 0) {exit = 1;}
  else if(strcmp(scanS,"proximo") == 0 && ind<s.nr-Pagsize) ind = ind+Pagsize;
  else if(strcmp(scanS,"anterior") == 0 && ind>Pagsize) ind = ind-Pagsize;
  else if(validstr==0) val = 0;
  else if(validstr!=0) ind = validstr*Pagsize;
 }
 free(scanS);
}
