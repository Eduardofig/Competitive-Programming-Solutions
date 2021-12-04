#include "max_heap.h"

#define true 1
#define false 0

typedef unsigned int bool_t;

typedef struct priority_queue_t
{
    max_heap_t *mh;
} priority_queue_t;

process_t *priority_queue_pop(priority_queue_t *pq);
process_t *priority_queue_top(priority_queue_t *pq);
void priority_queue_push(priority_queue_t *pq, process_t *process);
void free_priority_queue(priority_queue_t *pq);
priority_queue_t *new_priority_queue();
bool_t priority_queue_empty(priority_queue_t *pq);
