#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool unsigned char
#define true 1
#define false 0

typedef struct node_t
{
    struct node_t *next;
    char* string;
} node_t;

typedef struct
{
    node_t *start;
    node_t *word_ptrs[26];
    int valid_ptrs;
    bool updated;
} list_t;

node_t *alloc_node(char* string);
list_t *alloc_list();
void mock_update_vec_list(list_t *l);
void update_ptrs(list_t *l, node_t *n);
void insert_node(list_t *l, node_t *n, char* string);
void insert_list(list_t *l, char* string);
void print_node(node_t *n);
void print_list(list_t *l);
int query_node(node_t *n, char *key, int n_nodes);
int query_list(list_t *l, char *key);
int get_n_ptrs_list(list_t *l);
bool is_updated_list(list_t *l);
void free_node(node_t *n);
void free_list(list_t **l);
