#include "list.h"

//Funcao que alloca um no
static node_t *__alloc_node(char* string)
{
    node_t *n = (node_t*)malloc(sizeof(node_t));
    n->next = NULL;
    n->string = string;

    return n;
}

//Funcao que alloca uma lista
list_t *alloc_list()
{
    list_t *l = (list_t*)malloc(sizeof(list_t));
    l->start = NULL;
    l->valid_ptrs = 0;
    l->updated = false;
    for(int i = 0; i < 26; ++i)
        l->word_ptrs[i] = NULL;

    return l;
}

//Funcao que faz o update no vetor de indices da lista
//(so finge que faz o update porque na logica da minha lista o update eh feito a cada insercao, o que deixa o update como complexidade constante)
void mock_update_vec_list(list_t *l)
{
    l->updated = true;
}

//Funcao que faz o update do vetor de indices a cada insercao
static void __update_ptrs(list_t *l, node_t *n)
{
    if(!l->word_ptrs[n->string[0] - 'a']) l->valid_ptrs++;
    l->word_ptrs[n->string[0] - 'a'] = n;
}

//Funcao recursiva de insercao de uma chave
static void __insert_node(list_t *l, node_t *n, char* string)
{
    //Chegou no final da lista
    if(!n->next) {
        n->next = __alloc_node(string);

        __update_ptrs(l, n->next);
        return;
    }

    //Achou a posicao de insercao
    if(n->next->string[0] >= string[0]) {
        node_t *tmp = n->next;

        n->next = __alloc_node(string);
        n->next->next = tmp;

        __update_ptrs(l, n->next);
        return;
    }

    //Chamada recursiva
    __insert_node(l, n->next, string);
}

//Funcao que insere uma chave na lista
void insert_list(list_t *l, char* string)
{
    l->updated = false;

    //Criacao primeiro no
    if(!l->start) {
        l->start = __alloc_node(string);

        __update_ptrs(l, l->start);
        return;
    }

    //Insercao antes do primeiro no
    if(l->start->string[0] >= string[0]) {
        node_t *tmp = l->start;

        l->start = __alloc_node(string);
        l->start->next = tmp;

        __update_ptrs(l, l->start);
        return;
    }

    //Chamada recursiva
    __insert_node(l, l->start, string);
}

//Funcao recursiva que printa um no e para de printar no 3
static void __print_node(node_t *n, int counter)
{
    if(n && counter <= 3) {
        printf("%s\n", n->string);
        __print_node(n->next, counter + 1);
    }
}

//Funcao que printa a lista
void print_list(list_t *l)
{
    if(!l) return;
    if(l->start) __print_node(l->start, 1);
}

//Funcao recursiva de busca na lista
static int __query_node(node_t *n, char *key, int n_nodes)
{
    if(n && n->string[0] == key[0]) {
        //Se achou o no
        if(!strcmp(key, n->string)) return n_nodes;
        //Chamada recursiva
        return __query_node(n->next, key, n_nodes + 1);
    }

    //Se passou da chave ou chegou no final da lista
    return -1;
}

//Funcao de busca na lista que retorna -1 se nao achou e retorna o n de nos visitados se achou
int query_list(list_t *l, char *key)
{
    if(l->word_ptrs[key[0] - 'a']) return __query_node(l->word_ptrs[key[0] - 'a'], key, 0);

    return -1;
}

//Funcao que retorna o numero de ponteiros para no validos no vetor de indices
int get_n_ptrs_list(list_t *l)
{
    return l->valid_ptrs;
}

//Funcao que diz se o vetor de indices ja foi atualizado
bool is_updated_list(list_t *l)
{
    return l->updated;
}

//Funcao recursiva que desaloca um no da lista
static void __free_node(node_t *n)
{
    if(n) {
        free(n->string);
        __free_node(n->next);

        free(n);
    }
}

//Funcao que desaloca a lista
void free_list(list_t **l)
{
    __free_node((*l)->start);
    free(*l);

    *l = NULL;
}
