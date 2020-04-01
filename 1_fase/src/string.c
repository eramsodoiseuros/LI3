#include "../include/string.h"

struct string{
	char* id_produto;
};

// 
String iniciar_string(int id, int l1, int l2){
	String s = malloc(sizeof(String));
	printf("->_%c%c%d_<-", l1+'A',l2+'A',id);
	return s;
}


//
void navegador(String* lista, int tamanho){

	for(int i = 0; i < tamanho; i++)
		printf("%s\n", lista[i]->id_produto);
}