#include "binary_tree.h"

static node_t *_new_node(int val)
{
    node_t *n = (node_t *)malloc(sizeof(node_t));
    n->left = NULL;
    n->right = NULL;
    n->val = val;

    return n;
}

binary_tree_t *new_binary_tree()
{
    binary_tree_t *t = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    t->root = NULL;

    return t;
}

bool_t tree_empty(binary_tree_t *t)
{
    return t->root == NULL;
}

static void _tree_insert_node(node_t *curr, int val)
{
    if(val > curr->val) {
        if(curr->right) {
            _tree_insert_node(curr->right, val);
            return;
        }

        curr->right = _new_node(val);
    }

    if(val < curr->val) {
        if(curr->left) {
            _tree_insert_node(curr->left, val);
            return;
        }

        curr->left = _new_node(val);
    }
}

void tree_insert(binary_tree_t *t, int val)
{
    if(!t->root) {
        t->root = _new_node(val);
        return;
    }

    _tree_insert_node(t->root, val);
}

static bool_t _tree_find_node(node_t *curr, int val)
{
    if(val > curr->val && curr->right) return _tree_find_node(curr->right, val);
    if(val < curr->val && curr->left) return _tree_find_node(curr->left, val);

    return curr->val == val;
}

bool_t tree_find(binary_tree_t *t, int val)
{
    if(tree_empty(t)) return false;
    if(t->root->val == val) return true;

    return _tree_find_node(t->root, val);
}

static void _free_node(node_t *curr)
{
    if(curr) {
        _free_node(curr->left);
        _free_node(curr->right);
        free(curr);
    }
}

void free_tree(binary_tree_t *t)
{
    if(t->root) _free_node(t->root);
    free(t);
}
