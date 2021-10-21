/*
 * Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Exercicio 02 de icc2: Compressao de imagens
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define NO_VALUE -1

typedef unsigned char bool;

typedef struct node
{
    struct node *children[4];
    int val;
}node_t;

typedef struct quad_tree
{
    node_t *root;
}quad_tree_t;

//Funcao que aloca um no, setando o seu valor para -1 e os ponteiros dos seus filhos para NULL
node_t *alloc_node()
{
    node_t *node = (node_t*)malloc(sizeof(node_t));

    node->val = NO_VALUE;
    for(int i = 0; i < 4; ++i)
        node->children[i] = NULL;

    return node;
}

//Funcao que alloca uma arvore
quad_tree_t *alloc_tree()
{
    quad_tree_t *t = (quad_tree_t*)malloc(sizeof(quad_tree_t));
    t->root = alloc_node();

    return t;
}

//Funcao recursiva que percorre os quadrantes da imagem e vai criando os nos
void eval_node(node_t *node, int **img, int start_i, int end_i,
        int start_j, int end_j)
{
    bool equal = TRUE;
    int mid_i = start_i + (end_i - start_i)/2,
        mid_j = start_j + (end_j - start_j)/2;

    //Ve se o quadrante eh todo igual
    for(int i = start_i; i <= end_i; ++i)
        for(int j = start_j; j <= end_j; ++j)
            if(img[i][j] != img[start_i][start_j]) equal = FALSE;

    //Se o quadrante for igual, setta o valor do no e acaba a recursao
    if(equal) {
        node->val = img[start_i][start_j];
        return;
    }

    //Matriz que indica os proximos subquadrantes do quadrante atual a serem visitados
    int subquadrants[4][4] = {
        {start_i, mid_i, start_j, mid_j},
        {start_i, mid_i, mid_j + 1, end_j},
        {mid_i + 1, end_i, start_j, mid_j},
        {mid_i + 1, end_i, mid_j + 1, end_j}
    };

    //Visita todos os proximos subquadrantes do quadrante atual, alocando os nos para eles
    for(int i = 0; i < 4; ++i) {
        node->children[i] = alloc_node();

        eval_node(node->children[i], img, subquadrants[i][0],
                subquadrants[i][1], subquadrants[i][2], subquadrants[i][3]);
    }
}

//Funcao que cria a arvore
quad_tree_t *create_tree(int **img, int n, int m)
{
    quad_tree_t *t = alloc_tree();
    eval_node(t->root, img, 0, n - 1, 0, m - 1);

    return t;
}

//Funcao recursiva que printa um no e seus filhos se tiver
void print_node(node_t *node)
{
    printf("%d ", node->val);

    if(node->val == NO_VALUE)
        for(int i = 0; i < 4; ++i)
            print_node(node->children[i]);
}

//Funcao que printa a arvore inteira
void print_tree(quad_tree_t *t)
{
    if(t) print_node(t->root);
}

//Funcao que desalloca um no e seus filhos se houver
void free_node(node_t *node)
{
    if(node->val == NO_VALUE) 
        for(int i = 0; i < 4; ++i)
            free_node(node->children[i]);

    free(node);
}

//Funcao que desalloca uma arvore
void free_tree(quad_tree_t **t)
{
    if(t) {
        free_node((*t)->root);
        free(*t);
    }

    *t = NULL;
}

int main(int argc, char *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);

    int **img = (int**)malloc(sizeof(int*)*n);

    for(int i = 0; i < n; ++i) {
        img[i] = (int*)malloc(sizeof(int)*m);

        for(int j = 0; j < m; ++j)
            scanf("%d", img[i] + j);
    }

    quad_tree_t *t = create_tree(img, n, m);
    print_tree(t);
    free_tree(&t);

    for(int i = 0; i < n; ++i)
        free(img[i]);

    free(img);

    return 0;
}
