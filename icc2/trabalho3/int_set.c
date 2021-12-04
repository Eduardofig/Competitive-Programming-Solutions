#include "int_set.h"

int_set_t *new_set()
{
    int_set_t *s = (int_set_t*)malloc(sizeof(int_set_t));
    s->tree = new_binary_tree();

    return s;
}

void set_insert(int_set_t *s, int val)
{
    tree_insert(s->tree, val);
}

bool_t set_find(int_set_t *s, int val)
{
    return tree_find(s->tree, val);
}

void free_set(int_set_t *s)
{
    free_tree(s->tree);
    free(s);
}
