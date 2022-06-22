/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

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
        //Atualiza o codigo do processo caso ele ja tenha sido usado
        while(set_find(sch->set, process->code))
            process->code++;

        set_insert(sch->set, process->code);

        sch->max_quant = max(sch->max_quant, process->entry_quant);

        //Cuida da allocacao dinamica, fazendo o realloc caso necessario
        if(sch->max_quant > sch->processes_on_quant_len) {
            sch->prev_len = sch->processes_on_quant_len;
            sch->processes_on_quant_len = sch->max_quant*2;

            sch->n_processes_on_quant = (int*)safe_realloc(sch->n_processes_on_quant, sizeof(int)*sch->processes_on_quant_len);
            sch->n_processes_on_quant_size = (int*)safe_realloc(sch->n_processes_on_quant_size, sizeof(int)*sch->processes_on_quant_len);
            sch->processes_on_quant = (process_t***)safe_realloc(sch->processes_on_quant, sizeof(process_t**)*sch->processes_on_quant_len);

            //Seta os valores novos do vetor para 0
            memset(sch->n_processes_on_quant + sch->prev_len, 0, sizeof(int)*(sch->processes_on_quant_len - sch->prev_len));
            memset(sch->n_processes_on_quant_size + sch->prev_len, 0, sizeof(int)*(sch->processes_on_quant_len - sch->prev_len));
        }

        if(sch->n_processes_on_quant_size[process->entry_quant] == 0) {
            sch->n_processes_on_quant_size[process->entry_quant]++;
            sch->processes_on_quant[process->entry_quant] = (process_t**)malloc(sizeof(process_t*));
        } else if(sch->n_processes_on_quant_size[process->entry_quant] < sch->n_processes_on_quant[process->entry_quant] + 1) {
            sch->n_processes_on_quant_size[process->entry_quant] = (sch->n_processes_on_quant[process->entry_quant] + 1)*2;

            sch->processes_on_quant[process->entry_quant] = (process_t**)safe_realloc(sch->processes_on_quant[process->entry_quant],
                    sizeof(process_t*)*sch->n_processes_on_quant_size[process->entry_quant]);
        }

        //Insercao do processo no vetor
        sch->processes_on_quant[process->entry_quant][sch->n_processes_on_quant[process->entry_quant]++] = process;
    }
}

void scheduler_execute(scheduler_t *sch)
{
    for(int quant = 0; quant <= sch->max_quant; ++quant) {
        //Caso nao tenha processos em nenhuma das duas filas porem um processo ira entrar em um quantum futuro
        if(priority_queue_empty(sch->primary_pq) && priority_queue_empty(sch->secondary_pq) && sch->n_processes_on_quant[quant] > 0) {
            sch->start = 1;
            priority_queue_push(sch->primary_pq, sch->processes_on_quant[quant][0]);
        }

        //Enquanto existem processos que nao terminaram de executar
        while(!priority_queue_empty(sch->primary_pq) || !priority_queue_empty(sch->secondary_pq)) {
            //Executa todos os processos da primeira fila, passando-os para a segunda fila
            for(; !priority_queue_empty(sch->primary_pq); ++quant) {
                if(quant <= sch->max_quant) for(int i = sch->start; i < sch->n_processes_on_quant[quant]; ++i) {
                    //Caso algum processo que va entrar no quantum atual tenha prioridade maior do que o que
                    //esta na frente da file, ele rebobina os processos ate a posicao do processo que ele entrou
                    if(sch->processes_on_quant[quant][i]->priority > priority_queue_top(sch->primary_pq)->priority)
                        while(!priority_queue_empty(sch->secondary_pq) && priority_queue_top(sch->secondary_pq)->priority < sch->processes_on_quant[quant][i]->priority)
                            priority_queue_push(sch->primary_pq, priority_queue_pop(sch->secondary_pq));

                    priority_queue_push(sch->primary_pq, sch->processes_on_quant[quant][i]);
                }

                sch->start = 0;

                //Se o processo terminou ele e reitrado e nao e inserido na outra filas
                if(--priority_queue_top(sch->primary_pq)->remaining_quant == 0) {
                    printf("%d %d\n", priority_queue_top(sch->primary_pq)->code, quant);
                    priority_queue_pop(sch->primary_pq);
                //Se nao terminou ele vai pra a outra fila
                } else priority_queue_push(sch->secondary_pq, priority_queue_pop(sch->primary_pq));
            }

            //Segunda fila de prioridade faz a mesma coisa que a primeira
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
