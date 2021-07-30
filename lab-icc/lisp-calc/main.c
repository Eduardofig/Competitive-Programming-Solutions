#include <stdio.h>
#include <stdlib.h>

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
            char discard;
            double ans;
            scanf("%lf", &ans);
            discard = getchar();
            printf("%f", ans);
            return ans;
        }
    }

    //Le o operador
    scanf("%c ", &curr);

    //avalia a primeira expressao recursivamente
    double num = eval_lisp_expr();

    printf(" %c ", curr);

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
    char discard = 0;
    while(1) {
        double res = eval_lisp_expr();
        printf(" = %lf\n", res);

        //Flush do resto da linha do buffer
        while(discard != '\n') discard = getchar();
        discard = 0;
    }
    return 0;
}
