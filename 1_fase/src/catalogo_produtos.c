#include "../include/catalogo_produtos.h"
#include "../include/AVL.h"


struct produtos{
	AVL tabela_produtos[26][26][151];
};

// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hF_produtos(int index[3], char value[]){
	int s = 0, c = 0;
	for(int i = 2; i < strlen(value); i++){
		s = value[i]; c+=s; c*=s;
	}

	c = abs(c % 151);

	index[0] = value[0] - 65;
	index[1] = value[1] - 65;
	//printf("\tHASH__%c%c%d\n", value[0], value[1], c );
	index[2] = c;
}

// Função que insere um index, de tipologia Produto, numa estrutura de dados
void insert_produto(Produtos p, char id[]){
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	int nID = num_(id,2);
	hF_produtos(index, id);

	insert_tree(p->tabela_produtos[index[0]][index[1]][index[2]] , nID);
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
		if(valida_produto(linha)){
			insert_produto(p,linha);
			i++;
		}
	}

	fclose(file);
	return i;
}

// Função que imprime uma arvore por ordem dos elementos
int fprint_produtos(FILE* fp, int l1, int l2, AVL a){
	char pL = l1+'A', sL = l2+'A'; 
	int num = 0;

	if(a){
		num += fprint_produtos(fp,l1,l2,esq(a));
		if(valor(a) > 1){
			fprintf(fp,"%c%c%d\r\n", pL, sL,valor(a));
			num++;
		}
		num += fprint_produtos(fp,l1,l2,dir(a));
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

	for(int l1 = 0; l1 < 26; l1++)
		for(int l2 = 0; l2 < 26; l2++)
			for(int h = 0; h < 151; h++)
				r += fprint_produtos(fp,l1,l2,p->tabela_produtos[l1][l2][h]);

	fclose(fp);

	return r;
}

//Função que inicializa as estruturas, escreve na posição 2 e 3 do array
void init_Produtos(int* num, Produtos p){

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			for(int k = 0; k < 151; k++)
				p->tabela_produtos[i][j][k] = create_nodo(1);
	
	num[2] = load_produtos(p,"../Produtos.txt");
	num[3] = wrFileP(p,"../ProdutosVálidos.txt");
}


// Função que liberta o espaço alocado para a estrutura
void free_produtos(Produtos p){
	free(p);
}
