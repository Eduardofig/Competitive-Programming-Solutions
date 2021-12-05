#include "scheduler.h"

scheduler_t *new_scheduler()
{
    scheduler_t *sch = (scheduler_t*)malloc(sizeof(scheduler_t));

    sch->processes_on_quant_len = 40, sch->max_quant = 0, sch->start = 0,
    sch->set = new_set(),
    sch->n_processes_on_quant = (int*)calloc(sch->processes_on_quant_len, sizeof(int)),
    sch->n_processes_on_quant_size = (int*)calloc(sch->processes_on_quant_len, sizeof(int)),
    sch->processes_on_quant = (process_t***)malloc(sizeof(process_t**)*sch->processes_on_quant_len),
    sch->primary_pq = new_priority_queue(), sch->secondary_pq = new_priority_queue();

    return sch;
}

void scheduler_read_input(scheduler_t *sch)
{
    int code, entry_quant, remaining_quant, priority;
    process_t *process = NULL;

    while(scanf("%d %d %d %d\n", &code, &entry_quant, &remaining_quant, &priority) == 4) {
        process = new_process(code, entry_quant, remaining_quant, priority);
        while(set_find(sch->set, process->code))
            process->code++;

        set_insert(sch->set, process->code);

        sch->max_quant = max(sch->max_quant, process->entry_quant);

        if(sch->max_quant > sch->processes_on_quant_len) {
            sch->prev_len = sch->processes_on_quant_len;
            sch->processes_on_quant_len = sch->max_quant*2;

            sch->n_processes_on_quant = (int*)safe_realloc(sch->n_processes_on_quant, sizeof(int)*sch->processes_on_quant_len);
            sch->n_processes_on_quant_size = (int*)safe_realloc(sch->n_processes_on_quant_size, sizeof(int)*sch->processes_on_quant_len);
            sch->processes_on_quant = (process_t***)safe_realloc(sch->processes_on_quant, sizeof(process_t**)*sch->processes_on_quant_len);

            memset(sch->n_processes_on_quant + sch->prev_len, 0, sizeof(int)*(sch->processes_on_quant_len - sch->prev_len));
            memset(sch->n_processes_on_quant_size + sch->prev_len, 0, sizeof(int)*(sch->processes_on_quant_len - sch->prev_len));
        }

        //realocar
        if(sch->n_processes_on_quant_size[process->entry_quant] == 0) {
            sch->n_processes_on_quant_size[process->entry_quant]++;
            sch->processes_on_quant[process->entry_quant] = (process_t**)malloc(sizeof(process_t*));
        } else if(sch->n_processes_on_quant_size[process->entry_quant] < sch->n_processes_on_quant[process->entry_quant] + 1) {
            sch->n_processes_on_quant_size[process->entry_quant] = (sch->n_processes_on_quant[process->entry_quant] + 1)*2;

            sch->processes_on_quant[process->entry_quant] = (process_t**)safe_realloc(sch->processes_on_quant[process->entry_quant],
                    sizeof(process_t*)*sch->n_processes_on_quant_size[process->entry_quant]);
        }

        sch->processes_on_quant[process->entry_quant][sch->n_processes_on_quant[process->entry_quant]++] = process;
    }
}

void scheduler_execute(scheduler_t *sch)
{
    for(int quant = 0; quant <= sch->max_quant; ++quant) {
        if(priority_queue_empty(sch->primary_pq) && priority_queue_empty(sch->secondary_pq) && sch->n_processes_on_quant[quant] > 0) {
            sch->start = 1;
            priority_queue_push(sch->primary_pq, sch->processes_on_quant[quant][0]);
        }

        while(!priority_queue_empty(sch->primary_pq) || !priority_queue_empty(sch->secondary_pq)) {
            for(; !priority_queue_empty(sch->primary_pq); ++quant) {
                if(quant <= sch->max_quant) for(int i = sch->start; i < sch->n_processes_on_quant[quant]; ++i) {
                    if(sch->processes_on_quant[quant][i]->priority > priority_queue_top(sch->primary_pq)->priority)
                        while(!priority_queue_empty(sch->secondary_pq) && priority_queue_top(sch->secondary_pq)->priority < sch->processes_on_quant[quant][i]->priority)
                            priority_queue_push(sch->primary_pq, priority_queue_pop(sch->secondary_pq));

                    priority_queue_push(sch->primary_pq, sch->processes_on_quant[quant][i]);
                }

                sch->start = 0;

                if(--priority_queue_top(sch->primary_pq)->remaining_quant == 0) {
                    printf("%d %d\n", priority_queue_top(sch->primary_pq)->code, quant);
                    priority_queue_pop(sch->primary_pq);
                } else priority_queue_push(sch->secondary_pq, priority_queue_pop(sch->primary_pq));
            }

            for(; !priority_queue_empty(sch->secondary_pq); ++quant) {
                if(quant <= sch->max_quant) for(int i = 0; i < sch->n_processes_on_quant[quant]; ++i) {
                    if(sch->processes_on_quant[quant][i]->priority > priority_queue_top(sch->secondary_pq)->priority)
                        while(!priority_queue_empty(sch->primary_pq) && priority_queue_top(sch->primary_pq)->priority < sch->processes_on_quant[quant][i]->priority)
                            priority_queue_push(sch->secondary_pq, priority_queue_pop(sch->primary_pq));

                    priority_queue_push(sch->secondary_pq, sch->processes_on_quant[quant][i]);
                }

                if(--priority_queue_top(sch->secondary_pq)->remaining_quant == 0) {
                    printf("%d %d\n", priority_queue_top(sch->secondary_pq)->code, quant);
                    priority_queue_pop(sch->secondary_pq);
                } else priority_queue_push(sch->primary_pq, priority_queue_pop(sch->secondary_pq));
            }
        }

    }
}

void free_scheduler(scheduler_t *sch)
{
    for(int i = 0; i < sch->processes_on_quant_len; ++i) 
        if(sch->n_processes_on_quant_size[i] > 0) {
            for(int j = 0; j < sch->n_processes_on_quant[i]; ++j) free(sch->processes_on_quant[i][j]);
            free(sch->processes_on_quant[i]);
        }

    free_set(sch->set);
    free_priority_queue(sch->primary_pq);
    free_priority_queue(sch->secondary_pq);
    free(sch->n_processes_on_quant);
    free(sch->n_processes_on_quant_size);
    free(sch->processes_on_quant);

    free(sch);
}
