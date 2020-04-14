#include "../include/AVL.h"
#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"


struct arvore{
	int valor;             // valor para se poder gerir
    void* info;            // info que realmente se guarda
	struct arvore *esq, *dir;
	int altura;
};


struct lista_strings{
    int in_use;
    int free_space;
    char** lista;
};


struct lista_ordenada{
    int in_use;
    int free_space;
    char** lista;
    int* unidades;
};


//Função strdup criada para evitar warnings
char* sdup(const char *s){
    size_t tamanho = strlen (s) + 1;
    void *novo = malloc(tamanho);
    if(novo == NULL)
        return NULL;
    return (char *) memcpy (novo, s, tamanho);
}

// Função que transforma uma substring num numero
int num_(char string[], int index){
    return atoi(string+index);
}

//////////////////////////////////////////////////
// STRINGS

// Função que inicia uma Lista de Strings
Lista_Strings iniciar_lista(){
    Lista_Strings s = (Lista_Strings) malloc(sizeof(struct lista_strings));
    
    s->in_use = 0;
    s->free_space = 1000;
    s->lista = (char**) malloc(sizeof(char*) * s->free_space);

    return s;
}

// Função que verifica se a Lista está cheia, aloca memória se estiver
void is_full(Lista_Strings s){

    if(s->in_use >= s->free_space){
        s->free_space += 500;
        s->lista = realloc(s->lista, sizeof(char*) * s->free_space);
    }
}

//Função que insere uma string no fim do array Strings (alocando memória se necessário)
void add_lista(Lista_Strings s, char* c){
    is_full(s);
    s->lista[s->in_use++] = sdup(c);
}

int size_lista(Lista_Strings s){
    return s->in_use;
}

char* get_elem(Lista_Strings s, int i){
    return s->lista[i];
}

void delete_lista(Lista_Strings s){
    free(s);
}


//////////////////////////////////////////////////
// STRINGS ORDENADAS

// Função que inicia uma Lista Ordenada
Lista_Ordenada iniciar_lista_ordenada(){
    Lista_Ordenada s = (Lista_Ordenada) malloc(sizeof(struct lista_ordenada));
    
    s->in_use = 0;
    s->free_space = 50;
    s->lista = (char**) malloc(sizeof(char*) * s->free_space);
    s->unidades = (int*) malloc(sizeof(int) * s->free_space);

    return s;
}

// Função que verifica se a Lista está cheia, aloca memória se estiver
void is_full_(Lista_Ordenada s){

    if(s->in_use >= s->free_space){
        s->free_space += 100;
        s->lista = realloc(s->lista, sizeof(char*) * s->free_space);
        s->unidades = realloc(s->lista, sizeof(int) * s->free_space);
    }
}

int existe_in(Lista_Ordenada s, char* c, char tipo){
    int r = -1;
    if(tipo == 'c'){
        for(int aux = 0; aux < s->in_use; aux++)
            if(num_(c, 1) == num_(s->lista[aux], 1))
                if(c[0] == s->lista[aux][0])
                    r = aux;
    }
    if(tipo == 'p'){
        for(int aux = 0; aux < s->in_use; aux++)
            if(num_(c, 2) == num_(s->lista[aux], 2))
                if(c[0] == s->lista[aux][0])
                    if(c[1] == s->lista[aux][1])
                        r = aux;
    }

    return r;
}

//Função que insere uma string no fim do array Strings (alocando memória se necessário)
void add_lista_ordenada(Lista_Ordenada s, char* c, char tipo){
    int r = 0;
    is_full_(s);
    if( (r = existe_in(s,c,tipo)) == -1 )
        s->lista[s->in_use++] = sdup(c);
    else{
        s->lista[r] = sdup(c);
        s->unidades[r]++;
    }
}

int size_lista_ordenada(Lista_Ordenada s){
    return s->in_use;
}

char* get_elem_(Lista_Ordenada s, int i){
    return s->lista[i];
}

void delete_lista_ordenada(Lista_Ordenada s){
    free(s);
}


//////////////////////////////////////////////////
// AVL

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

//Função que devolve a string de uma arvore
char* codigo(AVL t){
    return (char*) t->info;
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
AVL create_nodo(int valor, char* id, char tipo){
    AVL new = malloc(sizeof(struct arvore));

    new->valor = valor;

    if(tipo == 'b'){
        new->info = sdup(id);
    }

    if(tipo == 'c'){
        new->info = iniciar_cliente();
    }

    if(tipo == 'p'){
        new->info = iniciar_produto();
    }

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
AVL insert_tree(AVL a, int val, char* id, char tipo){
	int balance;

    if(a == NULL){
        AVL new = create_nodo(val, id, tipo);
    	return(new);
    }

    if(val < a->valor) a->esq = insert_tree(a->esq, val, id, tipo);
    else if(val > a->valor) a->dir = insert_tree(a->dir, val, id, tipo);
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


/////////////////////////////////////////////////////
// SEARCH_FUNTIONS

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

// Função que procura um elemento numa arvore binaria
void search_update(AVL a, int id, char tipo, char* cliente, int filial, int mes, double preco, int unidades, char* produto, char NP){

    if(tipo == 'c'){
        if(a == NULL);
        else{
            if(id == a->valor){
                update_registo_c( (Cliente) a->info, filial, mes, preco, unidades, produto, NP);
            }
            else{
                if(id < a->valor) search_update(a->esq, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
                else search_update(a->dir, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
            }
        }
    }
    
    if(tipo == 'p'){
        if(a == NULL);
        else{
            if(id == a->valor){
                update_registo_p( (Produto) a->info, filial, mes, preco, unidades, cliente, NP);
            }
            else{
                if(id < a->valor) search_update(a->esq, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
                else search_update(a->dir, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
            }
        }
    }
}

// Função que
int search_n(AVL a, char tipo){
    int r = 0;
    if(tipo == 'c'){
        if(a == NULL) r = 0;
        else{
            if(comprou(a->info))
                r++; 
            r += search_n(a->esq,'c');
            r += search_n(a->dir,'c');
        }
    }
    
    if(tipo == 'p'){
        if(a == NULL) r = 0;
        else{
            if(vendeu(a->info))
                r++; 
            r += search_n(a->esq,'p');
            r += search_n(a->dir,'p');
        }
    }
    return r;
}

// Função que
void search_c(AVL a, Lista_Strings lista, char l1){

    if(a == NULL);
    else{
        if(comprou_tudo(a->info)){
            char* s = malloc(sizeof(char)*6);
            sprintf(s,"%c%d", l1, a->valor);
            add_lista(lista, s); 
        }
        search_c(a->esq, lista, l1);
        search_c(a->dir, lista, l1);
    }
}

// Função que
void search_p(AVL a, Lista_Strings lista, char l1, char l2, int x){

    if(a == NULL);
    else{
        if(vendeu_in(a->info, x)){
            char* s = malloc(sizeof(char)*7);
            sprintf(s,"%c%c%d", l1, l2, a->valor);
            add_lista(lista, s);
        }
        search_p(a->esq, lista, l1, l2, x);
        search_p(a->dir, lista, l1, l2, x);
    }
}

// Função que
void* search_info(AVL a, int id){
    void* r = NULL;

    if(a == NULL);
    else{
        if(id == a->valor){
            r = a->info;
        }
        else{
            if(id < a->valor) search_info(a->esq, id);
            else search_info(a->dir, id);
        }
    }

    return r;
}

