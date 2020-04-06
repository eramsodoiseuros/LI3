#include "../include/registos.h"

struct cliente{
	
	char* id;
	int comprou_in[4];

	int size_comprados;
	Produto* lista_comprados[12]; 

}*Cliente;

struct arvore_RC{
	int valor;
    struct cliente *info_cliente;
	struct arvore_RC *esq, *dir;
	int altura;
};


// Função que indica o maior de dois números
int max(int a, int b){ 
    return (a > b)? a : b;
}

// Função que indica a altura de uma arvore
int altura(RC a){
    return (a == NULL)? 0 : a->altura;
}

//Função strdup criada para evitar warnings
char* sdup(const char *s){
    size_t tamanho = strlen (s) + 1;
    void *novo = malloc(tamanho);
    if(novo == NULL)
        return NULL;
    return (char *) memcpy (novo, s, tamanho);
}

Cliente novo_cliente(char* id){
	Cliente cliente = malloc(sizeof(struct cliente));

	cliente->id = sdup(id);
	for(int i = 0; i < 4; i++)
		cliente->comprou_in[i] = 0;

	cliente->size_comprados = 0;
	cliente->lista_comprados = malloc(sizeof(Produto*)*12);

	return cliente;
}

// Função que cria um Nodo novo da arvore, ou até mesmo uma arvore nova, com um dado valor
RC novo_nodo_RC(int valor, char* id){
    RC new = malloc(sizeof(struct arvore_RC));

    new->valor = valor;

    new->info_cliente = novo_cliente(id);

    new->esq = NULL;
    new->dir = NULL;
    new->altura = 1;

    return(new);
}

// Função que balança a arvore para a direita
RC rotate_dir(RC y){
    RC x = y->esq;
    RC T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir))+1;
    x->altura = max(altura(x->esq), altura(x->dir))+1;

    return x; 
}
  
// Função que balança a arvore para a esquerda
RC rotate_esq(RC x){ 
    RC y = x->dir;
    RC T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir))+1;
    y->altura = max(altura(y->esq), altura(y->dir))+1;

    return y;
}

// Função que indica a diferença do balanceamento da arvore
int difBalance(RC a){
    return (a == NULL)? 0 : altura(a->esq) - altura(a->dir);
}

// Função que recursivamente insere um valor numa RC
RC insert_tree_RC(RC a, int val, char* id){
	int balance;

    if(a == NULL){
        RC new = novo_nodo_RC(val,id);
    	return(new);
    }

    if(val < a->valor) a->esq = insert_tree_RC(a->esq, val,id);
    else if(val > a->valor) a->dir = insert_tree_RC(a->dir, val,id);
    else return a;
        
    a->altura = 1 + max(altura(a->esq),altura(a->dir));
    balance = difBalance(a);

    if(balance > 1 && val < a->esq->valor)
        return rotate_dir(a);

    if(balance < -1 && val > a->dir->valor)
        return rotate_esq(a);

    if(balance > 1 && val > a->esq->valor){ 
        a->esq = rotate_esq(a->esq);
        return rotate_dir(a);
    }

    if(balance < -1 && val < a->dir->valor){
        a->dir = rotate_dir(a->dir);
        return rotate_esq(a);
    }

    return a;
} 

// Função que procura um elemento numa arvore binaria e realiza o update
int search_update_cliente(RC a, int id, int filial, char* id){
	int r;
	if(a == NULL) r = 0;
	else{
		if(id == a->valor){
			r = 1;
			a->info_cliente->comprou_in[filial]++;
			
			if(a->info_cliente->comprou_in[0] == 0)
				if(a->info_cliente->comprou_in[3] != 0 && a->info_cliente->comprou_in[2] != 0 && a->info_cliente->comprou_in[1] != 0)
					a->info_cliente->comprou_in[0] = 1;
			
			// search_produto(char* id) + update_produto()
		}
		else{
			if(id < a->valor) r = search_tree(a->esq, id);
			else r = search_tree(a->dir, id);
		}
	}

	return r;
}


///////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////


struct produto{

	int vezes_comprado;
	char* id;
	int vendido_in[4];

}*Produto;










// Função que transforma uma substring num numero
int num_(char string[], int index){
	return atoi(string+index);
}
