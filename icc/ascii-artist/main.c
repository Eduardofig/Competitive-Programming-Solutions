#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enquadra_arte(char *nome_do_arquivo_da_arte, int altura_do_quadro, int largura_do_quadro)
{
    FILE *f_arte_ptr = fopen(nome_do_arquivo_da_arte, "r");
    if (f_arte_ptr == NULL) {
        printf(
                "Erro na abertura do arquivo, "
                "Você esqueceu de fechar o arquivo antes? "
                "Ou deu free na string com o nome sem querer?\n"
              );

        exit(EXIT_FAILURE);
    }

    int qtd_espc_comeco;
    const char *apoio;
    if (largura_do_quadro % 2 == 0) {
        qtd_espc_comeco = largura_do_quadro / 2;
        apoio           = "/\\";
    } else {
        qtd_espc_comeco = largura_do_quadro / 2 + 1;
        apoio           = "Ʌ";
    }

    for (int i = 0; i < qtd_espc_comeco; i++) printf(" ");
    printf("%s\n", apoio);

    printf("╭");
    for (int i = 0; i < largura_do_quadro; i++) printf("—");
    printf("╮\n");

    for (int i = 0; i < altura_do_quadro; i++) {
        printf("|");
        for (int j = 0; j < largura_do_quadro; j++) {
            char pixel_atual = fgetc(f_arte_ptr);
            printf("%c", pixel_atual);
        }
        printf("|");

        char quebra = fgetc(f_arte_ptr);
        if (quebra != EOF) printf("%c", quebra);
    };
    fclose(f_arte_ptr);

    printf("\n╰");
    for (int i = 0; i < largura_do_quadro; i++) printf("—");
    printf("╯\n");
}

//Funcao que le uma string determinada por array de possiveis delimitadores
char *read_token(FILE *arquivo, char *delimitadores)
{
    size_t tamanho_da_linha = sizeof(char);
    char c, *linha = malloc(tamanho_da_linha), *failsafe;
    for(int i = 0; fread(&c, sizeof(char), 1, arquivo); i++) {
        //Quando chega no final da linha retorna a linha e adiciona o '\0' no final
        for(int j = 0; delimitadores[j] != 0; ++j) {
            if(c == delimitadores[j]) {
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

//Funcao que le a arte do arquivo
char **read_arte(FILE *arquivo, int *n_linhas)
{
    char **arte = (char**)malloc(sizeof(char*)), **failsafe;
    char *linha;
    *n_linhas = 0;

    linha = read_token(arquivo, "\n\r");

    while(linha) {
        arte[*n_linhas] = linha;
        linha = read_token(arquivo, "\n\r");

        //Se o realloc der errado
        failsafe = realloc(arte, sizeof(char*)*(++(*n_linhas) + 1));
        if(!failsafe) {
            for(int i = 0; i < *n_linhas; ++i)
                free(arte[i]);
            free(arte);
            exit(0);
        }

        arte = failsafe;
    }

    return arte;
}

void preencher_arte(char **arte, char alvo, char preenchimento, int posicao_i, int posicao_j, int n_linhas)
{
    //Casos base
    if(posicao_i < 0 || posicao_i >= n_linhas) return;
    if(arte[posicao_i][posicao_j] != alvo) return;

    arte[posicao_i][posicao_j] = preenchimento;

    int direcoes_i[4] = {1, -1, 0, 0};
    int direcoes_j[4] = {0, -0, -1, 1};

    //Chamada recursiva
    for(int i = 0; i < 4; ++i)
        preencher_arte(arte, alvo, preenchimento, posicao_i + direcoes_i[i], posicao_j + direcoes_j[i], n_linhas);
}

void print_arte(char **arte, int n_linhas)
{
    for(int i = 0; i < n_linhas; ++i)
        printf("%s\n", arte[i]);
}

void formatar(char ***arte, int largura, int *n_linhas)
{
    char **failsafe = (char**)realloc(*arte, sizeof(char*)*(*n_linhas + 1));
    char *formatacao = (char*)malloc(sizeof(char)*(largura + 1));

    ++(*n_linhas);

    for(int i = 0; i < largura; ++i) formatacao[i] = ' ';
    formatacao[largura] = 0;

    if(!failsafe) {
        for(int i = 0; i < *n_linhas - 1; ++i)
            free((*arte)[i]);
        free(*arte);
        exit(0);
    }

    *arte = failsafe;
    (*arte)[(*n_linhas - 1)] = formatacao; 
}

int main(int argc, char *argv[])
{
    int n_linhas, n_operacoes, posicao_i, posicao_j, largura_quadro = 0;

    char nome_arquivo[1000];
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    char **arte = read_arte(arquivo, &n_linhas), preenchimento;
    fclose(arquivo);

    scanf("%d\n", &n_operacoes);

    largura_quadro = strlen(arte[0]);

    formatar(&arte, largura_quadro, &n_linhas);

    printf("Arte inicial:\n");
    print_arte(arte, n_linhas);

    for(int i = 0; i < n_operacoes; ++i) {

        scanf("%c %d %d\n", &preenchimento, &posicao_i, &posicao_j);
        preencher_arte(arte, arte[posicao_i][posicao_j], preenchimento, posicao_i, posicao_j, n_linhas);
        printf("\nArte apos a etapa %d:\n", i);
        print_arte(arte, n_linhas);
    }

    arquivo = fopen(nome_arquivo, "w");

    for(int i = 0; i < n_linhas; ++i) {
        fwrite(arte[i], sizeof(char), strlen(arte[i]), arquivo);
        if(i != n_linhas - 1) fwrite("\n", sizeof(char), 1, arquivo);
        free(arte[i]);
    }
    free(arte);

    fclose(arquivo);

    printf("\nArte enquadrada:\n");
    enquadra_arte(nome_arquivo, n_linhas, largura_quadro);

    return 0;
}
