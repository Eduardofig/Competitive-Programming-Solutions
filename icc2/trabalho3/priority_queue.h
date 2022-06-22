/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "max_heap.h"

#define true 1
#define false 0

typedef unsigned int bool_t;

//Fila de prioridade que armazena processos
typedef struct priority_queue_t
{
    max_heap_t *mh;
} priority_queue_t;

//Retira o elemento que esta na frente da fila de prioridade e o retorna
process_t *priority_queue_pop(priority_queue_t *pq);
//Retorna o elemento que esta na frente da fila de prioridade
process_t *priority_queue_top(priority_queue_t *pq);
//Insere elementos na fila de prioridade
void priority_queue_push(priority_queue_t *pq, process_t *process);
//Destrutor da fila de prioridade
void free_priority_queue(priority_queue_t *pq);
//Construtor da fila de prioridade
priority_queue_t *new_priority_queue();
//Diz se a fila de prioridade esta vazia
bool_t priority_queue_empty(priority_queue_t *pq);

#endif
