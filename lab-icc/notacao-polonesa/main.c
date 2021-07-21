#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    double num;
    struct _node *next;
}node;

typedef struct
{
    node *top;
    int tamanho;
}stack;

//Funcoes da pilha
stack *criar_stack()
{
    stack *st = (stack*)malloc(sizeof(stack));
    st->tamanho = 0;
    return st;
}

double esta_vazia(stack *st)
{
    return st->top == NULL;
}

void push(double num, stack *st)
{
    node *top = (node*)malloc(sizeof(node));
    top->num = num;
    top->next = st->top;
    st->top = top;
    st->tamanho++;
}

void pop(stack *st)
{
    if(esta_vazia(st)) return;
    node *tmp = st->top;
    st->top = tmp->next;
    free(tmp);
    st->tamanho--;
}

double peek(stack *st)
{
    return st->top->num;
}


int tamanho(stack *st)
{
    return st->tamanho;
}

void deletar_stack(stack **st)
{
    if(!*st) return;
    node *tmp = (*st)->top, *tmp_2;
    while(tmp) {
        tmp_2 = tmp->next;
        free(tmp);
        tmp = tmp_2;
    }
    free(*st);
    *st = NULL;
}

int main(int argc, char *argv[])
{
    stack *st = criar_stack();
    char s[100];
    double a, b;

    //Operacoes da notacao polonesa
    while(scanf("%s", s) == 1) {
        switch(s[0]) {
            case '+':
                b = peek(st);
                pop(st);
                a = peek(st);
                pop(st);
                push(a + b, st);
                printf("%lf + %lf =  %lf\n", a, b, peek(st));
                break;
            case '-':
                b = peek(st);
                pop(st);
                a = peek(st);
                pop(st);
                push(a - b, st);
                printf("%lf - %lf =  %lf\n", a, b, peek(st));
                break;
            case '*':
                b = peek(st);
                pop(st);
                a = peek(st);
                pop(st);
                push(a*b, st);
                printf("%lf * %lf =  %lf\n", a, b, peek(st));
                break;
            case '/':
                b = peek(st);
                pop(st);
                a = peek(st);
                pop(st);
                push(a/b, st);
                printf("%lf / %lf =  %lf\n", a, b, peek(st));
                break;
            default:
                push(atof(s), st);
                break;
        }
    }

    printf("Resultado: %lf\n", peek(st));
    deletar_stack(&st);

    return 0;
}
