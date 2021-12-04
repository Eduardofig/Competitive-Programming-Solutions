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

static void _swap(process_t **a, process_t **b)
{
    process_t *tmp = *a;
    *a = *b;
    *b = tmp;
}

int heap_empty(max_heap_t *mh)
{
    return mh->size == 0;
}

static int _heap_cmp(const process_t *a, const process_t *b)
{
    return a->priority > b->priority;
}

static int _heap_parent(const int i)
{
    return i >> 1;
}

static int _heap_child(int which, int i)
{
    return (i << 1) + which;
}

static int _heap_contains(max_heap_t *mh, const int curr)
{
    return curr <= mh->size;
}

static int _heap_next_child(max_heap_t *mh, const int curr)
{
    int next = curr, tmp;

    for(int i = 0; i < 2; ++i) {
        tmp = _heap_child(i, curr);
        if(_heap_contains(mh, tmp) && _heap_cmp(mh->data[tmp], mh->data[next]))
            next = tmp;
    }

    return next;
}

static void _shift_up(max_heap_t *mh, const int curr)
{
    if(_heap_contains(mh, curr) && curr != HEAP_ROOT) {
        int par = _heap_parent(curr);

        if(_heap_cmp(mh->data[curr], mh->data[par]))
            _swap(mh->data + curr, mh->data + par);

        _shift_up(mh, par);
    }
}

static void _shift_down(max_heap_t *mh, const int curr)
{
    int next = _heap_next_child(mh, curr);

    if(next != curr) {
        _swap(mh->data + next, mh->data + curr);
        _shift_down(mh, next);
    }
}

void heap_push(max_heap_t *mh, process_t *val)
{
    if(mh->data_len <= mh->size + 1) {
        mh->data_len = (mh->size + 1)*2;
        process_t **tmp = (process_t**)safe_realloc(mh->data, sizeof(process_t*)*(mh->data_len));

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
    _shift_up(mh, mh->size);
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

    _swap(mh->data + HEAP_ROOT, mh->data + mh->size--);

    _shift_down(mh, HEAP_ROOT);
    
    return max;
}
