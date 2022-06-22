/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef unsigned int bool_t;

//Processo
typedef struct process_t
{
    int code;
    int entry_quant;
    int remaining_quant;
    int priority;
} process_t;

//Construtor do processo
process_t *new_process(int code, int entry_quant, int remaining_quant, int priority);

#endif
