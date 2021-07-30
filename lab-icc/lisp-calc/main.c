#include <stdio.h>
#include <stdlib.h>

//Setar para um se quiser ver a expressao completa escrita
#define MOSTRA_EXPR 0

double eval_lisp_expr()
{
    char curr = getchar();
    if(curr == EOF) exit(0);

    //Se for espaco pula para o proximo caractere
    if(curr == ' ') return eval_lisp_expr();

    //Se for um numero, devolve o char para o buffer, le o numero
    //e o retorna
    for(char c = '0'; c != '9' + 1; ++c) {
        if(curr == c) {
            ungetc(curr, stdin);
            char flush;
            double ans;
            scanf("%lf", &ans);
            flush = getchar();
            if(MOSTRA_EXPR) printf("%f", ans);
            return ans;
        }
    }

    //Le o operador
    scanf("%c ", &curr);

    //avalia a primeira expressao recursivamente
    double num = eval_lisp_expr();

    if(MOSTRA_EXPR) printf(" %c ", curr);

    //Retorna a operacao da primeira expressao com a segunda expressao
    switch(curr) {
        case '+':
            return num + eval_lisp_expr();
        case '-':
            return num - eval_lisp_expr();
        case '*':
            return num*eval_lisp_expr();
        default:
            return num/eval_lisp_expr();
    }
}

int main(int argc, char *argv[])
{
    char flush = 0;

    while(1) {
        double res = eval_lisp_expr();
        if(MOSTRA_EXPR) printf(" = ");
        printf("%lf\n", res);

        //Flush do resto da linha do buffer
        while(flush != '\n') flush = getchar();
        flush = 0;
    }
    return 0;
}
