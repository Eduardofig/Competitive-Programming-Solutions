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

node_t *_new_node(int val);
binary_tree_t *new_binary_tree();
bool_t tree_empty(binary_tree_t *t);
void _tree_insert_node(node_t *curr, int val);
void tree_insert(binary_tree_t *t, int val);
bool_t _tree_find_node(node_t *curr, int val);
bool_t tree_find(binary_tree_t *t, int val);
