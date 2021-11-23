#include "max_heap.h"

max_heap_t *new_heap()
{
    max_heap_t *mh = (max_heap_t*)malloc(sizeof(max_heap_t));

    mh->data = (int*)malloc(sizeof(int));
    mh->size = 0;
    mh->data_len = 1;

    return mh;
}

void free_heap(max_heap_t *mh)
{
    free(mh->data);
    free(mh);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int heap_empty(max_heap_t *mh)
{
    return mh->size == 0;
}

int heap_cmp(const int a, const int b)
{
    return a > b;
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

void heap_push(max_heap_t *mh, int val)
{
    if(mh->data_len <= mh->size + 1) {
        mh->data_len = (mh->size + 1)*2;
        int *tmp = (int*)realloc(mh->data, sizeof(int)*(mh->data_len));

        if(!tmp) {
            printf("ERRO: Faltou espaco na memoria");
            free_heap(mh);
            exit(1);
        }

        mh->data = tmp;
    }

    mh->data[++mh->size] = val;
    shift_up(mh, mh->size);
}

int heap_max(max_heap_t *mh)
{
    if(heap_empty(mh)) return ERRO;

    return mh->data[1];
}

int heap_pop(max_heap_t *mh)
{
    if(heap_empty(mh)) return ERRO;

    int max = mh->data[HEAP_ROOT];

    swap(mh->data + HEAP_ROOT, mh->data + mh->size);
    mh->size--;

    shift_down(mh, HEAP_ROOT);
    
    return max;
}
