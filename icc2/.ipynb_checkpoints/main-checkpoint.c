/*
 * Nome: Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Icc 2, Trabalho 1: Campo Minado
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define ERROR -0x3f3f3f3f

typedef unsigned char bool;

//Funcao que calcula a largura do campo quando ainda esta no arquivo
int get_field_width(FILE *stream)
{

    if(!stream) return ERROR;

    int c = 0, width = -1;
    while(c != '\n') {
        fread(&c, sizeof(char), 1, stream);
        width++;
    }

    fseek(stream, SEEK_SET, 0);
    
    return width;
}

//Funcao que checa se uma determinada posicao e valida
bool check_valid_position(int i, int j, int field_height, int field_width)
{
    return (i < field_height) && (j < field_width) && (i >= 0) && (j >= 0);
}

//Funcao que cria uma matriz de dicas dado um determinado campo
int **make_hints(char **field, int field_height, int field_width)
{
    int **hints = (int**)malloc(sizeof(int*)*(field_height)),
        dir_i[8] = {1, 1, 1, 0, 0, -1, -1, -1},
        dir_j[8] = {1, -1, 0, 1, -1, 1, -1, 0};

    //Cria a matriz de dicas preenchendo-a com zeros
    for(int i = 0; i < field_height; ++i) {
        hints[i] = (int*)malloc(sizeof(int)*field_width);
        memset(hints[i], 0, sizeof(int)*(field_width));
    }

    //Percorre a matriz de dicas preenchendo-as se for um espaco vazio no tabuleiro
    for(int i = 0; i < field_height; ++i) {
        for(int j = 0; j < field_width; ++j) {
            if(field[i][j] == '*') {
                for(int k = 0; k < 8; ++k) {
                    if(check_valid_position(i + dir_i[k], j + dir_j[k], field_height, field_width)) {
                        if(field[i + dir_i[k]][j + dir_j[k]] == '.') hints[i + dir_i[k]][j + dir_j[k]]++;
                    }
                }
            }
        }
    }

    return hints;
}

//Funcao que le o arquivo e seta todos os parametros e matrizes
void read_file(char *filename, char ***field_ptr, bool ***visited_ptr,
        int ***hints_ptr, int *field_height_ptr, int *field_width_ptr)
{
    FILE *stream = fopen(filename, "r");
    *field_width_ptr = get_field_width(stream);

    char **field = (char**)malloc(sizeof(char*));
    bool **show = (bool**)malloc(sizeof(bool*));

    int i = 0;
    field[i] = (char*)malloc(sizeof(char)*(*field_width_ptr));
    show[i] = (bool*)malloc(sizeof(bool*)*(*field_width_ptr));

    while(fread(field[i], sizeof(char), *field_width_ptr, stream)) {
        ++i;
        field = realloc(field, sizeof(char*)*(i + 1));
        show = realloc(show, sizeof(char*)*(i + 1));
        field[i] = (char*)malloc(sizeof(char)*(*field_width_ptr));
        show[i] = (bool*)malloc(sizeof(bool)*(*field_width_ptr));

        memset(show[i], false, sizeof(bool)*(*field_width_ptr));
        fseek(stream, 1, SEEK_CUR);
    }

    *field_height_ptr = i;
    *field_ptr = field;
    *visited_ptr = show;
    *hints_ptr = make_hints(*field_ptr, *field_height_ptr, *field_width_ptr);
}

//Funcao que efetua uma busca em profundidade pelos espacos vazios do campo
void field_dfs(char **field, bool **show, int **hints, int i, int j, int field_height, int field_width)
{
    if(show[i][j] || field[i][j] == '*') return;

    show[i][j] = true;
    
    if(hints[i][j]) return;

    int dir_i[8] = {1, 1, 1, 0, 0, -1, -1, -1},
        dir_j[8] = {1, -1, 0, 1, -1, 1, -1, 0};

    for(int k = 0; k < 8; ++k) {
        if(check_valid_position(i + dir_i[k], j + dir_j[k], field_height, field_width)) {
            field_dfs(field, show, hints, i + dir_i[k], j + dir_j[k], field_height, field_width);
        }
    }
}

//Funcao que reseta a matriz show que determina qual parte do campo eh visivel
void reset_show(bool **show, int field_height, int field_width)
{
    for(int i = 0; i < field_height; ++i) {
        memset(show[i], 0, sizeof(bool)*field_width);
    }
}

//Funcao que printa o campo inteiro
void print_entire_field(char **field, int field_height, int field_width)
{
    for (int i = 0; i < field_height; ++i) {
        for (int j = 0; j < field_width; ++j) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

//Funcao que printa o campo com as dicas
void print_field_with_hints(char **field, int **hints, int field_height, int field_width)
{
    for(int i = 0; i < field_height; ++i) {
        for(int j = 0; j < field_width; ++j) {
            if(hints[i][j]) printf("%d", hints[i][j]);
            else printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

//Funcao que printa a parte do campo que esta visivel
void print_visible_field(char **field, bool **show, int **hints, int field_height, int field_width)
{
    for(int i = 0; i < field_height; ++i) {
        for(int j = 0; j < field_width; ++j) {
            if(show[i][j]) {
                if(hints[i][j]) printf("%d", hints[i][j]);
                else printf("%c", field[i][j]);
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

//Funcao que printa uma unica dica e um monte de X no campo
void print_single_hint(char **field, bool **show, int **hints, int pos_i, int pos_j, int field_height, int field_width)
{
    for(int i = 0; i < field_height; ++i) {
        for(int j = 0; j < field_width; ++j) {
            if(i == pos_i && j == pos_j) {
                if(hints[i][j]) printf("%d", hints[i][j]);
                else printf(".");
            } else printf("X");
        }
        printf("\n");
    }

}

//Funcao que avalia o que vai acontecer quando uma determinada posicao eh selecionada
void eval_pos_field(char **field, bool **show, int **hints, int field_height, int field_width, int pos_i, int pos_j)
{
    if(field[pos_i][pos_j] == '*') {
        print_field_with_hints(field, hints, field_height, field_width);
        return;
    } 

    if(hints[pos_i][pos_j]) {
        print_single_hint(field, show, hints, pos_i, pos_j, field_height, field_width);
        return;
    }

    field_dfs(field, show, hints, pos_i, pos_j, field_height, field_width);

    print_visible_field(field, show, hints, field_height, field_width);
    reset_show(show, field_height, field_width);

    return;
}

//Funcao que desaloca as 3 matrizes
void free_matrices(char **field, bool **show, int **hints, int field_height)
{
    for(int i = 0; i < field_height; ++i) {
        free(field[i]);
        free(show[i]);
        free(hints[i]);
    }

    free(field[field_height]);
    free(show[field_height]);

    free(field);
    free(show);
    free(hints);
}

int main(int argc, char *argv[])
{
    int field_height, field_width, selector, pos_i, pos_j, **hints;
    char **field, file_name[100];
    bool **show;

    //Da scan continuamente enquanto houver comandos no buffer de entrada
    while(scanf("%d\n", &selector) == 1) {
        switch(selector)
        {
            case 1:
                scanf("%s\n", file_name);
                read_file(file_name, &field, &show, &hints, &field_height, &field_width);

                print_entire_field(field, field_height, field_width);
                free_matrices(field, show, hints, field_height);

                break;
            case 2:
                scanf("%s\n", file_name);
                read_file(file_name, &field, &show, &hints, &field_height, &field_width);

                print_field_with_hints(field, hints, field_height, field_width);
                free_matrices(field, show, hints, field_height);

                break;
            case 3:
                scanf("%s\n%d %d", file_name, &pos_i, &pos_j);
                read_file(file_name, &field, &show, &hints, &field_height, &field_width);

                eval_pos_field(field, show, hints, field_height, field_width, pos_i, pos_j);
                free_matrices(field, show, hints, field_height);

                break;
        }
    }

    return 0;
}
