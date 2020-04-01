#include "../include/catalogo_produtos.h"


#define LETRAS 26
#define HASHNUMBER 151

struct produtos{
	AVL tabela_produtos[LETRAS][LETRAS][HASHNUMBER];
	int size[LETRAS];
};

// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hF_produtos(int index[3], char value[]){
	int s = 0, c = 0;
	for(int i = 2; i < strlen(value); i++){
		s = value[i]; c+=s; c*=s;
	}

	c = abs(c % HASHNUMBER);

	index[0] = value[0] - 65;
	index[1] = value[1] - 65;
	//printf("\tHASH__%c%c%d\n", value[0], value[1], c );
	index[2] = c;
}

// Função que insere um index, de tipologia Produto, numa estrutura de dados
int insert_produto(Produtos p, char id[]){
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	int nID = num_(id,2);
	hF_produtos(index, id);

	p->tabela_produtos[index[0]][index[1]][index[2]] = insert_tree(p->tabela_produtos[index[0]][index[1]][index[2]] , nID, id);
	return index[0];
}

// Função que, aplicando a Hash Funtion, verifica se uma posição da Treetable existe
int search_P(Produtos p, char id[]){
	int r = 0, nID = num_(id,2);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	hF_produtos(index,id);

	r = search_tree(p->tabela_produtos[index[0]][index[1]][index[2]], nID);

	return r;
}

// Função que valida um id de um produto
int valida_produto(char * id){
	int r = 0;

	if(strlen(id) != 6) return 0;

	if(isupper(id[0]) && isupper(id[1]))							
		if(('1'<=id[2]) && (id[2]<='9'))
			for(int n = 3; n < 6; n++){
				if(isdigit(id[n])) r = 1;
				else return 0;
			}

	return r;
}

// Função que lê de um ficheiro de produtos
void load_produtos(Produtos p, char* path, int num[2]){
	char linha[7];
	int l1 = 0, i1 = 0, i2 = 0;
	FILE* file = fopen(path , "r");
	
	if(file == NULL){
	  	printf("Error! You tried to read an empty file.");
	  	fclose(file); 
		_exit(0);
	}

	while( fgets(linha, 7, file) ){
		if(valida_produto(linha)){
			l1 = insert_produto(p,linha);
			p->size[l1]++;
			i1++;
		}
		i2++;
	}

	num[0] = i1;
	num[1] = i2; 
	fclose(file);
}

// Função que imprime uma arvore por ordem dos elementos
int fprint_produtos(FILE* fp, AVL a){
	int num = 0;

	if(a){
		num += fprint_produtos(fp,esq(a));
		if(valor(a) > 1){
			fprintf(fp, "%s\r\n", codigo(a));
			num++;
		}
		num += fprint_produtos(fp,dir(a));
	}

	return num; // retorna o num de elementos que printou
}

//Função que escreve um cubo de Trees num ficheiro
int wrFileP (Produtos p, char* path){
	int r = 0;
	FILE* fp = fopen(path, "w+");
	
	if(fp == NULL){
		printf("Error! Couldn't find file point to write Produtos");
		fclose(fp); 
		_exit(0);
	}

	for(int l1 = 0; l1 < LETRAS; l1++)
		for(int l2 = 0; l2 < LETRAS; l2++)
			for(int h = 0; h < HASHNUMBER; h++)
				r += fprint_produtos(fp,p->tabela_produtos[l1][l2][h]);

	fclose(fp);

	return r;
}

//Função que inicializa as estruturas, escreve na posição 2 e 3 do array
Produtos iniciar_produtos(int* num){
	Produtos p = malloc(sizeof(struct produtos));
	int valores[2];

	for (int i = 0; i < LETRAS; i++){
		p->size[i] = 0;
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				p->tabela_produtos[i][j][k] = NULL;
	}
	
	load_produtos(p,"../Produtos.txt",valores);

	num[2] = valores[0];
	num[3] = valores[1];
	return p;
}

//
int get_size(Produtos p, char letra){
	return p->size[letra-'A'];
}

//
int print_simples(String* lista, AVL a, int pos){
	int num = 0;
	if(a){
		num += print_simples(lista,esq(a),pos+num);
		if(valor(a)){
			lista[pos+num] = iniciar_string(codigo(a));
			num++;
		}
		num += print_simples(lista,dir(a),pos+num);
	}

	return num;
}

//
void lista_produtos(Produtos p, char letra, String* lista){
	int r = 0;
	int l1 = letra - 'A';

	for(int l2 = 0; l2 < LETRAS; l2++)
		for(int h = 0; h < HASHNUMBER; h++)
			r += print_simples(lista,p->tabela_produtos[l1][l2][h],r);
}

// Função que liberta o espaço alocado para a estrutura
void free_produtos(Produtos p){
	free(p);
}
