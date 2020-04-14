#include "../include/filial.h"
#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"

struct filial{
	int n_clientes[4];
	int n_PC; // número de produtos comprados

	RP produtos;
	RC clientes;
};

// Função que inicia a estrutura filial com os respetivos valores a zero
Filial iniciar_filial(){
	Filial f = malloc(sizeof(struct filial));

	for(int i = 0; i < 4; i++)
		f->n_clientes[i] = 0;
	f->n_PC = 0;

	f->produtos = iniciar_RP();
	f->clientes = iniciar_RC();

	return f;
}

// Função que
void f_produto(Filial f, char* id){
	insert_p(f->produtos, id);
}

// Função que
void f_cliente(Filial f, char* id){
	insert_c(f->clientes, id);
}

// Função que
RP get_produtos(Filial f){
	return f->produtos;
}

// Função que
RC get_clientes(Filial f){
	return f->clientes;
}