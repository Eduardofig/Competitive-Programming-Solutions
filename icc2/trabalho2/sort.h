/*
   Eduardo Figueiredo Freire Andrade
   Nusp = 11232820
   Trabalho 2 de Icc 2
*/
#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define complex _Complex

//Funcao auxiliar do mergesort que faz o merge de duas particoes de um vetor
void merge(double complex *coeffs, int *origin, int st, int e);

//Funcao que ordena o vetor de coeficientes de acordo com a magnitude em ordem decrescente
void mergesort_coeffs(double complex *coeffs, int *origin, int st, int e);

#endif
