#include "max_heap.h"

int main()
{
    max_heap_t *mh = new_heap();
    for(int i = 0; i < 20; ++i) heap_push(mh, rand() % 10000);
    for(int i = 0; i < 20; ++i) printf("%d ", heap_pop(mh));
    free_heap(mh);
    return 0;
}
