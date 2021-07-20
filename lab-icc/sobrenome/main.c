#include <stdio.h>
#include <stdlib.h>

int $ = 0, eol = 0;
const int mxN = 1e4;

typedef char* string;

string read_token(string delimitadores)
{
    size_t tamanho_da_linha = sizeof(char);
    char c, *linha = malloc(tamanho_da_linha), *failsafe;
    for(int i = 0; scanf("%c", &c) == 1; i++) {
        //Quando chega no final da linha retorna a linha e adiciona o '\0' no final
        for(int j = 0; delimitadores[j] != 0; ++j) {
            if(c == delimitadores[j]) {
                if(c == '$') $ = 1;
                if(c == '\n') eol = 1;
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

//Funcao que da append em um nome completo
int append_nome(string nome, string **nome_completo, int *ultima_posicao)
{
    if(nome) {
        (*nome_completo)[(*ultima_posicao)++] = nome;
        string *tmp = (string*)realloc(*nome_completo, sizeof(string)*(*ultima_posicao + 1));

        if(!tmp) {
            for(int i = 0; i < *ultima_posicao - 1; ++i) {
                free(nome_completo[i]);
            }
            free(nome_completo);
            exit(0);
        }

        *nome_completo = tmp;
        /*printf("nome: %s\n", (*nome_completo)[*ultima_posicao - 1]);*/
        /*if(*ultima_posicao > 1) printf("nome - 1: %s\n", (*nome_completo)[*ultima_posicao - 2]); */
        if($) return 0;
        return 1;
    }
    return 0;
}

int main(int argc, string argv[])
{
    string **lista_de_nomes = (string**)malloc(sizeof(string*)), nome;
    int n_sobrenomes[mxN], n_nomes_completos, i, j, k;

    for(n_nomes_completos = 0; !$ && n_nomes_completos < 4; ++n_nomes_completos) {
        lista_de_nomes[n_nomes_completos] = (string*)malloc(sizeof(string));
        do {
            if(eol) {
                eol ^= 1;
                break;
            }
            nome = read_token(" $\n");

            /*if(n_nomes_completos > 0)*/
                /*printf("%s  i = %d\n", lista_de_nomes[0][0], n_nomes_completos);*/

        } while(append_nome(nome, lista_de_nomes + n_nomes_completos, n_sobrenomes + n_nomes_completos));
    }

    for(k = 0; k < n_nomes_completos - 1; ++k) {
        if(!(k % 2)) {
            if(n_sobrenomes[k] > 0)
                append_nome(lista_de_nomes[k][n_sobrenomes[k] - 1], lista_de_nomes + k + 1, n_sobrenomes + k + 1);
        }
    }

    for(i = 0; i < n_nomes_completos; ++i) {
        for(j = 0; j < n_sobrenomes[i]; ++j) {
            printf("%s ", lista_de_nomes[i][j]);
        }
        printf("\n");
    }

    for(; !$; ++n_nomes_completos) {
        lista_de_nomes[n_nomes_completos] = (string*)malloc(sizeof(string));
        do {
            if(eol) {
                eol ^= 1;
                break;
            }
            nome = read_token(" $\n");

            /*if(n_nomes_completos > 0)*/
                /*printf("%s  i = %d\n", lista_de_nomes[0][0], n_nomes_completos);*/

        } while(append_nome(nome, lista_de_nomes + n_nomes_completos, n_sobrenomes + n_nomes_completos));
    }

    for(; k < n_nomes_completos - 1; ++k) {
        if(!(k % 2)) {
            if(n_sobrenomes[k] > 0)
                append_nome(lista_de_nomes[k][n_sobrenomes[k] - 1], lista_de_nomes + k + 1, n_sobrenomes + k + 1);
        }
    }

    for(; i < n_nomes_completos; ++i) {
        for(j = 0; j < n_sobrenomes[i]; ++j) {
            printf("%s ", lista_de_nomes[i][j]);
        }
        printf("\n");
    }
    free(lista_de_nomes);

    return 0;
}
