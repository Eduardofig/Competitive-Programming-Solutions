/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#include "scheduler.h"

int main(int argc, char *argv[])
{
    scheduler_t *sch = new_scheduler();

    scheduler_read_input(sch);
    scheduler_execute(sch);

    free_scheduler(sch);

    return 0;
}
