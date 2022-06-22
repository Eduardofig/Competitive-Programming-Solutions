/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#include "utils.h"
#include <stdlib.h>

int max(const int a, const int b)
{
    if(a > b) return a;
    return b;
}

void *safe_realloc(void *ptr, size_t mem_size)
{
    void *tmp = realloc(ptr, mem_size);

    if(!tmp) {
        free(ptr);
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }

    return tmp;
}

