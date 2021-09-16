#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define ERROR 0x3f3f3f3f

typedef char bool;

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

char **read_file(char *filename, char ***field_ptr, char ***visited_ptr, int *field_height, int *field_width)
{
    FILE *stream = fopen(filename, "r");
    *field_width = get_field_width(stream);

    char **field = (char**)malloc(sizeof(char*));
    bool **show = (bool**)malloc(sizeof(bool*));

    int i = 0;
    field[i] = (char*)malloc(sizeof(char)*(*field_width));
    show[i] = (bool*)malloc(sizeof(bool*)*(*field_width));

    while (fread(field[i], sizeof(char), *field_width, stream)) {
        ++i;
        field = realloc(field, sizeof(char*)*(i + 1));
        show = realloc(show, sizeof(char*)*(i + 1));
        field[i] = (char*)malloc(sizeof(char)*(*field_width));
        show[i] = (bool*)malloc(sizeof(bool)*(*field_width));

        memset(show[i], false, sizeof(bool)*(*field_width));
        fseek(stream, 1, SEEK_CUR);
    }

    *field_height = i;
    *field_ptr = field;
    *visited_ptr = show;

    return field;
}

int check_valid_position(int i, int j, int field_width, int field_height)
{
    return i < field_height && j < field_width && i >= 0 && j >= 0;
}

void field_dfs(char **field, bool **show, int i, int j, int field_height, int field_width)
{

    if(show[i][j]) return;

    int dir_i[6] = {0, 1, 0, -1, 0},
        dir_j[6] = {0, 1, 0, -1, 0};

    show[i][j] = true;

    for(int k = 0; k < 6; ++k) {
        if(check_valid_position(i + dir_i[k], j + dir_j[k], field_width, field_height) && field[i][j] == '.') {
            field_dfs(field, show, i + dir_i[k], j + dir_j[k], field_width, field_height);
        }
    }
}

void print_visible_field(char **field, bool **show, int field_height, int field_width)
{
    for(int i = 0; i < field_height; ++i) {
        for(int j = 0; j < field_width; ++j) {
            if(show[i][j]) printf("%c", field[i][j]);
            else printf("X");
        }
        printf("\n");
    }
}

void print_entire_field(char **field, int field_height, int field_width)
{
    for (int i = 0; i < field_height; ++i) {
        for (int j = 0; j < field_width; ++j) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int field_height, field_width;
    char **field, **show;
    read_file("teste.txt", &field, &show, &field_height, &field_width);
    printf("size = %d\n", field_height);
    show[3][4] = true;
    show[4][2] = true;
    print_visible_field(field, show, field_height, field_width);
    print_entire_field(field, field_height, field_width);
}
