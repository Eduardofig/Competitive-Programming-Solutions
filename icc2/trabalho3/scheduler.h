#ifndef SCHEDULER_H
#define SCHEULER_H

#include <string.h>
#include "priority_queue.h"
#include "int_set.h"
#include "utils.h"

typedef struct scheduler_t
{
    int max_quant, processes_on_quant_len,
        *n_processes_on_quant, *n_processes_on_quant_size,
        prev_len, start;

    int_set_t *set;
    process_t ***processes_on_quant;

    priority_queue_t *primary_pq, *secondary_pq;
} scheduler_t;

scheduler_t *new_scheduler();
void scheduler_read_input(scheduler_t *sch);
void scheduler_execute(scheduler_t *sch);
void free_scheduler(scheduler_t *sch);

#endif
