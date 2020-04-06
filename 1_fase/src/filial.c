#include "../include/filial.h"
#include "../include/registos.h"

#define LETRAS 26
#define HASHNUMBER_C 599
#define HASHNUMBER_P 151

struct filial{
	RC r_cliente[LETRAS];
	RP r_produto[LETRAS][LETRAS];

	int n_clientes[4];
	int n_PNC; // número de produtos não comprados

};


// Função que dado os parametros de uma venda dá update na estrutura filial
void update_filial(Filial f1, int filial, int mes, double preco, int unidades, char* produto, char* cliente){

}

// Função que inicia a estrutura filial com os respetivos valores a zero
Filial iniciar_faturacao(){
	Filial f = malloc(sizeof(struct filial));

	for(int i = 0; i< LETRAS; i++)
		f->r_cliente[i] = malloc(sizeof(struct Pair));

	for(int i = 0; i < LETRAS; i++)
		for(int j = 0; j < LETRAS; j++)
			f->r_produto[i][j] = malloc(sizeof(struct Pair));;

	return f;
}

// Função que verifica se um cliente já comprou numa filial
int comprou_in(char* id, Filial f, int filial){

}

// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hf_clientes(int index[2], char value[]){
	int s = 0, c = 0;
	for(int i = 1; i < strlen(value); i++){
		s = value[i]; c+=s; c*=s;
	}

	c = abs(c % HASHNUMBER);

	index[0] = value[0] - 65;
	index[1] = c;
}

// Função que insere um index, de tipologia Cliente, numa estrutura de dados de registos
void insert_cliente(Filial f, char id[]){
	int index[2]; index[0] = 0, index[1] = 0;
	int nID = num_(id,1);

	hf_clientes(index, id);

	c->tabela_clientes[index[0]][index[1]] = insert_tree(c->tabela_clientes[index[0]][index[1]] , nID, id);
}

// Função que verifica se um id existe na estrutura
int search_C(Clientes c, char id[]){
	int r = 0, nID = num_(id,1);
	int index[2]; index[0] = 0, index[1] = 0;

	hF_clientes(index,id);

	r = search_tree(c->tabela_clientes[index[0]][index[1]], nID);
	return r;
}
