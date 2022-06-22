/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include "process.h"

//No da arvore binaria de busca
typedef struct node_t
{
    int val;
    struct node_t *right, *left;
} node_t;

//Arvore binaria de busca
typedef struct binary_tree_t
{
    node_t *root;
} binary_tree_t;

//Construtor da arvore binaria
binary_tree_t *new_binary_tree();
//Diz se a arvore esta vazia
bool_t tree_empty(binary_tree_t *t);
//Insere elementos na arvore
void tree_insert(binary_tree_t *t, int val);
//Busca elementos na arvore
bool_t tree_find(binary_tree_t *t, int val);
//Destrutor da arvore binaria
void free_tree(binary_tree_t *t);

#endif
