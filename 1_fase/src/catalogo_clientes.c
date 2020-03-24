#include "../include/catalogo_clientes.h"
#include "../include/AVL.h"

/*

No ficheiro Clientes.txt cada linha representa o código de um cliente identificado no hipermercado, sendo cada
código de cliente formado por uma letra maiúscula e 4 dígitos que representam um inteiro entre 1000 e 5000, cf. os exemplos:

F2916 / W1219 / F4999

*/

int LETRAS = 26;
int HASHNUMBER = 599;

struct clientes{
	AVL tabela_clientes[26][HASHNUMBER];
};

// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hF_clientes(int index[2], char value[]){
	int s = 0, c = 0;
	for(int i = 1; i < strlen(value); i++){
		s = value[i]; c+=s; c*=s;
	}

	c = abs(c % HASHNUMBER);

	index[0] = value[0] - 65;
	//printf("\tHASH__%c%d\n", value[0], c );
	index[1] = c;
}

// Função que insere um index, de tipologia Cliente, numa estrutura de dados
void insert_cliente(Clientes c, char id[]){
	int index[2]; index[0] = 0, index[1] = 0;
	int nID = num_(id,1);

	hF_clientes(index, id);

	insert_tree(c->tabela_clientes[index[0]][index[1]] , nID);
}

// Função que verifica se um id existe na estrutura
int search_C(Clientes c, char id[]){
	int r = 0, nID = num_(id,1);
	int index[2]; index[0] = 0, index[1] = 0;

	hF_clientes(index,id);

	r = search_tree(c->tabela_clientes[index[0]][index[1]], nID);
	return r;
}

// Função que valida um id de um cliente
int valida_cliente(char * id){
	int r = 0;

	if(strlen(id) != 5) return 0;

	if(isupper(id[0])){
		if(('1'<=id[1]) && (id[1]<='4'))
			for(int n = 2; n < 5; n++){
				if(isdigit(id[n])) r = 1;
				else return 0;
			}

		if('5'<=id[1])
			for(int n = 2; n < 5; n++){
				if(id[n] != '0') return 0;
				else r = 1;
			}
	}

	return r;
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
		if(valida_cliente(linha)){
			insert_cliente(c,linha);
			i++;
		}
	}

	fclose(file);
	return i;
}

// Função que imprime uma arvore num ficheiro por ordem dos elementos
int fprint_clientes(FILE* fp, int l1, AVL a){
	char pL = l1+'A';
	int num = 0;

	if(a){
		num += fprint_clientes(fp,l1,esq(a));
		if(valor(a) > 1){
			fprintf(fp,"%c%d\r\n", pL,valor(a));
			num++;
		}
		num += fprint_clientes(fp,l1,dir(a));
	}

	return num;  // retorna o num de elementos que printou
}

// Função que imprime num ficheiro a estrutura de clientes
int  wrFileC (Clientes c, char* path){
	int r = 0;
	FILE* fp = fopen(path, "w+");
	
	if(fp == NULL){
		printf("Error! Couldn't find file point to write Clientes");
		fclose(fp); 
		_exit(0);
	}
	
	for(int letra = 0; letra < LETRAS; letra++)
		for(int h = 0; h < HASHNUMBER; h++)
			r += fprint_clientes(fp,letra,c->tabela_clientes[letra][h]);

	fclose(fp);	

	return r;
}

// Função que inicializa as estruturas, escreve na posição 0 e 1 do array
void init_Clientes(int* num, Clientes c){

	for (int i = 0; i < LETRAS; i++)
		for (int j = 0; j < HASHNUMBER; j++)
			c->tabela_clientes[i][j] = create_nodo(1);

	num[0] = load_clientes(c,"../Clientes.txt");
	num[1] = wrFileC(c,"../ClientesVálidos.txt");
}

// Função que liberta o espaço alocado para a estrutura
void free_clientes(Clientes c){
	free(c);
}