#include "max_heap.h"

max_heap_t *new_heap()
{
    max_heap_t *mh = (max_heap_t*)malloc(sizeof(max_heap_t));

    mh->data = (process_t**)malloc(sizeof(process_t*));
    mh->data[0] = NULL;

    mh->size = 0;
    mh->data_len = 1;

    return mh;
}

void free_heap(max_heap_t *mh)
{
    for(int i = 0; i < mh->data_len; ++i) 
        if(mh->data[i]) free(mh->data[i]);

    free(mh->data);
    free(mh);
}

void swap(process_t **a, process_t **b)
{
    process_t *tmp = *a;
    *a = *b;
    *b = tmp;
}

int heap_empty(max_heap_t *mh)
{
    return mh->size == 0;
}

int heap_cmp(const process_t *a, const process_t *b)
{
    return a->priority > b->priority;
}

int heap_parent(const int i)
{
    return i >> 1;
}

int heap_child(int which, int i)
{
    return (i << 1) + which;
}

int heap_contains(max_heap_t *mh, const int curr)
{
    return curr <= mh->size;
}

int heap_next_child(max_heap_t *mh, const int curr)
{
    int next = curr, tmp;

    for(int i = 0; i < 2; ++i) {
        tmp = heap_child(i, curr);
        if(heap_contains(mh, tmp) && heap_cmp(mh->data[tmp], mh->data[next]))
            next = tmp;
    }

    return next;
}

void shift_up(max_heap_t *mh, const int curr)
{
    if(heap_contains(mh, curr) && curr != HEAP_ROOT) {
        int par = heap_parent(curr);

        if(heap_cmp(mh->data[curr], mh->data[par]))
            swap(mh->data + curr, mh->data + par);

        shift_up(mh, par);
    }
}

void shift_down(max_heap_t *mh, const int curr)
{
    int next = heap_next_child(mh, curr);

    if(next != curr) {
        swap(mh->data + next, mh->data + curr);
        shift_down(mh, next);
    }
}

void heap_push(max_heap_t *mh, process_t *val)
{
    if(mh->data_len <= mh->size + 1) {
        mh->data_len = (mh->size + 1)*2;
        process_t **tmp = (process_t**)realloc(mh->data, sizeof(process_t*)*(mh->data_len));

        if(!tmp) {
            printf("ERRO: Faltou espaco na memoria");
            free_heap(mh);
            exit(1);
        }

        mh->data = tmp;

        for(int i = mh->size + 1; i < mh->data_len; ++i)
            mh->data[i] = NULL;
    }

    mh->data[++mh->size] = val;
    shift_up(mh, mh->size);
}

process_t *heap_max(max_heap_t *mh)
{
    if(heap_empty(mh)) return NULL;

    return mh->data[1];
}

process_t *heap_pop(max_heap_t *mh)
{
    if(heap_empty(mh)) return NULL;

    process_t *max = mh->data[HEAP_ROOT];

    swap(mh->data + HEAP_ROOT, mh->data + mh->size--);

    shift_down(mh, HEAP_ROOT);
    
    return max;
}
