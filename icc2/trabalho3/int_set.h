/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#ifndef INT_SET_H
#define INT_SET_H

#include "binary_tree.h"

//Set que armazena inteiros
typedef struct int_set_t
{
    binary_tree_t *tree;
} int_set_t;

//Construtor do set
int_set_t *new_set();
//Insere inteiros no set
void set_insert(int_set_t *s, int val);
//Diz se o set possui um elemento
bool_t set_find(int_set_t *s, int val);
//Destrutor do set
void free_set(int_set_t *s);

#endif
