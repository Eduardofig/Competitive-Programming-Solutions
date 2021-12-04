#include "priority_queue.h"

process_t *priority_queue_pop(priority_queue_t *pq)
{
    return heap_pop(pq->mh);
}

process_t *priority_queue_top(priority_queue_t *pq)
{
    return heap_max(pq->mh);
}

void priority_queue_push(priority_queue_t *pq, process_t *process)
{
    heap_push(pq->mh, process);
}

void free_priority_queue(priority_queue_t *pq)
{
    free_heap(pq->mh);
    free(pq);
}

priority_queue_t *new_priority_queue()
{
    priority_queue_t *pq = (priority_queue_t*)malloc(sizeof(priority_queue_t));
    pq->mh = new_heap();

    return pq;
}

bool_t priority_queue_empty(priority_queue_t *pq)
{
    return heap_empty(pq->mh);
}
