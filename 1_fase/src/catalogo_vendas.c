#include "../include/catalogo_vendas.h"

/*

O ficheiro que será a maior fonte de dados do projecto designa-se por Vendas_1M.txt, no qual cada linha representa o registo de uma venda efectuada numa
qualquer das 3 filiais da Distribuidora. Cada linha (a que chamaremos compra ou venda, o que apenas depende do ponto de vista) será formada por um código
de produto, um preço unitário decimal (entre 0.0 e 999.99), o número inteiro de unidades compradas (entre 1 e 200), a letra N ou P conforme tenha sido uma
compra Normal ou uma compra em Promoção, o código do cliente, o mês da compra (1 .. 12) e a filial (de 1 a 3) onde a venda foi realizada, cf. os exemplos seguintes:

KR1583 77.72 128 P L4891 2 1 / QQ1041 536.53 194 P X4054 12 3 / OP1244 481.43 67 P Q3869 9 1
JP1982 343.2 168 N T1805 10 2 / IZ1636 923.72 193 P T2220 4 2 / AA1636 923.72 193 N A2220 4 2

*/


//Função strdup criada para evitar warnings
char* sdup(const char *s){
	size_t tamanho = strlen (s) + 1;
	void *novo = malloc(tamanho);
	if(novo == NULL)
		return NULL;
	return (char *) memcpy (novo, s, tamanho);
}

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

// função que valida um id de uma venda
int validaVenda(char* linha, Produtos p, Clientes c){
	int r = 0, i = 0;
	char* tokens[7];

	i = toktok(linha, tokens);

	if(i == 7)
		if( atof(tokens[1]) <= 999.99 && atof(tokens[1]) >= 0.0 )
			if( atoi(tokens[2]) <= 200 && atoi(tokens[2]) >= 1 )
				if( tokens[3][0] == 'N' || tokens[3][0] == 'P')
					if( atoi(tokens[5]) <= 12 && atoi(tokens[5]) >= 1 )	
						if( atoi(tokens[6]) <= 3 && atoi(tokens[6]) >= 1 )
							if( 1 /*função de tratamento*/ ) // clientes
								if( 1 /*função de tratamento*/ ) // produtos
									r = 1;
	return r;
}

// Função que lê de um ficheiro de vendas
int load_vendas(char* path, Produtos p, Clientes c /*, Filial f1, Faturacao f2*/){
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

// Função que inicializa as estruturas, escreve na posição 4 e 5 do array
void init_Vendas(int* num, Produtos p, Clientes c /*, Filial f1, Faturacao f2*/){

	// num[4] = load_vendas("../Vendas_1M.txt", p, c);
	// num[5] = wrFileV(v->vendas, "../VendasValidas.txt");
}
