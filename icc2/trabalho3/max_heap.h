#include <stdio.h>
#include <stdlib.h>

#define HEAP_ROOT 1
#define ERRO -0x3f3f3f3f

typedef struct max_heap_t
{
    int *data;
    int data_len;
    int size;
} max_heap_t;

max_heap_t *new_heap();
void free_heap(max_heap_t *mh);
void swap(int *a, int *b);
int heap_empty(max_heap_t *mh);
int heap_cmp(const int a, const int b);
int heap_parent(const int i);
int heap_child(int which, int i);
int heap_contains(max_heap_t *mh, const int curr);
int heap_next_child(max_heap_t *mh, const int curr);
void shift_up(max_heap_t *mh, const int curr);
void shift_down(max_heap_t *mh, const int curr);
void heap_push(max_heap_t *mh, int val);
int heap_max(max_heap_t *mh);
int heap_pop(max_heap_t *mh);
