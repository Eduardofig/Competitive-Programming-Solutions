#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int num;
    struct _node *next;
}node;

typedef struct
{
    node *top;
}stack;

stack *create_stack()
{
    return (stack*)malloc(sizeof(stack));
}

void push(int num, stack *st)
{
    node *top = (node*)malloc(sizeof(node));
    top->num = num;
    top->next = st->top;
    st->top = top;
}

void pop(stack *st)
{
    node *tmp = st->top;
    st->top = tmp->next;
    free(tmp);
}

int peek(stack *st)
{
    return st->top->num;
}

int is_empty(stack *st)
{
    return st->top == NULL;
}

int main(int argc, char *argv[])
{
    stack *st = create_stack();

    for(int i = 0; i < 10; ++i) 
        push(i, st);

    for(int i = 0; i < 10; ++i) {
        printf("%d\n", peek(st));
        pop(st);
    }
    return 0;
}
