#include "../include/AVL.h"

struct arvore{
	int valor; 
	struct arvore *esq, *dir;
	int altura;
};


// Função que imprime uma arvore por ordem dos elementos
int print_AVL(AVL arvore){
	int num = 0;
	if(arvore){
		num += print_AVL(arvore->esq);
		printf("%d\n", arvore->valor); num++;
		num += print_AVL(arvore->dir);
	}

	return num;
}

//Função que devolve o lado esquerdo de uma arvore
AVL esq(AVL t){
    return t->esq;
}

//Função que devolve o lado direito de uma arvore
AVL dir(AVL t){
    return t->dir;
}

//Função que devolve o valor de uma arvore
int valor(AVL t){
    return t->valor;
}

// Função que indica o maior de dois números
int max(int a, int b){ 
    return (a > b)? a : b;
}

// Função que indica a altura de uma arvore
int altura(AVL a){
    return (a == NULL)? 0 : a->altura;
}

// Função que cria um Nodo novo da arvore, ou até mesmo uma arvore nova, com um dado valor
AVL create_nodo(int valor){
    AVL new = malloc(sizeof(struct arvore));

    new->valor = valor;
    new->esq = NULL;
    new->dir = NULL;
    new->altura = 1;

    return(new);
}

// Função que balança a arvore para a direita
AVL rotate_dir(AVL y){
    AVL x = y->esq;
    AVL T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir))+1;
    x->altura = max(altura(x->esq), altura(x->dir))+1;

    return x; 
}
  
// Função que balança a arvore para a esquerda
AVL rotate_esq(AVL x){ 
    AVL y = x->dir;
    AVL T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir))+1;
    y->altura = max(altura(y->esq), altura(y->dir))+1;

    return y;
}

// Função que indica a diferença do balanceamento da arvore
int difBalance(AVL a){
    return (a == NULL)? 0 : altura(a->esq) - altura(a->dir);
}

// Função que recursivamente insere um valor numa AVL
AVL insert_tree(AVL a, int val){
	int balance;

    if(a == NULL){
        AVL new = create_nodo(val);
    	return(new);
    }

    if(val < a->valor) a->esq = insert_tree(a->esq, val);
    else if(val > a->valor) a->dir = insert_tree(a->dir, val);
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

// Função que procura um elemento numa arvore binaria
int search_tree(AVL a, int id){
	int r;
	if(a == NULL) r = 0;
	else{
		if(id == a->valor) r = 1;
		else{
			if(id < a->valor) r = search_tree(a->esq, id);
			else r = search_tree(a->dir, id);
		}
	}

	return r;
}

// Função que transforma uma substring num numero
int num_(char string[], int index){
	return atoi(string+index);
}
