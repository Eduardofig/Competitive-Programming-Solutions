#include <stdio.h>

int main(int argc, char *argv[])
{
    int dia;
    scanf("%d", &dia);
    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    for (int i = 0; i < 17; ++i) {
        printf(" ");
    }
    for (int i = 0; i <= 47; ++i) {
        if(i > 16) printf("%c%c%d%c%c ", i < 27? ' ': '\0', i == dia? '(': 0, i - 17, i == dia + 17? ')': 0, i % 7? ' ': '\n');
    }
    printf(" ");
}
