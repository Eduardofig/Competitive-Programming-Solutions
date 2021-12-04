#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "utils.h"

#define HEAP_ROOT 1
#define ERRO -0x3f3f3f3f

typedef struct max_heap_t
{
    process_t **data;
    int data_len;
    int size;
} max_heap_t;

max_heap_t *new_heap();
void free_heap(max_heap_t *mh);
int heap_empty(max_heap_t *mh);
void heap_push(max_heap_t *mh, process_t *val);
process_t *heap_max(max_heap_t *mh);
process_t *heap_pop(max_heap_t *mh);

#endif
