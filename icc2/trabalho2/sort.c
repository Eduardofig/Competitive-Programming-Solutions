#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

//Funcao que faz o merge entre duas particoes do mergesort
void merge(double *magnitude, double complex *compressed, int *origin, int st, int e)
{
    double *aux = (double*)malloc(sizeof(double)*(e - st + 1));
    double complex *z_aux = (double complex*)malloc(sizeof(double complex)*(e - st + 1));
    int *o_aux = (int*)malloc(sizeof(int)*(e - st + 1));

    int mid = (e + st) / 2, i = st, j = mid + 1, k;

    // Insere os elementos ordenadamente no vetor auxiliar
    for (k = 0; i <= mid && j <= e; k++) {
        if(magnitude[i] >= magnitude[j]) {
            o_aux[k] = origin[i];
            z_aux[k] = compressed[i];
            aux[k] = magnitude[i++];
        } else {
            o_aux[k] = origin[j];
            z_aux[k] = compressed[j];
            aux[k] = magnitude[j++];
        }
    }

    // insere os elementos que sobraram da primeira particao
    while(i <= mid) {
        o_aux[k] = origin[i];
        z_aux[k] = compressed[i];
        aux[k++] = magnitude[i++];
    }

    // insere os elementos que sobraram da segunda particao
    while(j <= e) {
        o_aux[k] = origin[j];
        z_aux[k] = compressed[j];
        aux[k++] = magnitude[j++];
    }

    // Passa os elementos do vetor auxiliar para o vetor inical
    for(i = st, k = 0; i <= e; i++, k++) {
        origin[i] = o_aux[k];
        compressed[i] = z_aux[k];
        magnitude[i] = aux[k];
    }

    free(aux);
}

//Funcao que ordena um vetor usando o metodo mergesortj
void mergesort_compressed(double *magnitude, double complex *compressed, int *origin, int st, int e)
{
    // Caso base que encerra a recursao
    if (e <= st)
        return;

    int c = (e + st)/2;

    // Chamada recursiva do inicio ate o meio e do meio ate o final
    mergesort_compressed(magnitude, compressed, origin, st, c);
    mergesort_compressed(magnitude, compressed, origin, c + 1, e);

    // Merge das duas particoes
    merge(magnitude, compressed, origin, st, e);
}

