#include "priority_queue.h"

int main()
{
    priority_queue_t *pq = new_priority_queue();
    priority_queue_t *pq2 = new_priority_queue();
    int curr_process = 0, quant = 1;
    process_t processes[4] = {
        {333, 1, 5, 4},
        {1571, 1, 3, 3},
        {1572, 2, 1, 2},
        {227, 5, 2, 1},
    };

    process_t *tmp;
    priority_queue_push(pq, &processes[curr_process++]);
    while(!priority_queue_empty(pq) || !priority_queue_empty(pq2)) {
        for(; !priority_queue_empty(pq); ++quant) {
            while(processes[curr_process].entry_quant == quant) {
                if(processes[curr_process].priority > priority_queue_top(pq)->priority)
                    while(!priority_queue_empty(pq2) && priority_queue_top(pq2)->priority < processes[curr_process].priority)
                        priority_queue_push(pq, priority_queue_pop(pq2));

                priority_queue_push(pq, &processes[curr_process++]);
            }

            if(--priority_queue_top(pq)->remaining_quant == 0) {
                printf("%d %d\n", priority_queue_top(pq)->code, quant);
                priority_queue_pop(pq);
            } else priority_queue_push(pq2, priority_queue_pop(pq));

        }
        for(; !priority_queue_empty(pq2); ++quant) {
            while(processes[curr_process].entry_quant == quant) {
                if(processes[curr_process].priority > priority_queue_top(pq2)->priority)
                    while(!priority_queue_empty(pq) && priority_queue_top(pq)->priority < processes[curr_process].priority)
                        priority_queue_push(pq2, priority_queue_pop(pq));

                priority_queue_push(pq2, &processes[curr_process++]);
            }

            if(--priority_queue_top(pq2)->remaining_quant == 0) {
                printf("%d %d\n", priority_queue_top(pq2)->code, quant);
                priority_queue_pop(pq2);
            } else priority_queue_push(pq, priority_queue_pop(pq2));

        }
    }

    return 0;
}
