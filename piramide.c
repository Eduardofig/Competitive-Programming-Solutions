#include <stdio.h>

void piramide(int altura, char caractere)
{
    /*Checa para ver se a altura eh invalida*/
    if(altura > 0) {
        for (int i = 1; i <= altura; ++i) {
            /*Impressao dos espacos iniciais*/
            for (int j = 0; j < altura - i; ++j) {
                printf(" ");
            }
            /*Impressao dos caracteres*/
            if(i == 1) printf("^");
            else {
                for (int j = 0; j < 2*i - 1; ++j) {
                    if(i == altura) {
                        printf("-");
                    } else {
                        if(j == 2*i - 2) {
                            printf("\\");
                        } else if(j == 0) {
                            printf("/");
                        } else printf("%c", caractere);
                    }
                }
            }

            printf("\n");
        }
    } else {
        printf("Altura invalida\n");
    }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 50; ++i) {
        piramide(i, i);
    }
    return 0;
}
