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
