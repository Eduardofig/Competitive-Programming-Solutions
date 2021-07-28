#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transpilar_codigo(FILE *arquivo, char codigo)
{
    switch(codigo)
    {
        case '+':
            fwrite("mem[i]++;\n", sizeof(char), 10, arquivo);
            break;
        case '-':
            fwrite("mem[i]--;\n", sizeof(char), 10, arquivo);
            break;
        case '>':
            fwrite("i++;\n", sizeof(char), 5, arquivo);
            break;
        case '<':
            fwrite("i--;\n", sizeof(char), 5, arquivo);
            break;
        case '.':
            fwrite("putchar(mem[i]);\n", sizeof(char), 17, arquivo);
            break;
        case '[':
            fwrite("while(mem[i]) {\n", sizeof(char), 16, arquivo);
            break;
        case ']':
            fwrite("}\n", sizeof(char), 2, arquivo);
            break;
    }
}

int main(int argc, char *argv[])
{
    FILE *arquivo = fopen("arquivo.c", "w");
    char c,
         comeco[1000] = "#include <stdio.h>\n\nint main() {\nchar mem[3000];\nint i = 0;\nfor(int j = 0; j < 3000; ++j) {\nmem[j] = 0;\n}\n",
         final[1000] = "printf(\"\\n\");\nfor(int j = 0; j < 3000; ++j){\nif (mem[j] != 0) {\nprintf(\"%d \", mem[j]);\n}\n}\n\nprintf(\"\\n\");\n\nreturn 0;\n}";

    fwrite(comeco, sizeof(char), strlen(comeco), arquivo);

    while(scanf("%c", &c) == 1) 
        transpilar_codigo(arquivo, c);

    fwrite(final, sizeof(char), strlen(final), arquivo);

    fclose(arquivo);

    return 0;
}
