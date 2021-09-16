#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef char bool;

char **read_file(char *filename, char ***field_ptr, char ***visited_ptr, int *size)
{
    FILE *stream = fopen(filename, "r");
    char **field = (char**)malloc(sizeof(char*));
    bool **show = (bool**)malloc(sizeof(bool*));
    int i = 0;
    field[i] = (char*)malloc(sizeof(char)*10);
    show[i] = (bool*)malloc(sizeof(bool*)*10);

    while (fgets(field[i], 100, stream)) {
        ++i;
        field = realloc(field, sizeof(char*)*(i + 1));
        show = realloc(show, sizeof(char*)*(i + 1));
        field[i] = (char*)malloc(sizeof(char)*10);
        show[i] = (bool*)malloc(sizeof(bool)*10);

        memset(show[i], false, sizeof(bool)*10);
    }

    *size = i;
    *field_ptr = field;
    *visited_ptr = show;

    return field;
}

int check_valid_position(char **field, int i, int j, int size)
{
    return i < size && j < size && i >= 0 && j >= 0 && field[i][j] == '.';
}

void field_dfs(char **field, bool **show, int i, int j, int col, int size)
{

    int dir_i[6] = {0, 1, 0, -1, 0},
        dir_j[6] = {0, 1, 0, -1, 0};

    show[i][j] = true;

    for(int k = 0; k < col; ++k) {
        if(!check_valid_position(field, i, j, size)) {
            field_dfs(field, show, i + dir_i[k], j + dir_j[k], col, size);
        }
    }
}

void print_visible_field(char **field, bool **show, int size)
{
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(show[i][j]) printf("%c", field[i][j]);
            else printf("X");
        }
        printf("\n");
    }
}

void print_entire_field(char **field, int size)
{
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    char **field, **show;
    read_file("teste.txt", &field, &show, &size);
    printf("size = %d\n", size);
    show[3][4] = true;
    show[4][2] = true;
    print_visible_field(field, show, size);
    print_entire_field(field, size);
}
