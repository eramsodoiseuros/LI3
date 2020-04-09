#include "../include/filial.h"
#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"

struct filial{
	int n_clientes[4];
	int n_PC; // número de produtos comprados

	RP produtos;
	RC clientes;
};

// Função que dado os parametros de uma venda dá update na estrutura filial
void update_filial(Filial f1, int filial, int mes, double preco, int unidades, char NP, char* produto, char* cliente){
	int i = 0;
	i++;
}

// Função que inicia a estrutura filial com os respetivos valores a zero
Filial iniciar_filial(){
	Filial f = malloc(sizeof(struct filial));

	for(int i = 0; i < 4; i++)
		f->n_clientes[i] = 0;
	f->n_PC = 0;

	return f;
}

// Função que verifica se um cliente já comprou numa filial
int comprou_in(char* id, Filial f, int filial){
	return 0;
}