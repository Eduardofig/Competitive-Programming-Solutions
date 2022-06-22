/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#include "process.h"

process_t *new_process(int code, int entry_quant, int remaining_quant, int priority)
{
    process_t *process = (process_t*)malloc(sizeof(process_t));
    process->code = code;
    process->entry_quant = entry_quant;
    process->remaining_quant = remaining_quant;
    process->priority = priority;

    return process;
}
