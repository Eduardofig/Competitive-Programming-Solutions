/*
   Eduardo Figueiredo Freire Andrade
   Nusp = 11232820
   Trabalho 2 de Icc 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

void merge(double complex *coeffs, int *origin, int st, int e)
{
    double complex *z_aux = (double complex*)malloc(sizeof(double complex)*(e - st + 1));
    int *o_aux = (int*)malloc(sizeof(int)*(e - st + 1)),
        mid = (e + st) / 2, i = st, j = mid + 1, k;

    //Insere os elementos ordenadamente no vetor auxiliar
    for(k = 0; i <= mid && j <= e; k++) {
        if (cabs(coeffs[i]) >= cabs(coeffs[j])) {
            o_aux[k] = origin[i];
            z_aux[k] = coeffs[i++];
        } else {
            o_aux[k] = origin[j];
            z_aux[k] = coeffs[j++];
        }
    }

    //Insere os elementos que sobraram da primeira particao
    while (i <= mid) {
        o_aux[k] = origin[i];
        z_aux[k++] = coeffs[i++];
    }

    //Insere os elementos que sobraram da segunda particao
    while (j <= e) {
        o_aux[k] = origin[j];
        z_aux[k++] = coeffs[j++];
    }

    //Passa os elementos do vetor auxiliar para o vetor inical
    for (i = st, k = 0; i <= e; i++, k++) {
        origin[i] = o_aux[k];
        coeffs[i] = z_aux[k];
    }

    //Desalloca os vetores auxiliares
    free(z_aux);
    free(o_aux);
}

void mergesort_coeffs(double complex *coeffs, int *origin, int st, int e)
{
    // Caso base que encerra a recursao
    if (e <= st)
        return;

    int c = (e + st) / 2;

    // Chamada recursiva do inicio ate o meio e do meio ate o final
    mergesort_coeffs(coeffs, origin, st, c);
    mergesort_coeffs(coeffs, origin, c + 1, e);

    // Merge das duas particoes
    merge(coeffs, origin, st, e);
}
