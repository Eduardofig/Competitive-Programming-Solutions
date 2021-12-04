#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include "process.h"

typedef struct node_t
{
    int val;
    struct node_t *right, *left;
} node_t;

typedef struct binary_tree_t
{
    node_t *root;
} binary_tree_t;

binary_tree_t *new_binary_tree();
bool_t tree_empty(binary_tree_t *t);
void tree_insert(binary_tree_t *t, int val);
bool_t tree_find(binary_tree_t *t, int val);
void free_tree(binary_tree_t *t);

#endif
