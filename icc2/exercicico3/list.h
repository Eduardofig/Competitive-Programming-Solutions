#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool unsigned char
#define true 1
#define false 0

//Estrutura de um no
typedef struct node_t
{
    struct node_t *next;
    char* string;
} node_t;

//Estrutura da lista que ja contem o vetor de indices imbutido
typedef struct
{
    node_t *start;
    node_t *word_ptrs[26];
    int valid_ptrs;
    bool updated;
} list_t;

//Funcao que alloca um no
static node_t *__alloc_node(char* string);

//Funcao que alloca uma lista
list_t *alloc_list();

//Funcao que faz o update no vetor de indices da lista
//(so finge que faz o update porque na logica da minha lista o update eh feito a cada insercao, o que deixa o update como complexidade constante)
void mock_update_vec_list(list_t *l);

//Funcao que faz o update do vetor de indices a cada insercao
static void __update_ptrs(list_t *l, node_t *n);

//Funcao recursiva de insercao de uma chave
static void __insert_node(list_t *l, node_t *n, char* string);

//Funcao que insere uma chave na lista
void insert_list(list_t *l, char* string);

//Funcao recursiva que printa um no e para de printar no 3
static void __print_node(node_t *n, int counter);

//Funcao que printa a lista
void print_list(list_t *l);

//Funcao recursiva de busca na lista
static int __query_node(node_t *n, char *key, int n_nodes);

//Funcao de busca na lista que retorna -1 se nao achou e retorna o numero de nos visitados se achou
int query_list(list_t *l, char *key);

//Funcao que retorna o numero de ponteiros para no validos no vetor de indices
int get_n_ptrs_list(list_t *l);

//Funcao que diz se o vetor de indices ja foi atualizado
bool is_updated_list(list_t *l);

//Funcao recursiva que desaloca um no da lista
static void __free_node(node_t *n);

//Funcao que desaloca a lista
void free_list(list_t **l);
