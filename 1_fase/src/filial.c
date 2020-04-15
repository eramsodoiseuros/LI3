#include "../include/filial.h"
#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"

struct filial{
	RP produtos;
	RC clientes;
};

// Função que inicia a estrutura filial com os respetivos valores a zero
Filial iniciar_filial(){
	Filial f = (Filial) malloc(sizeof(struct filial));

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