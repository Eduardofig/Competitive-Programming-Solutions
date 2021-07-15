#include <stdio.h>
#include <stdlib.h>

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

int append_nome(char *nome, char ***lista_de_nomes, int *ultima_posicao)
{
    if(nome) {
        (*lista_de_nomes)[(*ultima_posicao)++] = nome;
        char **tmp = realloc(*lista_de_nomes, sizeof(char*)*(*ultima_posicao + 1));

        if(!tmp) {
            for(int i = 0; i < *ultima_posicao - 1; ++i) {
                free(lista_de_nomes[i]);
            }
            free(lista_de_nomes);
            exit(0);
        }

        *lista_de_nomes = tmp;
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char **lista_de_nomes = (char**)malloc(sizeof(char*)), *nome;
    int ultima_posicao = 0;
    nome = read_token(" $");
    while(append_nome(nome, &lista_de_nomes, &ultima_posicao)) {
        nome = read_token(" $");
    }

    for(int i = 0; i < ultima_posicao; ++i) {
        printf("%s\n", lista_de_nomes[i]);
    }
    return 0;
}
