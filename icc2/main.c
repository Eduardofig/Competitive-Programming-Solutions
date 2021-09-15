#include <stdio.h>
#include <stdlib.h>

char **read_file(char *filename, int *size)
{
    FILE *stream = fopen(filename, "r");
    char **field = (char **)malloc(sizeof(char *));
    int i = 0;
    field[i] = (char *)malloc(sizeof(char) * 10);
    while (fgets(field[i], 100, stream)) {
        ++i;
        field = realloc(field, sizeof(char *) * (i + 1));
        field[i] = (char *)malloc(sizeof(char) * 10);
    }

    *size = i;

    return field;
}

int check_valid_position(char **field, int i, int j, int size)
{
    return i < size && j < size && i >= 0 && j >= 0 && field[i][j] == '.';
}

void field_dfs(int i, int j, int col, char **field, int size)
{

    int dir_i[6] = {0, 1, 0, -1, 0},
        dir_j[6] = {0, 1, 0, -1, 0};

    field[i][j] = '*';

    for(int k = 0; k < col; ++k) {
        if(!check_valid_position(field, i, j, size)) {
            field_dfs(i + dir_i[k], j + dir_j[k], col, field, size);
        }
    }
}

void print_field(char **field, int size)
{
    for(int i = 0; i < size; ++i) {
        printf("%s", field[i]);
    }
}

int main()
{
    int size;
    char **field = read_file("teste.txt", &size);
    printf("size = %d\n", size);
    print_field(field, size);

}
