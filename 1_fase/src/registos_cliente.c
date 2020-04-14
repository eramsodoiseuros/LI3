#include "../include/registos_cliente.h"

#define LETRAS 26
#define HASHNUMBER 599

struct registos_cliente{
	AVL tabela_cliente[LETRAS][HASHNUMBER];
};

struct cliente{
    int comprou_in[5];
    int vezes_comprou[12][3];
    int size_comprados;
    // void* lista_comprados[12]; 
};

// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hF_c(int index[2], char value[]){
	int s = 0, c = 0;
	for(int i = 1; i < strlen(value); i++){
		s = value[i]; c+=s; c*=s;
	}

	c = abs(c % HASHNUMBER);

	index[0] = value[0] - 65;
	index[1] = c;
}

// Função que insere um index, de tipologia Cliente, numa estrutura de dados
void insert_c(RC c, char* id){
	int index[2]; index[0] = 0, index[1] = 0;
	int nID = num_(id,1);

	hF_c(index, id);

	c->tabela_cliente[index[0]][index[1]] = insert_tree(c->tabela_cliente[index[0]][index[1]], nID, id, 'c');
}

// Função que inicializa um cliente
Cliente iniciar_cliente(){
	Cliente c = malloc(sizeof(struct cliente));

	for(int i = 0; i < 5; i++)
		c->comprou_in[i] = 0;
	
	for(int m = 0; m < 12; m++)
		for(int i = 0; i < 3; i++)
			c->vezes_comprou[m][i] = 0;

	c->size_comprados = 0;

	return c;
}

// Função que
void update_registo_c(Cliente c, int filial, int mes, double preco, int unidades, char* produto, char NP){
	c->comprou_in[0]++;
	c->comprou_in[filial]++;
	
	if(c->comprou_in[1] && c->comprou_in[2] && c->comprou_in[3])
		c->comprou_in[4] = 1;

	c->vezes_comprou[mes-1][filial-1]++;
    
    //if(new_produto(c, cp))
    c->size_comprados++;
}

// Função que
void update_cliente(RC c, char* cliente, int filial, int mes, double preco, int unidades, char* produto, char NP){
	int nID = num_(cliente,1);
	int index[2]; index[0] = 0, index[1] = 0;

	hF_c(index,cliente);

	search_update(c->tabela_cliente[index[0]][index[1]], nID, 'c', cliente, filial, mes, preco, unidades, produto, NP);
}

// Função que
RC iniciar_RC(){
	RC c = malloc(sizeof(struct registos_cliente));

	for (int i = 0; i < LETRAS; i++)
		for(int k = 0; k < HASHNUMBER; k++)
			c->tabela_cliente[i][k] = NULL;

	return c;
}

// Função que
int cliente_comprou(RC c, char* cliente, int x){
	int nID = num_(cliente,1);
	int index[2]; index[0] = 0, index[1] = 0;

	hF_c(index,cliente);

	Cliente c2 = search_info(c->tabela_cliente[index[0]][index[1]], nID);

	return c2->comprou_in[x];
}

// Função que
int c_quantos_comprou(RC c, char* cliente){
	int nID = num_(cliente,1);
	int index[2]; index[0] = 0, index[1] = 0;

	hF_c(index,cliente);

	Cliente c2 = search_info(c->tabela_cliente[index[0]][index[1]], nID);

	return c2->size_comprados;
}

// Função que
int c_vezes_comprou(RC c, char* cliente, int m, int f){
	int nID = num_(cliente,1);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	hF_c(index,cliente);

	Cliente c2 = search_info(c->tabela_cliente[index[0]][index[1]], nID);

	return c2->vezes_comprou[m][f];
}

// Função que
int comprou(Cliente c){
	return (c->comprou_in[0] == 0);
}

// Função que
int comprou_tudo(Cliente c){
	return (c->comprou_in[4] == 1);
}

// Função que
Lista_Strings c_comprou_tudo(RC c){
	Lista_Strings lista = malloc(sizeof(Lista_Strings));
	char l1 = 'A';

	for (int i = 0; i < LETRAS; i++)
		for(int k = 0; k < HASHNUMBER; k++)
			search_c(c->tabela_cliente[i][k], lista, l1+i);

	return lista;
}

// Função que
int c_nao_comprou(RC c){
	int r = 0;

	for (int i = 0; i < LETRAS; i++)
		for(int k = 0; k < HASHNUMBER; k++)
			search_n(c->tabela_cliente[i][k], 'c');

	return r;
}