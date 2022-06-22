/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#include "binary_tree.h"

//Construtor de um no
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

//Funcao recursive de insercao em elementos em um no
static void _tree_insert_node(node_t *curr, int val)
{
    if(val > curr->val) {
        if(curr->right) {
            //Chamada recursiva para o no da direita
            _tree_insert_node(curr->right, val);
            return;
        }

        //Insere no no da direita
        curr->right = _new_node(val);
    }

    if(val < curr->val) {
        if(curr->left) {
            //Chamada recursiva para o no da esquerda
            _tree_insert_node(curr->left, val);
            return;
        }

        //Insere no no da esquerda
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

//Funcao recursiva de busca em um no
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
