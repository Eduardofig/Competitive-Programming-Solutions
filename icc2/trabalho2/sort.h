#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define complex _Complex

void merge(double *magnitude, double complex *compressed, int *origin, int st, int e);
void mergesort_compressed(double *magnitude, double complex *compressed, int *origin, int st, int e);

#endif
