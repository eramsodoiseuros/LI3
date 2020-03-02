#include "../include/read.h"



//
//				PROBLEMAS A RESOLVER: 5
//



// função que devolve o i e preenche o array tokens
int toktok(char * linha, char** tokens){
	char* tok = NULL;
	tok = strtok(linha, " ");
	int i = 0;

    for(i = 0; tok; i++){
    	if(i < 7)
    		tokens[i] = sdup(tok);
        tok = strtok(NULL," ");
    }

    return i;
}



//
// 				FUNÇÕES DE VALIDAÇÃO
//



// função que valida um id de um produto
int validaProduto(char * id){
	int r = 0;
	if(isupper(id[0]) && isupper(id[1]))							
		if(('1'<=id[2]) && (id[2]<='9'))
			for(int n = 3; n < 5; n++){
				if(isdigit(id[n])) r = 1;
				else return 0;
			}
	return r;
}

// função que valida um id de um cliente
int validaCliente(char * id){
	int r = 0;
	if(isupper(id[0]))	
		if(('1'<=id[1]) && (id[1]<='5'))
			for(int n = 2; n < 4; n++){
				if(isdigit(id[n])) r = 1;
				else return 0;
			}
	return r;
}

// função que valida um id de uma venda
int validaVenda(char* linha, Produtos p, Clientes c){
	int r = 0, i = 0;
	char* tokens[7];

	i = toktok(linha, tokens);

	if(i == 7)
		if( 1 /*função de tratamento*/ )
			if( atof(tokens[1]) <= 999.99 && atof(tokens[1]) >= 0.0 )
				if( atoi(tokens[2]) <= 200 && atoi(tokens[2]) >= 1 )
					if( !strcmp(tokens[3], "N") || !strcmp(tokens[3], "P") )
						if( 1 /*função de tratamento*/ )
							if( atoi(tokens[5]) <= 12 && atoi(tokens[5]) >= 1 )	
								if( atoi(tokens[6]) <= 3 && atoi(tokens[6]) >= 1 )
									r = 1;
	return r;
}



//
//				FUNÇÕES DE LEITURA
//



// Função que lê de um ficheiro de produtos
int load_produtos(Produtos p, char* path){
	char linha[7];
	int i = 0;
	FILE* file = fopen(path , "r");
	
	if(file == NULL){
	  	printf("Error! You tried to read an empty file.");
	  	fclose(file); 
		_exit(0);
	}

	while( fgets(linha, 7, file) ){
		if(validaProduto(linha)){
			// função de tratamento
			i++;
		}
	}

	fclose(file);
	return i;
}

// Função que lê de um ficheiro de clientes
int load_clientes(Clientes c, char* path){
	char linha[6];
	int i = 0;
	FILE* file = fopen(path , "r");
	
	if(file == NULL){
      	printf("Error! You tried to read an empty file.");   
      	fclose(file);
     	_exit(0);            
    }

	while( fgets(linha, 6, file) ){
		if(validaCliente(linha)){
			// função de tratamento
			i++;
		}
	}

	fclose(file);
	return i;
}

// Função que lê de um ficheiro de vendas
int loadstruct_Vendas(char* path, Produtos p, Clientes c){
	char linha[33], *original = malloc(sizeof(char)*33);
	int i = 0;
	FILE* file = fopen(path , "r");

	if(file == NULL){
		printf("Error! You tried to read an empty file.");
		fclose(file);
		_exit(0);
	}

	while( fgets(linha, 32, file) ){
		strcpy(original, linha);
		if(validaVenda(linha, p, c)){
			// função de tratamento
			i++;
		}
	}
	
	free(original);
	fclose(file);	
	return i;
}