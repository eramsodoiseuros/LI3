#include "../include/navegador.h"


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
