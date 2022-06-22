/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "utils.h"

#define HEAP_ROOT 1
#define ERRO -0x3f3f3f3f

typedef struct max_heap_t
{
    process_t **data;
    int data_len;
    int size;
} max_heap_t;

//Construtor da heap
max_heap_t *new_heap();
//Destrutor da heap
void free_heap(max_heap_t *mh);
//Funcao que diz se uma heap esta vazia
int heap_empty(max_heap_t *mh);
//Insere elementos na heap
void heap_push(max_heap_t *mh, process_t *val);
//Retorna o elemento que esta no topo da heap
process_t *heap_max(max_heap_t *mh);
//Retira o elemento que esta no topo da heap e o retorna
process_t *heap_pop(max_heap_t *mh);

#endif
