#ifndef INT_SET_H
#define INT_SET_H

#include "binary_tree.h"

typedef struct int_set_t
{
    binary_tree_t *tree;
} int_set_t;

int_set_t *new_set();
void set_insert(int_set_t *s, int val);
bool_t set_find(int_set_t *s, int val);
void free_set(int_set_t *s);

#endif
