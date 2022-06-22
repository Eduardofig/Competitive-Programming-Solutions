/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#ifndef SCHEDULER_H
#define SCHEULER_H

#include <string.h>
#include "priority_queue.h"
#include "int_set.h"
#include "utils.h"

//Escalonador de processos
typedef struct scheduler_t
{
    int max_quant, //Quantum maximo de entrada de todos os processos do input
        processes_on_quant_len, //Tamano do vetor processes_on_quant, para reallocar caso preciso
        *n_processes_on_quant, //Numero de processos que vao entrar em um determinado quantum
        *n_processes_on_quant_size, //Tamanho do vetor de processos em um determinado quantum, para reallocar
        prev_len, //Valor utilizado na funcao execute
        start; //Valor utilizado na funcao execute

    int_set_t *set; //Set para guardar quais codigos de processo ja foram usados
    process_t ***processes_on_quant; //Vetor que indica os processo que vao entrar em um determinado quantum

    //Filas de prioridade que sao usadas na funcao execute
    priority_queue_t *primary_pq, *secondary_pq;
} scheduler_t;

//Construtor do escalonador
scheduler_t *new_scheduler();
//Le os inputs dos casos teste 
void scheduler_read_input(scheduler_t *sch);
//Faz a simulacao do escalonador de processos
void scheduler_execute(scheduler_t *sch);
//Destrutor do escalonador de processos
void free_scheduler(scheduler_t *sch);

#endif
