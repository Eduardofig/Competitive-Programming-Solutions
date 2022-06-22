/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

//Funcao que retorna o maximo entre 2 elementos
int max(const int a, const int b);
//Funcao que faz o realloc checando se ele deu certo e encerrando o programa
//se deu errado
void *safe_realloc(void *ptr, size_t mem_size);

#endif
