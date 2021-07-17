#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int bool;
#define TRUE 1;
#define FALSE 0;
#define SHIFT_MAIUSCULO 'a' - 'A'

//Funcao que le uma string determinada por array de possiveis delimitadores
char *read_token(char *delimitadores)
{
    size_t tamanho_da_linha = sizeof(char);
    char c, *linha = malloc(tamanho_da_linha), *failsafe;
    for(int i = 0; scanf("%c", &c) == 1; i++) {
        //Quando chega no final da linha retorna a linha e adiciona o '\0' no final
        for(int j = 0; delimitadores[j] != 0; ++j) {
            if(c == delimitadores[j]) {
                if(c == '\r') scanf("%c", &c);
                linha[i] = 0;
                return linha;
            }
        }
        linha[i] = c;
        tamanho_da_linha += sizeof(char);
        failsafe = realloc(linha, tamanho_da_linha);
        //Se o realloc der errado
        if(!failsafe) {
            free(linha);
            return NULL;
        }
        linha = failsafe;
    }
    free(linha);
    return NULL;
}

bool checar_palindromo_direto(char *palavra, int i, int j)
{
    //casos base
    if(i >= j) return TRUE;
    if(palavra[i] != palavra[j] && abs(palavra[i] - palavra[j]) != SHIFT_MAIUSCULO) return FALSE;

    //recursao
    return checar_palindromo_direto(palavra, i + 1, j - 1);
}

//Funcao que checa palindromo
bool checar_palindromo_indireto(char *palavra, int i, int j)
{
    //caso base
    if(i >= j) return TRUE;

    //recursao
    if(!isalnum(palavra[i])) return checar_palindromo_indireto(palavra, i + 1, j);
    if(!isalnum(palavra[j])) return checar_palindromo_indireto(palavra, i, j - 1);

    //outro caso base
    if(palavra[i] != palavra[j] && abs(palavra[i] - palavra[j]) != SHIFT_MAIUSCULO) return FALSE;

    return checar_palindromo_indireto(palavra, i + 1, j - 1);
}

int main(int argc, char *argv[])
{
    char *palavra = read_token("\n");

    if(checar_palindromo_direto(palavra, 0, strlen(palavra) - 1)) {
        printf("Palindromo direto\n");

        free(palavra);
        exit(0);
    }

    if(checar_palindromo_indireto(palavra, 0, strlen(palavra) - 1)) {
        printf("Palindromo indireto\n");

        free(palavra);
        exit(0);
    }

    printf("Nao eh um palindromo\n");

    free(palavra);
    return 0;
}
