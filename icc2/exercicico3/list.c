#include "list.h"

node_t *alloc_node(char* string)
{
    node_t *n = (node_t*)malloc(sizeof(node_t));
    n->next = NULL;
    n->string = string;

    return n;
}

list_t *alloc_list()
{
    list_t *l = (list_t*)malloc(sizeof(list_t));
    l->start = NULL;
    l->valid_ptrs = 0;
    for(int i = 0; i < 26; ++i)
        l->word_ptrs[i] = NULL;

    return l;
}

void update_ptrs(list_t *l, node_t *n)
{
    if(!l->word_ptrs[n->string[0] - 'a']) {
        l->word_ptrs[n->string[0] - 'a'] = n;
        l->valid_ptrs++;
    }
}

void insert_node(list_t *l, node_t *n, char* string)
{
    if(!n->next) {
        n->next = alloc_node(string);

        update_ptrs(l, n->next);
        return;
    }

    if(n->next->string[0] > string[0]) {
        node_t *tmp = n->next;

        n->next = alloc_node(string);
        n->next->next = tmp;

        update_ptrs(l, n->next);
        return;
    }

    insert_node(l, n->next, string);
}

void insert_list(list_t *l, char* string)
{
    if(!l->start) {
        l->start = alloc_node(string);

        update_ptrs(l, l->start);
        return;
    }

    if(l->start->string[0] > string[0]) {
        node_t *tmp = l->start;

        l->start = alloc_node(string);
        l->start->next = tmp;

        update_ptrs(l, l->start);
        return;
    }
    
    insert_node(l, l->start, string);
}

void print_node(node_t *n)
{
    if(n) {
        printf("%s\n", n->string);
        print_node(n->next);
    }
}

void print_list(list_t *l)
{
    if(!l) return;
    if(l->start) print_node(l->start);
}

bool query_node(node_t *n, char *key)
{
    if(n && n->string[0] == key[0]) {
        if(!strcmp(key, n->string)) return true;
        return query_node(n->next, key);
    }

    return false;
}

bool query_list(list_t *l, char *key)
{
    if(l->word_ptrs[key[0] - 'a'])
        return query_node(l->word_ptrs[key[0] - 'a'], key);

    return false;
}

int get_n_ptrs_list(list_t *l)
{
    return l->valid_ptrs;
}

void free_node(node_t *n)
{
    if(n) {
        node_t *tmp = n->next;

        /*free(n->string);*/
        free(n);

        free_node(n->next);
    }
}

void free_list(list_t **l)
{
    free_node((*l)->start);
    free(*l);

    *l = NULL;
}
